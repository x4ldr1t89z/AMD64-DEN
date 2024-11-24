#include <iostream>
using namespace std;
// pre-order-traversal
struct treeNode {
    int data;
    treeNode* left;
    treeNode* right;

    treeNode(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

class tree {
private:
    treeNode* root;
    // Pre-order traversal function.
    void preVar(treeNode* node) {
        // Base case.
        if (node == NULL)
            return;

        // Visit current node first.
        cout << node->data << " ";

        // Recursive case #1: Visit left subtree.
        preVar(node->left);

        // Recursive case #2: Visit right subtree.
        preVar(node->right);
    }
    // Basic helper function to insert a new node in the tree.
    treeNode* insertNode(treeNode* node, int value) {
        if (node == NULL)
            return new treeNode(value);

        if (value < node->data)
            node->left = insertNode(node->left, value);
        else
            node->right = insertNode(node->right, value);

        return node;
    }

public:
    tree() : root(nullptr) {}
    // Insert values from array.
    void insertFromArray(int values[], int size) {
        for (int i = 0; i < size; i++) {
            root = insertNode(root, values[i]);
        }
    }
    // Print values in pre-order.
    void print() {
        cout << "pre-order traversal: ";
        preVar(root);
        cout << '\n';
    }
};
int main() {
    tree Tree;
    int values[] = {5, 3, 7, 2, 4};
    int size = sizeof(values) / sizeof(values[0]);

    Tree.insertFromArray(values, size);
    Tree.print();

    return 0;
}
