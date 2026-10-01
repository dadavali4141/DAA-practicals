#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node* buildTree() {
    int data;

    cout << "Enter the Data: ";
    cin >> data;

    if (data == -1) {
        return NULL;
    }

    Node* root = new Node(data);

    cout << "For left node" << endl;
    root->left = buildTree();

    cout << "For right node" << endl;
    root->right = buildTree();

    return root;
}

void levelOrderTraversal(Node* root) {

    if (root == NULL) {
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {

        Node* temp = q.front();
        q.pop();

        cout << temp->data << " ";

        if (temp->left != NULL) {
            q.push(temp->left);
        }

        if (temp->right != NULL) {
            q.push(temp->right);
        }
    }
}

int main() {

    Node* root = buildTree();

    cout << "\nLevel Order Traversal:" << endl;
    levelOrderTraversal(root);

    return 0;
}