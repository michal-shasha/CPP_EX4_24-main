#ifndef TREE_TPP
#define TREE_TPP
#include "Tree.hpp"

template <typename T, size_t K>
void Tree<T, K>::add_root(const Node<T>& node) {
    root = std::make_shared<Node<T>>(node.get_value()); // Create a new node with the value of 'node'
}

template <typename T, size_t K>
void Tree<T, K>::add_sub_node(const Node<T>& parent, const Node<T>& child) {
    auto parent_ptr = find_node(root, parent.get_value());
    if (parent_ptr) {
        auto child_ptr = std::make_shared<Node<T>>(child.get_value()); // Create a new node
        parent_ptr->add_child(child_ptr);
    } else {
        throw std::runtime_error("Parent node not found in the tree.");
    }
}

template <typename T, size_t K>
std::shared_ptr<Node<T>> Tree<T, K>::find_node(std::shared_ptr<Node<T>> start, const T& value) {
    // Implement tree traversal to find the node with the specified value
    if (!start) return nullptr;
    
    if (start->get_value() == value) {
        return start;
    } else {
        for (auto child : start->get_children()) {
            auto result = find_node(child, value);
            if (result) return result;
        }
    }
    
    return nullptr;
}

template<typename T, size_t K>
TreeIterator<T> Tree<T, K>::begin() {
    return begin_bfs_scan();
}

template<typename T, size_t K>
TreeIterator<T> Tree<T, K>::end() {
    return end_bfs_scan();
}

template<typename T, size_t K>
TreeIterator<T> Tree<T, K>::begin_pre_order() {
    return TreeIterator<T>(root, TreeIteratorType::PRE_ORDER);
}


template<typename T, size_t K>
TreeIterator<T> Tree<T, K>::end_pre_order() {
    return TreeIterator<T>(nullptr, TreeIteratorType::PRE_ORDER);
}

template<typename T, size_t K>
TreeIterator<T> Tree<T, K>::begin_post_order() {
    return TreeIterator<T>(root, TreeIteratorType::POST_ORDER);
}

template<typename T, size_t K>
TreeIterator<T> Tree<T, K>::end_post_order() {
    return TreeIterator<T>(nullptr, TreeIteratorType::POST_ORDER);
}

template<typename T, size_t K>
TreeIterator<T> Tree<T, K>::begin_in_order() {
    return TreeIterator<T>(root, TreeIteratorType::IN_ORDER);
}

template<typename T, size_t K>
TreeIterator<T> Tree<T, K>::end_in_order() {
    return TreeIterator<T>(nullptr, TreeIteratorType::IN_ORDER);
}

template<typename T, size_t K>
TreeIterator<T> Tree<T, K>::begin_bfs_scan() {
    return TreeIterator<T>(root, TreeIteratorType::BFS);
}

template<typename T, size_t K>
TreeIterator<T> Tree<T, K>::end_bfs_scan() {
    return TreeIterator<T>(nullptr, TreeIteratorType::BFS);
}

template<typename T, size_t K>
TreeIterator<T> Tree<T, K>::begin_dfs_scan() {
    return TreeIterator<T>(root, TreeIteratorType::DFS);
}

template<typename T, size_t K>
TreeIterator<T> Tree<T, K>::end_dfs_scan() {
    return TreeIterator<T>(nullptr, TreeIteratorType::DFS);
}

template <typename T, size_t K>
std::ostream& operator<<(std::ostream& os, const Tree<T, K>& tree) {
    // Implement a traversal to print the tree
    std::function<void(const std::shared_ptr<Node<T>>&)> print_tree = [&](const std::shared_ptr<Node<T>>& node) {
        if (node) {
            os << node->get_value() << " -> ";
            for (const auto& child : node->get_children()) { // Assuming get_children returns a vector of child nodes
                print_tree(child);
            }
        }
    };

    print_tree(tree.root);
    return os;
}

#endif // TREE_TPP
