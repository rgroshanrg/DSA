#include <iostream>
#include <stack>
using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int data) {
            this->left = NULL;
            this->right = NULL;
            this->data = data;
        }
        Node() {
            this->left = this->right = NULL;
        }
};

Node* findParent(Node* root, Node *child) {
    if(root == child)
        return NULL;
    if(root->left == child || root->right == child)
        return root;
    if(child->data < root->data)
        return findParent(root->left, child);
    if(child->data  > root->data)
        return findParent(root->right, child);
    return NULL;
}

Node* insert(Node* root, int data) {
    if(root == NULL) {
        root = new Node(data);
        return root;
    }
    if(data < root->data)
        root->left = insert(root->left, data);
    else if(data > root->data)
        root->right = insert(root->right, data);
    return root;
}

void preorder(Node* root) {
    if(root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if(root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root) {
    if(root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
Node* search(Node* root, int key) {
    if(root == NULL)
        return NULL;
    if(root->data == key)
        return root;
    if(key < root->data)
        return search(root->left, key);
    else if(key > root->data)
        return search(root->right, key);
    return NULL;
}

int main() {
    Node* root = NULL;
    // root = new Node(20);
    root = insert(root, 20);
    root = insert(root, 15);
    root = insert(root, 12);
    root = insert(root, 11);
    root = insert(root, 18);
    root = insert(root, 9);
    preorder(root); cout<<endl;
    cout<<findParent(root, search(root, 20))->data;

    return 0;
}
