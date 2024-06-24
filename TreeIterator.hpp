#ifndef TREEITERATOR_HPP
#define TREEITERATOR_HPP

#include <memory>
#include <stack>
#include <queue>
#include "Node.hpp"

enum class TreeIteratorType {
    PRE_ORDER,
    POST_ORDER,
    IN_ORDER,
    BFS,
    DFS
};

template<typename T>
class TreeIterator {
public:
    TreeIterator(std::shared_ptr<Node<T>> root, TreeIteratorType type);

    bool operator!=(const TreeIterator<T>& other) const;

    TreeIterator<T>& operator++();

    std::shared_ptr<Node<T>> operator*();

    void heapify(std::shared_ptr<Node<T>> node);

    void convert_to_min_heap();

private:
    void traverse_pre_order(std::shared_ptr<Node<T>> node);

    void traverse_post_order(std::shared_ptr<Node<T>> node);

    void traverse_in_order(std::shared_ptr<Node<T>> node);

    void traverse_bfs(std::shared_ptr<Node<T>> node);

    void traverse_dfs(std::shared_ptr<Node<T>> node);

    

    std::queue<std::shared_ptr<Node<T>>> queue;
    std::shared_ptr<Node<T>> current;
    TreeIteratorType type;
};

#include "TreeIterator.tpp"

#endif // TREEITERATOR_HPP
