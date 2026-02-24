#include <iostream>
using namespace std;

struct node{
    char data;
    node* left;
    node* right;

    node(char value) : data(value), left(nullptr), right(nullptr) {}
};

class Binarytree {
    public:
        node* root;
        Binarytree() : root(nullptr) {}

        void displayconnections(node* current) {
            if (current == nullptr) return;
            if (current->left != nullptr) {
                cout << current->data << " -> " << current->left->data << " (left)" << endl;
            }
            if (current->right != nullptr) {
                cout << current->data << " -> " << current->right->data << " (right)" << endl;
            }
            displayconnections(current->left);
            displayconnections(current->right);
        }
};

int main(){
    Binarytree puno;

    puno.root = new node('A');
    puno.root->left = new node('B');
    puno.root->right = new node('C');
    puno.root->left->left = new node('D');
    puno.root->left->right = new node('E');
    puno.root->right->left = new node('F');
    puno.root->right->right = new node('G');

    cout << "The connections in the binary tree are:" << endl;
    puno.displayconnections(puno.root);
    return 0;
}