#include <iostream>
using namespace std;
// in-order-traversal
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

    // In-order traversal function.
    void inVar(treeNode* node) {
        // Base case.
        if (node == NULL)
            return;
        // Recursive case #1.
        inVar(node->left);

        cout << node->data << " ";

        // Recursive case #2.
        inVar(node->right);
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
    // Print values in in-order.
    void print() {
        cout << "in-order traversal: ";
        inVar(root);
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
