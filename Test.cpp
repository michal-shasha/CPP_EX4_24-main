//325763498
//michalshasha8@gmail.com

#include "doctest.h"
#include "Tree.hpp"
#include "Complex.hpp"
#include <vector>
#include <iostream>


TEST_CASE("Tree traversal methods") {
    Tree<Complex> tree;
    Complex root_val(1.0, 1.0);
    Node<Complex> root_node(root_val);
    tree.add_root(root_node);

    Complex val1(2.0, 2.0);
    Complex val2(3.0, 3.0);
    Complex val3(4.0, 4.0);
    Complex val4(5.0, 5.0);
    Complex val5(6.0, 6.0);

    Node<Complex> n1(val1);
    Node<Complex> n2(val2);
    Node<Complex> n3(val3);
    Node<Complex> n4(val4);
    Node<Complex> n5(val5);

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    SUBCASE("Pre-order traversal") {
        std::vector<Complex> values;
        for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node) {
            values.push_back(node->get_value());
        }
        std::vector<Complex> expected = {root_val, val1, val3, val4, val2, val5};
        CHECK(values == expected);
    }

    SUBCASE("Post-order traversal") {
        std::vector<Complex> values;
        for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node) {
            values.push_back(node->get_value());
        }
        std::vector<Complex> expected = {val3, val4, val1, val5, val2, root_val};
        CHECK(values == expected);
    }

    SUBCASE("In-order traversal") {
        std::vector<Complex> values;
        for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node) {
            values.push_back(node->get_value());
        }
        std::vector<Complex> expected = {val3, val1, val4, root_val, val5, val2};
        CHECK(values == expected);
    }

    SUBCASE("Breadth-first traversal") {
        std::vector<Complex> values;
        for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node) {
            values.push_back(node->get_value());
        }
        std::vector<Complex> expected = {root_val, val1, val2, val3, val4, val5};
        CHECK(values == expected);
    }

    SUBCASE("Depth-first traversal") {
        std::vector<Complex> values;
        for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node) {
            values.push_back(node->get_value());
        }
        std::vector<Complex> expected = {root_val, val1, val3, val4, val2, val5};
        CHECK(values == expected);
    }
}


TEST_CASE("Integer Tree - Pre-order Traversal") {
    Tree<int, 3> tree;
    Node<int> root_node(8);
    tree.add_root(root_node);

    Node<int> n1(7);
    Node<int> n2(3);
    Node<int> n3(6);
    Node<int> n4(2);
    Node<int> n5(1);

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    std::vector<int> values;
    for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node) {
        values.push_back((*node)->get_value());
    }

    std::vector<int> expected = {8,7,6,2,3,1};
    CHECK(values == expected);
}

TEST_CASE("Integer Tree - Post-order Traversal") {
    Tree<int, 3> tree;
    Node<int> root_node(10);
    tree.add_root(root_node);

    Node<int> n1(22);
    Node<int> n2(50);
    Node<int> n3(11);
    Node<int> n4(5);
    Node<int> n5(62);

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    std::vector<int> values;
    for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node) {
        values.push_back((*node)->get_value());
    }

    std::vector<int> expected = {10,22,11,5,50,62};
    CHECK(values == expected);
}

TEST_CASE("Integer Tree - In-order Traversal") {
    Tree<int, 3> tree;
    Node<int> root_node(1);
    tree.add_root(root_node);

    Node<int> n1(2);
    Node<int> n2(3);
    Node<int> n3(4);
    Node<int> n4(5);
    Node<int> n5(6);

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    std::vector<int> values;
    for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node) {
        values.push_back((*node)->get_value());
    }

    std::vector<int> expected = {1,2,4,5,3,6};
    CHECK(values == expected);
}

