#include <iostream>
using namespace std;
// post-order-traversal.
struct treeNode {
    int data;
    treeNode* left;
    treeNode* right;

    treeNode(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};
class tree {
private:
    treeNode* root;

    // Post-Order Traversal function
    void postOrder(treeNode* node) {
        // Base case: If node is null, return
        if (node == nullptr)
            return;
        // Recursive case #01: Traverse the left subtree
        postOrder(node->left);

        // Recursive case #02: Traverse the right subtree
        postOrder(node->right);

        // Visit the current node (Root)
        cout << node->data << " ";
    }
    // Helper function to insert nodes into the tree
    treeNode* insertNode(treeNode* node, int value) {
        if (node == nullptr)
            return new treeNode(value);

        if (value < node->data)
            node->left = insertNode(node->left, value);
        else
            node->right = insertNode(node->right, value);

        return node;
    }
public:
    tree() : root(nullptr) {}

    // Insert values from an array into the tree
    void insertFromArray(int values[], int size) {
        for (int i = 0; i < size; i++) {
            root = insertNode(root, values[i]);
        }
    }
    // Wrapper function to start Post-Order Traversal
    void printPostOrder() {
        cout << "Post-Order Traversal: ";
        postOrder(root);
        cout << endl;
    }
};
int main() {
    tree Tree;
    int values[] = {5, 3, 7, 2, 4};
    int size = sizeof(values) / sizeof(values[0]);
    // Insert values into the tree
    Tree.insertFromArray(values, size);
    // Perform Post-Order Traversal
    Tree.printPostOrder();

    return 0;
}
