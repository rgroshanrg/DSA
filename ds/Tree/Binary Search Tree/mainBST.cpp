#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

Node* insert(int x, Node *root) {
    if(root == NULL) {
        root = new Node;
        root->data = x;
        root->left = root->right = NULL;
    }
    // if(x == root->data)
    //     return NULL;
    else if(x < root->data)
        root->left = insert(x, root->left);
    else if(x > root->data)
        root->right = insert(x, root->right);
    return root;
}

Node* insert_iterative(int x, Node *root) {
    Node *newNode = new Node;
    newNode->data = x;
    newNode->left = newNode->right = NULL;
    if(root == NULL) {
        root = newNode;
        return root;
    }
    Node *temp = root;
    Node *temp1 = NULL;
    bool left;
    while(temp != NULL) {
        temp1 = temp;
        if(x < temp->data) {
            temp = temp->left;
            left = true;
        } else if(x > temp->data) {
            temp = temp->right;
            left = false;
        } else {
            return root;
        }
    }
    if(left) {
        temp1->left = newNode;
    } else {
        temp1->right = newNode;
    }
    return root;
}

Node* maxNode(Node *root) {
    if(root->right == NULL)
        return root;
    return maxNode(root->right);
}

Node* minNode(Node *root) {
    if(root->left == NULL)
        return root;
    return minNode(root->left);
}

int height(Node *root) {
    if(root == NULL)
        return -1;
    int left_height = height(root->left);
    int right_height = height(root->right);
    if(left_height > right_height) {
        return left_height+1;
    } else {
        return right_height+1;
    }
}
Node* findNode(Node* root, int x) {
    if(root == NULL) {
        return root;
    }
    // Node* temp = NULL;
    if(root->data == x)
        return root;
    if(x < root->data)
        return findNode(root->left, x);
    if(x > root->data)
        return findNode(root->right, x);
}

struct tt {
    Node* node;
    bool isLeft;
};
tt findPrevNode(Node* root, int x) {
    tt *p = new tt;
    p->node = NULL;
    if(root == NULL)
        return *p;
    if(root->left->data == x) {
        p->isLeft = true;
        p->node = root;
        return *p;
    }
    if(root->right->data == x) {
        p->isLeft = false;
        p->node = root;
        return *p;
    }
    
}
void deleteNode(Node* root, int x) {
    Node *deletingNode = findNode(root, x);
    Node* temp = NULL;
    if(deletingNode->left) {
        temp = maxNode(deletingNode->left);
    } else if(deletingNode->right) {
        temp = minNode(deletingNode->right);
    } else {
        temp = deletingNode;
    }
    deletingNode->data = temp->data;
    delete temp;
}

void inorder(Node *root) {
    if(root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void iterative_inorder(Node *root) {
    stack<Node*> Stack;
    Node* current = root;
    while(!Stack.empty() || current != NULL) {
        if(current != NULL) {
            Stack.push(current);
            current = current->left;
        } else {
            cout << Stack.top()->data << " ";
            current = Stack.top()->right;
            Stack.pop();
        }
    }
}

void preorder(Node *root) {
    if(root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void iterative_preorder(Node* root) {
    stack<Node*> Stack;
    Node* current = root;
    Stack.push(current);
    while(!Stack.empty()) {
        current = Stack.top();
        cout << current->data << " ";
        Stack.pop();
        if(current->right != NULL) {
            Stack.push(current->right);
        }
        if(current->left != NULL) {
            Stack.push(current->left);
        }        
    }
}

void postorder(Node *root) {
    if(root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    Node *root = NULL;

    int n = 10;
    // while(n--) {
        root = insert_iterative(5, root);
        root = insert_iterative(1, root);
        root = insert_iterative(6, root);
        root = insert_iterative(8, root);
        root = insert_iterative(2, root);
        root = insert_iterative(9, root);
        root = insert_iterative(0, root);
        root = insert_iterative(3, root);
    // }
    // iterative_preorder(root);
    // inorder(root);
    // cout<<endl;
    preorder(root);
    cout << endl;
    deleteNode(root, 6);
    iterative_preorder(root);
    // cout << findNode(root,1)->data;
    // cout << findNode(root,5)->data;
    // cout << findNode(root,6)->data;
    // cout << findNode(root,9)->data;
    // cout << findNode(root,3)->data;
    // inorder(root);
    // cout << "\n" << maxNode(root)->data;
    // cout << "\nHeight: " << height(root);

    return 0;
}