TEST_CASE("Integer Tree - Breadth-first Traversal") {
    Tree<int, 3> tree;
    Node<int> root_node(1);
    tree.add_root(root_node);

    Node<int> n1(2);
    Node<int> n2(3);
    Node<int> n3(4);
    Node<int> n4(5);
    Node<int> n5(6);

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    std::vector<int> values;
    for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node) {
        values.push_back((*node)->get_value());
    }

    std::vector<int> expected = {1, 2, 3, 4, 5, 6};
    CHECK(values == expected);
}

TEST_CASE("Integer Tree - Depth-first Traversal") {
    Tree<int, 3> tree;
    Node<int> root_node(1);
    tree.add_root(root_node);

    Node<int> n1(2);
    Node<int> n2(3);
    Node<int> n3(4);
    Node<int> n4(5);
    Node<int> n5(6);

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    std::vector<int> values;
    for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node) {
        values.push_back((*node)->get_value());
    }

    std::vector<int> expected = {1, 2, 4, 5, 3, 6};
    CHECK(values == expected);
}

TEST_CASE("Integer Tree - Heap Traversal") {
    Tree<int, 3> tree;
    Node<int> root_node(1);
    tree.add_root(root_node);

    Node<int> n1(2);
    Node<int> n2(3);
    Node<int> n3(4);
    Node<int> n4(5);
    Node<int> n5(6);

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    std::vector<int> values;
    for (auto node = tree.begin_heap(); node != tree.end_heap(); ++node) {
        values.push_back((*node)->get_value());
    }

    std::vector<int> expected = {1, 2, 3, 4, 5, 6};
    CHECK(values == expected);
}

TEST_CASE("Pre-order Traversal") {
    Tree<double, 3> tree;
    Node<double> root_node(1.0);
    tree.add_root(root_node);

    Node<double> n1(2.05);
    Node<double> n2(3.0);
    Node<double> n3(4.2);
    Node<double> n4(5.1);
    Node<double> n5(6.2);

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    std::vector<double> values;
    for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node) {
        values.push_back((*node)->get_value());
    }

    std::vector<double> expected = {1.0, 2.05, 4.2, 5.1, 3.0, 6.2};
    CHECK(values == expected);
}

TEST_CASE("Double Tree - Post-order Traversal") {
    Tree<double, 3> tree;
    Node<double> root_node(1.0);
    tree.add_root(root_node);

    Node<double> n1(2.0);
    Node<double> n2(3.0);
    Node<double> n3(4.0);
    Node<double> n4(5.0);
    Node<double> n5(6.0);

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    std::vector<double> values;
    for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node) {
        values.push_back((*node)->get_value());
    }

    std::vector<double> expected = {1.0, 2.0, 4.0, 5.0, 3.0, 6.0};
    CHECK(values == expected);
}

TEST_CASE("String Tree - Pre-order Traversal") {
    Tree<std::string, 3> tree;
    Node<std::string> root_node("root");
    tree.add_root(root_node);

    Node<std::string> n1("node1");
    Node<std::string> n2("node2");
    Node<std::string> n3("node3");
    Node<std::string> n4("node4");
    Node<std::string> n5("node5");

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    std::vector<std::string> values;
    for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node) {
        values.push_back((*node)->get_value());
    }

    std::vector<std::string> expected = {"root", "node1", "node3", "node4", "node2", "node5"};
    CHECK(values == expected);
}

TEST_CASE("String Tree- Heap Traversal") {
    Tree<std::string, 3> tree;
    Node<std::string> root_node("M");
    tree.add_root(root_node);

    Node<std::string> n1("I");
    Node<std::string> n2("C");
    Node<std::string> n3("H");
    Node<std::string> n4("A");
    Node<std::string> n5("L");

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    std::vector<std::string> values;
    for (auto node = tree.begin_heap(); node != tree.end_heap(); ++node) {
        values.push_back((*node)->get_value());
    }

    // Adjust the expected values to lexicographical order
    std::vector<std::string> expected = {"A", "C", "H", "I", "L", "M"};
    CHECK(values == expected);
}


