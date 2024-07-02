//325763498
//michalshasha8@gmail.com

#ifndef TREE_TPP
#define TREE_TPP
#include "Tree.hpp"
#include <sstream>

template <typename T, size_t K>
void Tree<T, K>::add_root(const Node<T>& node) {
    root = std::make_shared<Node<T>>(node.get_value()); // Create a new node with the value of 'node'
}

template <typename T, size_t K>
void Tree<T, K>::add_sub_node(const Node<T>& parent, const Node<T>& child) {
    auto parent_ptr = find_node(root, parent.get_value());
    if (parent_ptr) {
        auto child_ptr = std::make_shared<Node<T>>(child.get_value()); // Create a new node
        parent_ptr->add_child(child_ptr);
    } else {
        throw std::runtime_error("Parent node not found in the tree.");
    }
}

template <typename T, size_t K>
std::shared_ptr<Node<T>> Tree<T, K>::find_node(std::shared_ptr<Node<T>> start, const T& value) const {
    // Implement tree traversal to find the node with the specified value
    if (!start) return nullptr;
    
    if (start->get_value() == value) {
        return start;
    } else {
        for (auto child : start->get_children()) {
            auto result = find_node(child, value);
            if (result) return result;
        }
    }
    
    return nullptr;
}

template <typename T, size_t K>
size_t Tree<T, K>::count_children(const Node<T>& node) const {
    auto found_node = find_node(root, node.get_value());
    if (found_node) {
        return found_node->count_children();
    } else {
        throw std::runtime_error("Node not found in the tree.");
    }
}

template<typename T, size_t K>
TreeIterator<T,K> Tree<T, K>::begin() {
    return begin_bfs_scan();
}

template<typename T, size_t K>
TreeIterator<T,K> Tree<T, K>::end() {
    return end_bfs_scan();
}

template<typename T, size_t K>
TreeIterator<T,K> Tree<T, K>::begin_pre_order() {
    if (this->get_tree_order() > 2) {
        return TreeIterator<T,K>(root, TreeIteratorType::DFS);
    }
    return TreeIterator<T,K>(root, TreeIteratorType::PRE_ORDER);
}

template<typename T, size_t K>
TreeIterator<T,K> Tree<T, K>::end_pre_order() {
    if (this->get_tree_order() > 2) {
        return TreeIterator<T,K>(nullptr, TreeIteratorType::DFS);
    }
    return TreeIterator<T,K>(nullptr, TreeIteratorType::PRE_ORDER);
}


template<typename T, size_t K>
TreeIterator<T,K> Tree<T, K>::begin_post_order() {
   if(this->get_tree_order()>2)
    {
      return TreeIterator<T,K>(root, TreeIteratorType::DFS);
    }
    return TreeIterator<T,K>(root, TreeIteratorType::POST_ORDER);
}

template<typename T, size_t K>
TreeIterator<T,K> Tree<T, K>::end_post_order() {
  if(this->get_tree_order()>2)
    {
      return TreeIterator<T,K>(nullptr, TreeIteratorType::DFS);
    }
    return TreeIterator<T,K>(nullptr, TreeIteratorType::POST_ORDER);
}

template<typename T, size_t K>
TreeIterator<T,K> Tree<T, K>::begin_in_order() {
    if(this->get_tree_order()>2)
    {
      return TreeIterator<T,K>(this->root, TreeIteratorType::DFS);
    }
    return TreeIterator<T,K>(this->root, TreeIteratorType::IN_ORDER);
}

template<typename T, size_t K>
TreeIterator<T,K> Tree<T, K>::end_in_order() {
    if(this->get_tree_order()>2)
    {
      return TreeIterator<T,K>(nullptr, TreeIteratorType::DFS);
    }
    return TreeIterator<T,K>(nullptr, TreeIteratorType::IN_ORDER);
}

template<typename T, size_t K>
TreeIterator<T,K> Tree<T, K>::begin_bfs_scan() {
    return TreeIterator<T,K>(root, TreeIteratorType::BFS);
}

template<typename T, size_t K>
TreeIterator<T,K> Tree<T, K>::end_bfs_scan() {
    return TreeIterator<T,K>(nullptr, TreeIteratorType::BFS);
}

template<typename T, size_t K>
TreeIterator<T,K> Tree<T, K>::begin_dfs_scan() {
    return TreeIterator<T,K>(root, TreeIteratorType::DFS);
}

template<typename T, size_t K>
TreeIterator<T,K> Tree<T, K>::end_dfs_scan() {
    return TreeIterator<T,K>(nullptr, TreeIteratorType::DFS);
}

template <typename T, size_t K>
std::ostream& operator<<(std::ostream& os, const Tree<T, K>& tree) {
    // Implement a traversal to print the tree
    std::function<void(const std::shared_ptr<Node<T>>&)> print_tree = [&](const std::shared_ptr<Node<T>>& node) {
        if (node) {
            os << node->get_value() << " -> ";
            for (const auto& child : node->get_children()) { // Assuming get_children returns a vector of child nodes
                print_tree(child);
            }
        }
    };

    print_tree(tree.root);
    return os;
}

