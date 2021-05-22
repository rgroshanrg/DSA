#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Node {    
    public :
        int data;
        Node *left;
        Node *right;
        Node(int data) {
            this->data = data;
            left = right = NULL;
        }
        Node() {
            left = right = NULL;
        }
};

Node* insert(Node* root, int data) {
    Node* newNode = new Node(data);
    if(root == NULL) {
        root = newNode;
        return root;
    }
    queue<Node*> Q;
    Q.push(root);
    while(!Q.empty()) {
        Node* temp = Q.front();
        Q.pop();
        if(temp->left == NULL) {
            temp->left = newNode;
            break;
        } else {
            Q.push(temp->left);
        }
        if(temp->right == NULL) {
            temp->right = newNode;
            break;
        } else {
            Q.push(temp->right);
        }
        
    }
    return root;
}

int height(Node *root) {
    if(root == NULL)
        return 0;
    int left_height = height(root->left);
    int right_height = height(root->right);
    int height;
    if(left_height > right_height)
        height = left_height+1;
    else 
        height = right_height+1;
    return height;
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

void levelorder(Node* root) {
    if(root == NULL)
        return;
    queue<Node*> Q;
    Q.push(root);
    while(!Q.empty()) {
        Node* temp = Q.front();
        Q.pop();
        cout << temp->data << " ";
        if(temp->left)
            Q.push(temp->left);
        if(temp->right)
            Q.push(temp->right);        
    }
}
Node* findParent(Node *root, Node *child) {
    queue<Node*> Q;
    Q.push(root);
    Node *temp = NULL;
    while(!Q.empty()) {
        temp = Q.front();
        Q.pop();
        if(temp->left == child || temp->right == child) {
            return temp;
        }
        if(temp->left) {
            Q.push(temp->left);
        }
        if(temp->right) {
            Q.push(temp->right);
        }
    }
    return NULL;
}
Node* del(Node *root, int data) {
    if(root->data == data && !root->left && !root->right) {
        delete root;
        return NULL;
    }

    queue<Node*> Q;
    Q.push(root);
    Node *toDel = NULL;
    Node *temp = NULL;
    while(!Q.empty()) {
        temp = Q.front();
        Q.pop();
        if(temp->data == data) {
            toDel = temp;
        }
        if(temp->left) {
            Q.push(temp->left);
        }
        if(temp->right) {
            Q.push(temp->right);
        }
    }

    if(temp != NULL && toDel != NULL) {
        toDel->data = temp->data;
        Node* par = findParent(root, temp);
        if(par != NULL) {
            if(par->right)
                par->right = NULL;
            else
                par->left = NULL;
            delete temp;
        }        
    }
    return root;
}
int main() {
    Node *root = NULL;

    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 7);
    root = insert(root, 8);
    root = insert(root, 9);
    root = insert(root, 10);
    root = insert(root, 11);
    root = insert(root, 12);
    root = insert(root, 13);
    root = insert(root, 14);
    root = insert(root, 15);
    root = del(root, 11);
    root = del(root, 12);
    root = del(root, 13);
    root = del(root, 14);
    root = del(root, 15);
    levelorder(root); cout<<endl;
    cout<< height(root) <<endl;
    // inorder(root);
    return 0;
}