#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int key){
    if(!root) return new Node(key);
    if(key < root->data){
        root->left = insert(root->left, key);
    } else {
        root->right = insert(root->right, key);
    }
    return root;
}

void displayConnections(Node* node) {
    if (!node) return;
    if (node->left) {
        cout<< node->data << " -> " << node->left->data << "(left)" << endl;
        displayConnections(node->left);
    }
    if (node->right) {
        cout<< node->data << " -> " << node->right->data << "(right)" << endl;
        displayConnections(node->right);
    }
}

Node* search(Node* root, int key) {
    if (!root || root->data == key) return root;
    if (key < root->data) return search(root->left, key);
    return search(root->right, key);
}

int main() {
    Node* root = nullptr;
    int keys[] = {40, 30, 25, 35, 50, 45, 60};
    for (int key : keys) {
        root = insert(root, key);
    }

    cout <<"Connections in the binary search tree:" << endl;
    displayConnections(root);

    int searchKey = 46;
    Node* foundNode = search(root, searchKey);
    if (foundNode) {
        cout << "Node with key " << searchKey <<
        " found with value " << foundNode->data << "." << endl;
    } else {
        cout << "Node with key " << searchKey << " not found." << endl;
    }

    return 0;
}