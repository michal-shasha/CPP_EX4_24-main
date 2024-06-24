#ifndef NODE_TPP
#define NODE_TPP

#include "Node.hpp"

template<typename T>
Node<T>::Node(T val) : value(val) {}

template<typename T>
T Node<T>::get_value() const {
    return value;
}

template<typename T>
void Node<T>::add_child(const std::shared_ptr<Node<T>>& child) {
    children.push_back(child);
}

template<typename T>
std::vector<std::shared_ptr<Node<T>>> Node<T>::get_children() const {
    return children;
}

#endif // NODE_TPP
