//325763498
//michalshasha8@gmail.com

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
    DFS,
    HEAP
};

template<typename T, size_t K>
class TreeIterator {
public:
    TreeIterator(std::shared_ptr<Node<T>> root, TreeIteratorType type);

    TreeIterator& operator++();
    bool operator!=(const TreeIterator& other) const;
    std::shared_ptr<Node<T>> operator*();
    Node<T>* operator->();
    void flatten_to_vector(std::shared_ptr<Node<T>> node, std::vector<std::shared_ptr<Node<T>>>& nodes);


private:
    void traverse_pre_order(std::shared_ptr<Node<T>> node);

    void traverse_post_order(std::shared_ptr<Node<T>> node);

    void traverse_in_order(std::shared_ptr<Node<T>> node);

    void traverse_bfs(std::shared_ptr<Node<T>> node);

    void traverse_dfs(std::shared_ptr<Node<T>> node);

    void traverse_heap(std::shared_ptr<Node<T>> node);

    

    std::queue<std::shared_ptr<Node<T>>> queue;
    std::shared_ptr<Node<T>> current;
    TreeIteratorType type;
};

#include "TreeIterator.tpp"

#endif // TREEITERATOR_HPP
