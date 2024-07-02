//325763498
//michalshasha8@gmail.com
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
void Node<T>::set_value(T new_value) {
    value = new_value;
}

template<typename T>
void Node<T>::add_child(const std::shared_ptr<Node<T>>& child) {
    children.push_back(child);
}

template<typename T>
const std::vector<std::shared_ptr<Node<T>>>& Node<T>::get_children() const {
    return children;
}

template<typename T>
std::shared_ptr<Node<T>> Node<T>::get_left_child() const {
    if (children.size() > 0) {
        return children[0]; 
    }
    return nullptr; // No left child
}

template<typename T>
std::shared_ptr<Node<T>> Node<T>::get_right_child() const {
    if (children.size() > 1) {
        return children[1]; 
    }
    return nullptr; // No right child
}

template<typename T>
void Node<T>::clear_children() {
    children.clear();
}

template<typename T>
size_t Node<T>::count_children() const {
    return children.size();
}

#endif // NODE_TPP

