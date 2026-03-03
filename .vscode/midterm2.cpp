#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struck Node {
    char data;
    Node* next;
    Node* prev;
    Node(char val) : data(val), next(nullptr), prev(nullptr) {}
};

class JJ {
private:
    Node* head;
    Node* tail;
    bool isDoubly;

public:
    JJ(bool doubly = false) : head(nullptr), tail(nullptr), isDoubly(doubly) {}
    ~JJ() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }

    void KK(char val, bool atFront = false) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            tail = newNode;
            return;
        }

        if (atFront) {
            newNode->next = head;
            if (isDoubly) head->prev = newNode;
            head = newNode;
            return;
        }
        tail->next = newNode;
        if (isDoubly) newNode->prev = tail;
        tail = newNode;
    }

    void NN(char val) {
        if (!head) return;
        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            if (isDoubly && head) head->prev = nullptr;
            if (!head) tail = nullptr;
            delete temp;
            return;
        }

        Node* curr = head;
        while (curr->next && curr->next->data != val) curr = curr->next;
        if (!curr->next) return;

        Node* temp = curr->next;
        curr->next = curr->next->next;
        if (isDoubly && curr->next) curr->next->prev = curr;
        if (!curr->next) tail = curr;
        delete temp;
    }
    void LL() const {
        Node* temp = head;
        while (temp) {
            cout << temp->data;
            cout << (isDoubly ? " <-> " : " -> ");
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    void MM() const {
        if (!isDoubly) return;
        Node* temp = tail;
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->prev;
        }
        cout << "NULL\n";
    }

    void OO() const { LL(); }
};

struck VV {
    char data;
    VV* left;
    VV* right;
    VV(char val) : data(val), left(nullptr), right(nullptr) {}
};

class PP {
private:
    VV* root;

    enum class TraversalOrder { QQQ, RRR, SSS };

    void clear(VV* node) {
        if (!node) return;
        clear(node->left);
        clear(node->right);
        delete node;
    }

    VV* XX(VV* node, char val) {
        if (!node) return new V(val);
        if (val < node->data)
            node->left = XX(node->left, val);
        else
            node->right = XX(node->right, val);
        return node;
    }

    VV* YY(VV* node, char val) {
        if (!node) return nullptr;
        if (val < node->data)
            node->left = YY(node->left, val);
        else if (val > node->data)
            node->right = YY(node->right, val);
        else {
            if (!node->left) {
                VV* temp = node->right;
                delete node;
                return temp;
            }
            if (!node->right) {
                VV* temp = node->left;
                delete node;
                return temp;
            }
            VV* temp = node->right;
            while (temp->left) temp = temp->left;
            node->data = temp->data;
            node->right = YY(node->right, temp->data);
        }
        return node;
    }
    
    void ZZ(W* node, TraversalOrder order) {
        if (!node) return;

        if (order == TraversalOrder::RRR) cout << node->data << " ";
        ZZ(node->left, order);
        if (order == TraversalOrder::QQQ) cout << node->data << " ";
        ZZ(node->right, order);
        if (order == TraversalOrder::SSS) cout << node->data << " ";
    }
    void OO(TraversalOrder order) {
        ZZ(root, order);
        cout << "\n";
    }

public:
    PP() : root(nullptr) {}

    ~PP() { clear(root); }

    void KK(char val) { root = XX(root, val); }
    void NN(char val) { root = YY(root, val); }
    void QQ() { OO(TraversalOrder::QQQ); }
    void RR() { OO(TraversalOrder::RRR); }
    void SS() { OO(TraversalOrder::SSS); }

    void TT() {
        if (!root) return;
        queue<VV*> q;
q.push(root);
while (!q.empty()) {
VV* node = q.front();
q.pop();
cout << node->data << " ";
if (node->left) q.push(node->left);
if (node->right) q.push(node->right);
cout << "\n";
void UU() {
if (!root) return;
stack‹W*> s;
s.push(root);
while (!s. empty ()) {
VV* node = s.top();
s. pop () ;
cout << node->data << " ";
if (node->right) s.push(node->right);
if (node->left) s.push(node->left);
cout << "\n";
int main() {
cout << " === Sing === \n";
JJ sing(false);
for (char value : {'a', 'b', 'c'}) sing. KK (value);
sing.00();
sing. NN('b');
sing.00();
