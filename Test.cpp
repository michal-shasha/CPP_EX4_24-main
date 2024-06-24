#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Tree.hpp"
#include "Node.hpp"
#include "TreeIterator.hpp"

TEST_CASE("TreeIterator Pre-Order Traversal") {
    Node<int> root(1);
    Node<int> child1(2);
    Node<int> child2(3);
    root.add_child(std::make_shared<Node<int>>(child1));
    root.add_child(std::make_shared<Node<int>>(child2));

    Tree<int, 2> tree;
    tree.add_root(root);

    auto it = tree.begin_pre_order();
    auto end = tree.end_pre_order();

    std::vector<int> values;
    while (it != end) {
        values.push_back((*it)->get_value());
        ++it;
    }

    REQUIRE(values == std::vector<int>{1, 2, 3});
}

TEST_CASE("TreeIterator Post-Order Traversal") {
    Node<int> root(1);
    Node<int> child1(2);
    Node<int> child2(3);
    root.add_child(std::make_shared<Node<int>>(child1));
    root.add_child(std::make_shared<Node<int>>(child2));

    Tree<int, 2> tree;
    tree.add_root(root);

    auto it = tree.begin_post_order();
    auto end = tree.end_post_order();

    std::vector<int> values;
    while (it != end) {
        values.push_back((*it)->get_value());
        ++it;
    }

    REQUIRE(values == std::vector<int>{2, 3, 1});
}

TEST_CASE("TreeIterator In-Order Traversal") {
    Node<int> root(1);
    Node<int> child1(2);
    Node<int> child2(3);
    root.add_child(std::make_shared<Node<int>>(child1));
    root.add_child(std::make_shared<Node<int>>(child2));

    Tree<int, 2> tree;
    tree.add_root(root);

    auto it = tree.begin_in_order();
    auto end = tree.end_in_order();

    std::vector<int> values;
    while (it != end) {
        values.push_back((*it)->get_value());
        ++it;
    }

    REQUIRE(values == std::vector<int>{2, 1, 3});
}

TEST_CASE("TreeIterator BFS Traversal") {
    Node<int> root(1);
    Node<int> child1(2);
    Node<int> child2(3);
    root.add_child(std::make_shared<Node<int>>(child1));
    root.add_child(std::make_shared<Node<int>>(child2));

    Tree<int, 2> tree;
    tree.add_root(root);

    auto it = tree.begin_bfs_scan();
    auto end = tree.end_bfs_scan();

    std::vector<int> values;
    while (it != end) {
        values.push_back((*it)->get_value());
        ++it;
    }

    REQUIRE(values == std::vector<int>{1, 2, 3});
}

TEST_CASE("TreeIterator DFS Traversal") {
    Node<int> root(1);
    Node<int> child1(2);
    Node<int> child2(3);
    root.add_child(std::make_shared<Node<int>>(child1));
    root.add_child(std::make_shared<Node<int>>(child2));

    Tree<int, 2> tree;
    tree.add_root(root);

    auto it = tree.begin_dfs_scan();
    auto end = tree.end_dfs_scan();

    std::vector<int> values;
    while (it != end) {
        values.push_back((*it)->get_value());
        ++it;
    }

    REQUIRE(values == std::vector<int>{1, 2, 3});
}

TEST_CASE ("3-arity TreeIterator Pre-Order Traversal") {
    Node<int> root(1);
    Node<int> child1(2);
    Node<int> child2(3);
    Node<int> child3(4);
    root.add_child(std::make_shared<Node<int>>(child1));
    root.add_child(std::make_shared<Node<int>>(child2));
    root.add_child(std::make_shared<Node<int>>(child3));

    Tree<int, 3> tree;
    tree.add_root(root);

    auto it = tree.begin_pre_order();
    auto end = tree.end_pre_order();

    std::vector<int> values;
    while (it != end) {
        values.push_back((*it)->get_value());
        ++it;
    }

    REQUIRE(values == std::vector<int>{1, 2, 3, 4});
}

TEST_CASE ("3-arity TreeIterator Post-Order Traversal") {
    Node<int> root(1);
    Node<int> child1(2);
    Node<int> child2(3);
    Node<int> child3(4);
    root.add_child(std::make_shared<Node<int>>(child1));
    root.add_child(std::make_shared<Node<int>>(child2));
    root.add_child(std::make_shared<Node<int>>(child3));

    Tree<int, 3> tree;
    tree.add_root(root);

    auto it = tree.begin_post_order();
    auto end = tree.end_post_order();

    std::vector<int> values;
    while (it != end) {
        values.push_back((*it)->get_value());
        ++it;
    }

    REQUIRE(values == std::vector<int>{2, 3, 4, 1});
}

TEST_CASE ("3-arity TreeIterator In-Order Traversal") {
    Node<int> root(1);
    Node<int> child1(2);
    Node<int> child2(3);
    Node<int> child3(4);
    root.add_child(std::make_shared<Node<int>>(child1));
    root.add_child(std::make_shared<Node<int>>(child2));
    root.add_child(std::make_shared<Node<int>>(child3));

    Tree<int, 3> tree;
    tree.add_root(root);

    auto it = tree.begin_in_order();
    auto end = tree.end_in_order();

    std::vector<int> values;
    while (it != end) {
        values.push_back((*it)->get_value());
        ++it;
    }

    REQUIRE(values == std::vector<int>{2, 1, 3, 4});
}

