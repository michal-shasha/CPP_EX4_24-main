//325763498
//michalshasha8@gmail.com

#ifndef NODE_HPP
#define NODE_HPP

#include <vector>
#include <memory>

template<typename T>
class Node {
public:
    Node(T val);

    T get_value() const;
    void set_value(T new_value);

    void add_child(const std::shared_ptr<Node<T>>& child);
    const std::vector<std::shared_ptr<Node<T>>>& get_children() const;

    std::shared_ptr<Node<T>> get_left_child() const;
    std::shared_ptr<Node<T>> get_right_child() const;

    size_t count_children() const;

    void clear_children();

private:
    T value;
    std::vector<std::shared_ptr<Node<T>>> children;
};

#include "Node.tpp"

#endif // NODE_HPP