template <typename T, size_t K>
std::shared_ptr<Node<T>> Tree<T, K>:: get_root() const{
    return root;
}

template <typename T, size_t K>
void Tree<T, K>::draw_tree(sf::RenderWindow& window, std::shared_ptr<Node<T>> node, int x, int y, int horizontal_gap, sf::Font& font) {
    if (!node) return;

    // Drawing circle and lines...
    sf::Color circleColor = sf::Color::Green; // Green color for circles
    sf::Color outlineColor = sf::Color::Black; // Black color for circle outline
    sf::Color textColor = sf::Color:: Black; // Black color for text

    // Draw circle
    sf::CircleShape circle(30); // Circle radius
    circle.setFillColor(circleColor);
    circle.setOutlineThickness(2);
    circle.setOutlineColor(outlineColor);
    circle.setPosition(x, y);
    window.draw(circle);

    // Convert value to string with fixed precision
    T value = node->get_value();
    std::ostringstream oss;
    oss.precision(1);
    oss << std::fixed << value;
    std::string text = oss.str();

    // Draw text
    sf::Text textObject(text, font, 20);
    textObject.setFillColor(textColor);
    sf::FloatRect textBounds = textObject.getLocalBounds();
    textObject.setOrigin(textBounds.left + textBounds.width / 2.0f,
                         textBounds.top + textBounds.height / 2.0f);
    textObject.setPosition(x + circle.getRadius(), y + circle.getRadius());
    window.draw(textObject);

    // Draw lines to children
    auto children = node->get_children();
    int num_children = children.size();
    if (num_children > 0) {
        for (int i = 0; i < num_children; ++i) {
            int child_x = x - horizontal_gap / 2 + i * horizontal_gap;
            int child_y = y + 100;

            sf::Vertex line[] = {
                sf::Vertex(sf::Vector2f(x + circle.getRadius(), y + 2 * circle.getRadius())),
                sf::Vertex(sf::Vector2f(child_x + circle.getRadius(), child_y))
            };
            line[0].color = sf::Color::Black;
            line[1].color = sf::Color::Black;
            window.draw(line, 2, sf::Lines);

            draw_tree(window, children[i], child_x, child_y, horizontal_gap / 2, font);
        }
    }
}

template <typename T, size_t K>
void Tree<T, K>::handle_window() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Tree Display");
    // Load font
    sf::Font font;
    if (!font.loadFromFile("./DancingScript-Regular.ttf")) {
        std::cerr << "Failed to load font!" << std::endl;
        return;
    }
    window.clear(sf::Color::White); // Clear window with white color
    draw_tree(window, get_root(), 400, 50, 200, font);
    window.display();

    // Draw the tree starting from the root node
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
    }
}


template <typename T, size_t K>
void Tree<T, K>::heapify(std::shared_ptr<Node<T>> node) {
    if (!node) return;

    auto smallest = node;
    auto children = node->get_children();

    for (const auto& child : children) {
        if (child->get_value() < smallest->get_value()) {
            smallest = child;
        }
    }

    if (smallest != node) {
        T temp = node->get_value();
        node->set_value(smallest->get_value());
        smallest->set_value(temp);

        heapify(smallest);
    }
}

template <typename T, size_t K>
void Tree<T, K>::convert_to_min_heap() {
    if (!root) return;

    // Step 1: Flatten the tree to a vector of shared_ptr
    std::vector<std::shared_ptr<Node<T>>> nodes;
    flatten_to_vector(root, nodes);

    // Step 2: Convert the flattened vector into a min-heap
    std::make_heap(nodes.begin(), nodes.end(), [](const std::shared_ptr<Node<T>>& a, const std::shared_ptr<Node<T>>& b) {
        return a->get_value() > b->get_value(); // Min-heap: smallest value at the top
    });

    // Step 3: Sort the heap
    std::sort_heap(nodes.begin(), nodes.end(), [](const std::shared_ptr<Node<T>>& a, const std::shared_ptr<Node<T>>& b) {
        return a->get_value() > b->get_value(); // Sort in ascending order
    });

    // Step 4: Reconstruct the tree with the sorted heap
    root->clear_children(); // Assuming Node<T> has a method to clear children

    // Rebuild the tree with the sorted nodes
    for (size_t i = 1; i < nodes.size(); ++i) {
        auto parent_index = (i - 1) / K;
        auto parent = nodes[parent_index];
        auto child = nodes[i];
        parent->add_child(child);
    }
}


template <typename T, size_t K>
TreeIterator<T,K> Tree<T, K>::begin_heap() {
    return TreeIterator<T,K>(root, TreeIteratorType::HEAP);
}

template <typename T, size_t K>
TreeIterator<T,K> Tree<T, K>::end_heap() {
    return TreeIterator<T,K>(nullptr, TreeIteratorType::HEAP);
}

template <typename T, size_t K>
int Tree<T, K>::get_tree_order() const {
    return tree_order;
}


#endif // TREE_TPP
