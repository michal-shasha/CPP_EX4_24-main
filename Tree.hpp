#ifndef TREE_HPP
#define TREE_HPP

#include <memory>
#include <iostream>
#include <functional> 
#include "Node.hpp"
#include "TreeIterator.hpp"

template<typename T, size_t K = 2>
class Tree {
private:
    std::shared_ptr<Node<T>> root;

public:
    void add_root(const Node<T>& node);
    void add_sub_node(const Node<T>& parent, const Node<T>& child);
    std::shared_ptr<Node<T>> find_node(std::shared_ptr<Node<T>> start, const T& value);

    std::shared_ptr<Node<T>> get_root() const;

    // Friend function declaration using the same template parameters
    template<typename U, size_t M>
    friend std::ostream& operator<<(std::ostream& os, const Tree<U, M>& tree);

    // Iterators for different traversals
    TreeIterator<T> begin_pre_order();
    TreeIterator<T> end_pre_order();
    TreeIterator<T> begin_post_order();
    TreeIterator<T> end_post_order();
    TreeIterator<T> begin_in_order();
    TreeIterator<T> end_in_order();
    TreeIterator<T> begin_bfs_scan();
    TreeIterator<T> end_bfs_scan();
    TreeIterator<T> begin_dfs_scan();
    TreeIterator<T> end_dfs_scan();

    // Iterators for range-based for loop (using BFS as an example)
    TreeIterator<T> begin();
    TreeIterator<T> end();
    

};

#include "Tree.tpp"

#endif // TREE_HPP
