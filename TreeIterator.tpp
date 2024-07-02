//325763498
//michalshasha8@gmail.com

#ifndef TREEITERATOR_TPP
#define TREEITERATOR_TPP

#include "TreeIterator.hpp"

template<typename T, size_t K>
TreeIterator<T, K>::TreeIterator(std::shared_ptr<Node<T>> root, TreeIteratorType type) : type(type) {
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
            case TreeIteratorType::HEAP:
                traverse_heap(root);
                break;  
        }
    }
    current = queue.empty() ? nullptr : queue.front();
}

template<typename T, size_t K>
TreeIterator<T, K>& TreeIterator<T, K>::operator++() {
    if (!queue.empty()) {
        queue.pop();
        current = queue.empty() ? nullptr : queue.front();
    }
    return *this;
}

template<typename T, size_t K>
bool TreeIterator<T, K>::operator!=(const TreeIterator<T, K>& other) const {
    return current != other.current;
}

template<typename T, size_t K>
Node<T>* TreeIterator<T, K>::operator->() {
    return current.get();
}

template<typename T, size_t K>
std::shared_ptr<Node<T>> TreeIterator<T, K>::operator*() {
    return current;
}

template <typename T, size_t K>
void TreeIterator<T, K>::flatten_to_vector(std::shared_ptr<Node<T>> node, std::vector<std::shared_ptr<Node<T>>>& nodes) {
    if (!node) return;

    nodes.push_back(node); // Push shared_ptr to node

    for (const auto& child : node->get_children()) {
        flatten_to_vector(child, nodes);
    }
}

template<typename T, size_t K>
void TreeIterator<T, K>::traverse_heap(std::shared_ptr<Node<T>> node) {

    std::vector<std::shared_ptr<Node<T>>> nodes;

    // Step 1: Flatten the tree starting from the given node into a vector
    flatten_to_vector(node, nodes); // Assuming you have a function to flatten into 'nodes'

    // Step 2: Convert the flattened vector into a min-heap
    std::make_heap(nodes.begin(), nodes.end(), [](const std::shared_ptr<Node<T>>& a, const std::shared_ptr<Node<T>>& b) {
        return a->get_value() < b->get_value(); // Min-heap: smallest value at the top
    });
    std::sort_heap(nodes.begin(), nodes.end(), [](const std::shared_ptr<Node<T>>& a, const std::shared_ptr<Node<T>>& b) {
        return a->get_value() < b->get_value(); // Sort in ascending order
    });
    // Step 3: Traverse the heap (if needed)
    for (const auto& n : nodes) {
        queue.push(n); // Assuming queue is a member variable of TreeIterator to store heap nodes
    }

    // Step 4: Initialize current pointer (assuming queue is not empty)
    current = queue.empty() ? nullptr : queue.front();
}

template<typename T, size_t K>
void TreeIterator<T, K>::traverse_pre_order(std::shared_ptr<Node<T>> node) {
    if (!node) return;
    // If K is greater than 2, use dfs
    if (K > 2) {
        traverse_dfs(node);
        return;
    }
    queue.push(node);
    for (auto child : node->get_children()) {
        traverse_pre_order(child);
    }
}

template<typename T, size_t K>
void TreeIterator<T, K>::traverse_post_order(std::shared_ptr<Node<T>> node) {
    if (node) {
        // If K is greater than 2, use dfs
        if (K > 2) {
          traverse_dfs(node);
          return;
        }
        for (auto child : node->get_children()) {
            traverse_post_order(child);
        }
        queue.push(node);
    }
}

template<typename T, size_t K>
void TreeIterator<T, K>::traverse_in_order(std::shared_ptr<Node<T>> node) {
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

template<typename T, size_t K>
void TreeIterator<T, K>::traverse_bfs(std::shared_ptr<Node<T>> node) {
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

template<typename T, size_t K>
void TreeIterator<T, K>::traverse_dfs(std::shared_ptr<Node<T>> node) {
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

#endif // TREEITERATOR_TPP
