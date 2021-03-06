/**
 * A binary tree built with pointers
 */

#include <iostream>

template <typename T>
struct Node {
    T data;
    Node* left;
    Node* right;
};

template <typename T>
class BinaryTree {
public:
    Node<T>* root;

    void SetNull() {
        root = nullptr;
    }

    BinaryTree() {
        SetNull();
    }

    // In-order traversal of the tree
    void inorder(std::ostream& out, Node<T>* root) const {
        if (!root) return;

        inorder(out, root->left);

        out << root->data << " ";

        inorder(out, root->right);
    }

    // Height of the tree
    // A single node tree has height 1
    int height(Node<T>* root) const {
        if (!root) return 0;

        return 1 + std::max(
            height(root->left),
            height(root->right)
        );
    }


    // TODO: Function to construct a tree from an istream
    // TODO: Function to insert a new node to the tree? (BST property)

    friend std::ostream& operator<<(std::ostream& out, const BinaryTree<T>& BT) {
        BT.inorder(out, BT.root);
        return out;
    }
};