TEST_CASE("String Tree- Heap Traversal") {
    Tree<std::string, 3> tree;
    Node<std::string> root_node("S");
    tree.add_root(root_node);

    Node<std::string> n1("H");
    Node<std::string> n2("A");
    Node<std::string> n3("S");
    Node<std::string> n4("H");
    Node<std::string> n5("A");

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    std::vector<std::string> values;
    for (auto node = tree.begin_heap(); node != tree.end_heap(); ++node) {
        values.push_back((*node)->get_value());
    }

    // Adjust the expected values to lexicographical order
    std::vector<std::string> expected = {"A", "A", "H", "H", "S", "S"};
    CHECK(values == expected);
}

TEST_CASE("Complex Tree - Pre-order Traversal") {
    Tree<Complex, 3> tree;
    Complex root_val(1.0, 1.0);
    Node<Complex> root_node(root_val);
    tree.add_root(root_node);

    Complex val1(2.0, 2.0);
    Complex val2(3.0, 3.0);
    Complex val3(4.0, 4.0);
    Complex val4(5.0, 5.0);
    Complex val5(6.0, 6.0);

    Node<Complex> n1(val1);
    Node<Complex> n2(val2);
    Node<Complex> n3(val3);
    Node<Complex> n4(val4);
    Node<Complex> n5(val5);

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    std::vector<Complex> values;
    for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node) {
        values.push_back((*node)->get_value());
    }

    std::vector<Complex> expected = {root_val, val1, val3, val4, val2, val5};
    CHECK(values == expected);
}

TEST_CASE("check num of children") {
    Tree<int, 3> tree;
    Node<int> root_node(1);
    tree.add_root(root_node);

    Node<int> n1(2);
    Node<int> n2(3);
    Node<int> n3(4);
    Node<int> n4(5);
    Node<int> n5(6);

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    CHECK(tree.count_children(root_node) == 2);
    CHECK(tree.count_children(n1) == 2);
    CHECK(tree.count_children(n2) == 1);
    CHECK(tree.count_children(n3) == 0);
    CHECK(tree.count_children(n4) == 0);
    CHECK(tree.count_children(n5) == 0);
}

TEST_CASE("find node") {
    Tree<int, 3> tree;
    Node<int> root_node(1);
    tree.add_root(root_node);

    Node<int> n1(2);
    Node<int> n2(3);
    Node<int> n3(4);
    Node<int> n4(5);
    Node<int> n5(6);

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    CHECK(tree.find_node(tree.get_root(), 1)->get_value() == 1);
    CHECK(tree.find_node(tree.get_root(), 2)->get_value() == 2);
    CHECK(tree.find_node(tree.get_root(), 3)->get_value() == 3);
    CHECK(tree.find_node(tree.get_root(), 4)->get_value() == 4);
    CHECK(tree.find_node(tree.get_root(), 5)->get_value() == 5);
    CHECK(tree.find_node(tree.get_root(), 6)->get_value() == 6);
}

TEST_CASE("complex operator <"){
    Complex c1(1.0, 1.0);
    Complex c2(2.0, 2.0);
    Complex c3(3.0, 3.0);
    Complex c4(4.0, 4.0);
    Complex c5(5.0, 5.0);
    Complex c6(6.0, 6.0);

    CHECK(c1 < c2);
    CHECK(c2 < c3);
    CHECK(c3 < c4);
    CHECK(c4 < c5);
    CHECK(c5 < c6);
}

TEST_CASE("binary tree DFS"){
    Tree<int, 3> tree;
    Node<int> root_node(1);
    tree.add_root(root_node);

    Node<int> n1(2);
    Node<int> n2(3);
    Node<int> n3(4);
    Node<int> n4(5);
    Node<int> n5(6);

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(root_node, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    std::vector<int> values;
    for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node) {
        values.push_back((*node)->get_value());
    
    }

    std::vector<int> expected = {1, 2, 5, 3, 6, 4};
    CHECK(values == expected);
}