TEST_CASE ("3-arity TreeIterator BFS Traversal") {
    Node<int> root(1);
    Node<int> child1(2);
    Node<int> child2(3);
    Node<int> child3(4);
    root.add_child(std::make_shared<Node<int>>(child1));
    root.add_child(std::make_shared<Node<int>>(child2));
    root.add_child(std::make_shared<Node<int>>(child3));

    Tree<int, 3> tree;
    tree.add_root(root);

    auto it = tree.begin_bfs_scan();
    auto end = tree.end_bfs_scan();

    std::vector<int> values;
    while (it != end) {
        values.push_back((*it)->get_value());
        ++it;
    }

    REQUIRE(values == std::vector<int>{1, 2, 3, 4});
}

TEST_CASE ("3-arity TreeIterator DFS Traversal") {
    Node<int> root(1);
    Node<int> child1(2);
    Node<int> child2(3);
    Node<int> child3(4);
    root.add_child(std::make_shared<Node<int>>(child1));
    root.add_child(std::make_shared<Node<int>>(child2));
    root.add_child(std::make_shared<Node<int>>(child3));

    Tree<int, 3> tree;
    tree.add_root(root);

    auto it = tree.begin_dfs_scan();
    auto end = tree.end_dfs_scan();

    std::vector<int> values;
    while (it != end) {
        values.push_back((*it)->get_value());
        ++it;
    }

    REQUIRE(values == std::vector<int>{1, 2, 3, 4});
}

TEST_CASE("4-arity TreeIterator Pre-Order Traversal") {
    Node<int> root(1);
    Node<int> child1(2);
    Node<int> child2(3);
    Node<int> child3(4);
    Node<int> child4(5);
    root.add_child(std::make_shared<Node<int>>(child1));
    root.add_child(std::make_shared<Node<int>>(child2));
    root.add_child(std::make_shared<Node<int>>(child3));
    root.add_child(std::make_shared<Node<int>>(child4));

    Tree<int, 4> tree;
    tree.add_root(root);

    auto it = tree.begin_pre_order();
    auto end = tree.end_pre_order();

    std::vector<int> values;
    while (it != end) {
        values.push_back((*it)->get_value());
        ++it;
    }

    REQUIRE(values == std::vector<int>{1, 2, 3, 4, 5});
}

TEST_CASE("8-arity TreeIterator Pre-Order Traversal") {
    Node<int> root(1);
    Node<int> child1(2);
    Node<int> child2(3);
    Node<int> child3(4);
    Node<int> child4(5);
    Node<int> child5(6);
    Node<int> child6(7);
    Node<int> child7(8);
    root.add_child(std::make_shared<Node<int>>(child1));
    root.add_child(std::make_shared<Node<int>>(child2));
    root.add_child(std::make_shared<Node<int>>(child3));
    root.add_child(std::make_shared<Node<int>>(child4));
    root.add_child(std::make_shared<Node<int>>(child5));
    root.add_child(std::make_shared<Node<int>>(child6));
    root.add_child(std::make_shared<Node<int>>(child7));

    Tree<int, 8> tree;
    tree.add_root(root);

    auto it = tree.begin_pre_order();
    auto end = tree.end_pre_order();

    std::vector<int> values;
    while (it != end) {
        values.push_back((*it)->get_value());
        ++it;
    }

    REQUIRE(values == std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8});
}

TEST_CASE("2-arity TreeIterator Range-Based Loop") {
    Node<int> root(1);
    Node<int> child1(2);
    Node<int> child2(3);
    root.add_child(std::make_shared<Node<int>>(child1));
    root.add_child(std::make_shared<Node<int>>(child2));

    Tree<int, 2> tree;
    tree.add_root(root);

    std::vector<int> values;
    for (const auto& node : tree) {
        values.push_back(node->get_value());
    }

    REQUIRE(values == std::vector<int>{1, 2, 3});
}

TEST_CASE("3-arity TreeIterator Range-Based Loop") {
    Node<int> root(1);
    Node<int> child1(2);
    Node<int> child2(3);
    Node<int> child3(4);
    root.add_child(std::make_shared<Node<int>>(child1));
    root.add_child(std::make_shared<Node<int>>(child2));
    root.add_child(std::make_shared<Node<int>>(child3));

    Tree<int, 3> tree;
    tree.add_root(root);

    std::vector<int> values;
    for (const auto& node : tree) {
        values.push_back(node->get_value());
    }

    REQUIRE(values == std::vector<int>{1, 2, 3, 4});
}

TEST_CASE("4-arity TreeIterator Range-Based Loop") {
    Node<int> root(1);
    Node<int> child1(2);
    Node<int> child2(3);
    Node<int> child3(4);
    Node<int> child4(5);
    root.add_child(std::make_shared<Node<int>>(child1));
    root.add_child(std::make_shared<Node<int>>(child2));
    root.add_child(std::make_shared<Node<int>>(child3));
    root.add_child(std::make_shared<Node<int>>(child4));

    Tree<int, 4> tree;
    tree.add_root(root);

    std::vector<int> values;
    for (const auto& node : tree) {
        values.push_back(node->get_value());
    }

    REQUIRE(values == std::vector<int>{1, 2, 3, 4, 5});
}
