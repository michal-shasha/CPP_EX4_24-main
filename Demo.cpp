#include <iostream>
#include "Node.hpp"
#include "Tree.hpp"

using namespace std;

int main() {
    // Binary tree example
    Node<double> root_node(1.1);
    Tree<double> tree;
    tree.add_root(root_node);

    Node<double> n1(1.2);
    Node<double> n2(1.3);
    Node<double> n3(1.4);
    Node<double> n4(1.5);
    Node<double> n5(1.6);

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    // Print traversals
    cout << "Pre-order traversal: ";
    for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node) {
        cout << (*node)->get_value() << " ";
    }
    cout << endl;

    cout << "Post-order traversal: ";
    for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node) {
        cout << (*node)->get_value() << " ";
    }
    cout << endl;

    cout << "In-order traversal: ";
    for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node) {
        cout << (*node)->get_value() << " ";
    }
    cout << endl;

    cout << "BFS traversal: ";
    for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node) {
        cout << (*node)->get_value() << " ";
    }
    cout << endl;

    cout << "Range-based loop (same as BFS): ";
    for (const auto& node : tree) {
        cout << node->get_value() << " ";
    }
    cout << endl;

    cout << "Tree structure (operator<<):" << endl;
    cout << tree << endl;

    // 3-ary tree example
    Node<double> root_node2(1.1);
    Tree<double, 3> three_ary_tree;
    three_ary_tree.add_root(root_node2);

    Node<double> n6(1.2);
    Node<double> n7(1.3);
    Node<double> n8(1.4);
    Node<double> n9(1.5);
    Node<double> n10(1.6);

    three_ary_tree.add_sub_node(root_node2, n6);
    three_ary_tree.add_sub_node(root_node2, n7);
    three_ary_tree.add_sub_node(root_node2, n8);
    three_ary_tree.add_sub_node(n6, n9);
    three_ary_tree.add_sub_node(n7, n10);


    // Convert to min-heap and print the tree structure again
    cout << "Converting tree to min-heap..." << endl;
    TreeIterator<double> iterator(tree.get_root(), TreeIterator<double>::Order::BFS);
    iterator.convert_to_min_heap();

    cout << "Tree structure after converting to min-heap:" << endl;
    cout << tree << endl;


    return 0;
}


    // The 3-ary tree should look like:
    /**
     *       root = 1.1
     *     /      |     \
     *    1.2    1.3    1.4
     *   /        |
     *  1.5      1.6
     */


// Output

// Pre-order traversal: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6
// Post-order traversal: 1.4, 1.5, 1.2, 1.6, 1.3, 1.1
// In-order traversal: 1.4, 1.2, 1.5, 1.1, 1.6, 1.3
// BFS traversal: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6
// Range-based loop (same as BFS):1.1, 1.2, 1.3, 1.4, 1.5, 1.6
// Tree structure (operator<<):
// 1.1 -> 1.2 -> 1.4 -> 1.5 -> 1.3 -> 1.6

