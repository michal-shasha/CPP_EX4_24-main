# Assignment4- Trees and Iterators**  
**Email: michalshasha8@gmail.com**

## Overview

This project provides an implementation of a hierarchical data structure using templates in C++. The primary components are the `Node` and `Tree` classes, designed to handle generic data types and support various traversal methods. The project also includes a visualization feature using the SFML library.

## Libraries Used

<memory>: Used for managing dynamic memory through smart pointers.
<vector>: Used for managing child nodes in a vector container.
<iostream>: Used for input/output operations, specifically in the friend function for output stream.
<sstream>: Used for string stream operations, specifically in converting node values to strings for display.
<stdexcept>: Used for throwing exceptions, specifically in the division operator overload to handle division by zero.
<functional>: Used for defining the traversal function in the operator<< overload for printing the tree.
<SFML/Graphics.hpp>: Used for graphical operations, specifically for drawing trees.
<algorithm>: Used for algorithms such as std::make_heap and std::sort_heap in converting the tree into a min-heap.
<queue>: Used for implementing BFS and heap traversal algorithms.
<deque>: Used for implementing DFS traversal.



Hierarchy of Classes
Node<T>
The Node class represents a node in the tree. It is templated to handle different data types.

Methods:

Constructor: Node(T val)

Initializes the node with a value.
Getters and Setters:

T get_value() const
void set_value(T new_value)
Child Management:

void add_child(const std::shared_ptr<Node<T>>& child)
const std::vector<std::shared_ptr<Node<T>>>& get_children() const
std::shared_ptr<Node<T>> get_left_child() const
std::shared_ptr<Node<T>> get_right_child() const
void clear_children()
size_t count_children() const


Tree<T, K>
The Tree class represents the tree structure. It is templated to handle different data types and allows specifying the maximum number of children (K) per node.

Methods:

Root Management:

void add_root(const Node<T>& node)
std::shared_ptr<Node<T>> get_root() const
Node Management:

void add_sub_node(const Node<T>& parent, const Node<T>& child)
std::shared_ptr<Node<T>> find_node(std::shared_ptr<Node<T>> start, const T& value) const
size_t count_children(const Node<T>& node) const
Tree Traversal:

TreeIterator<T> begin()
TreeIterator<T> end()
TreeIterator<T> begin_pre_order()
TreeIterator<T> end_pre_order()
TreeIterator<T> begin_post_order()
TreeIterator<T> end_post_order()
TreeIterator<T> begin_in_order()
TreeIterator<T> end_in_order()
TreeIterator<T> begin_bfs_scan()
TreeIterator<T> end_bfs_scan()
TreeIterator<T> begin_dfs_scan()
TreeIterator<T> end_dfs_scan()
TreeIterator<T> begin_heap()
TreeIterator<T> end_heap()
Heap Operations:

void heapify(std::shared_ptr<Node<T>> node)
void convert_to_min_heap()
Tree Visualization:

void draw_tree(sf::RenderWindow& window, std::shared_ptr<Node<T>> node, int x, int y, int horizontal_gap, sf::Font& font)
void handle_window()

TreeIterator<T>
The TreeIterator class provides various traversal methods for the tree.

Methods:

Constructor: TreeIterator(std::shared_ptr<Node<T>> root, TreeIteratorType type)

Initializes the iterator with a root node and traversal type.
Operators:

TreeIterator<T>& operator++()
bool operator!=(const TreeIterator<T>& other) const
Node<T>* operator->()
std::shared_ptr<Node<T>> operator*()
Traversal Methods:

void traverse_pre_order(std::shared_ptr<Node<T>> node)
void traverse_post_order(std::shared_ptr<Node<T>> node)
void traverse_in_order(std::shared_ptr<Node<T>> node)
void traverse_bfs(std::shared_ptr<Node<T>> node)
void traverse_dfs(std::shared_ptr<Node<T>> node)
void traverse_heap(std::shared_ptr<Node<T>> node)

Complex
The Complex class handles complex numbers and provides basic arithmetic operations.

Methods:

Constructor: Complex(double r, double i)

Initializes the complex number with real and imaginary parts.
Getters and Setters:

double getReal() const
double getImag() const
void setReal(double r)
void setImag(double i)
Operator Overloads:

Complex operator+(const Complex& other) const
Complex operator-(const Complex& other) const
Complex operator*(const Complex& other) const
Complex operator/(const Complex& other) const
bool operator<(const Complex& other) const
bool operator==(const Complex& other) const
bool operator!=(const Complex& other) const
Complex operator-() const
friend std::ostream& operator<<(std::ostream& out, const Complex& c)





