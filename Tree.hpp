//325763498
//michalshasha8@gmail.com

#ifndef TREE_HPP
#define TREE_HPP

#include <memory>
#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
#include <SFML/Graphics.hpp>
#include "Node.hpp"
#include "TreeIterator.hpp"

template<typename T, size_t K = 2>
class Tree {
private:
    std::shared_ptr<Node<T>> root;
    std::vector<std::shared_ptr<Node<T>>> heap_nodes; // Adjusted to store shared_ptr to Node<T>
    int tree_order;
    void heapify(std::shared_ptr<Node<T>> node);
    //void flatten_to_vector(std::shared_ptr<Node<T>> node, std::vector<std::shared_ptr<Node<T>>>& nodes);

public:
    Tree() : root(nullptr), tree_order(K) {}

    void add_root(const Node<T>& node);
    void add_sub_node(const Node<T>& parent, const Node<T>& child);
    int get_tree_order() const;
    std::shared_ptr<Node<T>> find_node(std::shared_ptr<Node<T>> start, const T& value) const;
    std::shared_ptr<Node<T>> get_root() const;
    size_t count_children(const Node<T>& node) const;

    template<typename U, size_t M>
    friend std::ostream& operator<<(std::ostream& os, const Tree<U, M>& tree);

    // Iterators
    TreeIterator<T,K> begin_pre_order();
    TreeIterator<T,K> end_pre_order();
    TreeIterator<T,K> begin_post_order();
    TreeIterator<T,K> end_post_order();
    TreeIterator<T,K> begin_in_order();
    TreeIterator<T,K> end_in_order();
    TreeIterator<T,K> begin_bfs_scan();
    TreeIterator<T,K> end_bfs_scan();
    TreeIterator<T,K> begin_dfs_scan();
    TreeIterator<T,K> end_dfs_scan();
    TreeIterator<T,K> begin_heap();
    TreeIterator<T,K> end_heap();

    TreeIterator<T,K> begin();
    TreeIterator<T,K> end();

    // GUI functions
    void draw_tree(sf::RenderWindow& window, std::shared_ptr<Node<T>> node, int x, int y, int horizontal_gap, sf::Font& font);
    void handle_window();

    // Heap operations
    void convert_to_min_heap();
};

#include "Tree.tpp"

#endif // TREE_HPP
