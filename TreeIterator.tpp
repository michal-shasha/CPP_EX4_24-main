#ifndef TREEITERATOR_TPP
#define TREEITERATOR_TPP

#include "TreeIterator.hpp"

template<typename T>
TreeIterator<T>::TreeIterator(std::shared_ptr<Node<T>> root, TreeIteratorType type) : type(type) {
    if (root) {
        switch (type) {
            case TreeIteratorType::PRE_ORDER:
                traverse_pre_order(root);
                break;
            case TreeIteratorType::POST_ORDER:
                traverse_post_order(root);
                break;
            case TreeIteratorType::IN_ORDER:
                traverse_in_order(root);
                break;
            case TreeIteratorType::BFS:
                traverse_bfs(root);
                break;
            case TreeIteratorType::DFS:
                traverse_dfs(root);
                break;    
        }
    }
    current = queue.empty() ? nullptr : queue.front();
}

template<typename T>
TreeIterator<T>& TreeIterator<T>::operator++() {
    if (!queue.empty()) {
        queue.pop();
        current = queue.empty() ? nullptr : queue.front();
    }
    return *this;
}

template<typename T>
bool TreeIterator<T>::operator!=(const TreeIterator<T>& other) const {
    return current != other.current;
}


template<typename T>
std::shared_ptr<Node<T>> TreeIterator<T>::operator*() {
    return current;
}


template<typename T>
void TreeIterator<T>::traverse_pre_order(std::shared_ptr<Node<T>> node) {
    if (!node) return;

    queue.push(node);
    for (auto child : node->get_children()) {
        traverse_pre_order(child);
    }
}

template<typename T>
void TreeIterator<T>::traverse_post_order(std::shared_ptr<Node<T>> node) {
    if (node) {
        for (auto child : node->get_children()) {
            traverse_post_order(child);
        }
        queue.push(node);
    }
}

template<typename T>
void TreeIterator<T>::traverse_in_order(std::shared_ptr<Node<T>> node) {
    if (node) {
        auto children = node->get_children();
        if (!children.empty()) {
            traverse_in_order(children[0]);
        }
        queue.push(node);
        for (size_t i = 1; i < children.size(); ++i) {
            traverse_in_order(children[i]);
        }
    }
}


// template<typename T>
// void TreeIterator<T>::traverse_bfs(std::shared_ptr<Node<T>> node) {
//     if (node) {
//         queue.push(node);
//         while (!queue.empty()) {
//             auto current = queue.front();
//             queue.pop();
//             auto children = current->get_children();
//             for (auto child : children) {
//                 queue.push(child);
//             }
//             stack.push(current); // Push to stack for use in BFS traversal if needed
//         }
//     }
// }

// template<typename T>
// void TreeIterator<T>::traverse_dfs(std::shared_ptr<Node<T>> node) {
//     if (node) {
//         stack.push(node);
//         auto children = node->get_children();
//         for (auto it = children.rbegin(); it != children.rend(); ++it) {
//             traverse_dfs(*it);
//         }
//     }
// }


template<typename T>
void TreeIterator<T>::traverse_bfs(std::shared_ptr<Node<T>> node) {
    if (!node) return;
    std::queue<std::shared_ptr<Node<T>>> bfs_queue;
    bfs_queue.push(node);

    while (!bfs_queue.empty()) {
        auto current = bfs_queue.front();
        bfs_queue.pop();
        queue.push(current);

        for (auto& child : current->get_children()) {
            bfs_queue.push(child);
        }
    }
}

template<typename T>
void TreeIterator<T>::traverse_dfs(std::shared_ptr<Node<T>> node) {
    if (!node) return;
    std::deque<std::shared_ptr<Node<T>>> deque;
    deque.push_front(node);

    while (!deque.empty()) {
        auto current = deque.front();
        deque.pop_front();
        queue.push(current);

        auto children = current->get_children();
        for (auto it = children.rbegin(); it != children.rend(); ++it) {
            deque.push_front(*it);
        }
    }
}



template<typename T>
void TreeIterator<T>::heapify(std::shared_ptr<Node<T>> node) {
    if (!node) return;

    auto smallest = node;
    auto left = node->get_left_child();
    auto right = node->get_right_child();

    // Compare with left child
    if (left && left->get_value() < smallest->get_value()) {
        smallest = left;
    }

    // Compare with right child
    if (right && right->get_value() < smallest->get_value()) {
        smallest = right;
    }

    // If the smallest is not the current node, swap values and recursively heapify
    if (smallest != node) {
        std::swap(node->value, smallest->value);
        heapify(smallest); // Recursively heapify the affected subtree
    }
}

template<typename T>
void TreeIterator<T>::convert_to_min_heap() {
    if (!current) return;

    std::queue<std::shared_ptr<Node<T>>> q;
    q.push(current);

    while (!q.empty()) {
        auto node = q.front();
        q.pop();

        // Apply heapify to the current node
        heapify(node);

        // Enqueue children for further processing
        auto left = node->get_left_child();
        auto right = node->get_right_child();
        if (left) q.push(left);
        if (right) q.push(right);
    }
}


#endif // TREEITERATOR_TPP
