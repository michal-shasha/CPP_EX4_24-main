#ifndef NODE_HPP
#define NODE_HPP

#include <vector>
#include <memory>

template <typename T>
class Node {
public:
    Node(T value);


    T get_value() const ;
    void add_child(const std::shared_ptr<Node<T>>& child);
    std::vector<std::shared_ptr<Node<T>>> get_children() const;

private:
    T value;
    std::vector<std::shared_ptr<Node<T>>> children;
};

#include "Node.tpp"

#endif // NODE_HPP
