#include <iostream>
using namespace std;

struct Node {
    int val;
    int height;
    Node* left;
    Node* right;
};

Node* createNode(int val) {
    Node* newNode = new Node;
    newNode->val = val;
    newNode->height = 1;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int height(Node* node) {
    if (node == NULL) {
        return 0;
    }
    return node->height;
}

int balanceFactor(Node* node) {
    if (node == NULL) {
        return 0;
    }
    return height(node->left) - height(node->right);
}

void updateHeight(Node* node) {
    node->height = 1 + max(height(node->left), height(node->right));
}

Node* rotateLeft(Node* node) {
    Node* rightChild = node->right;
    Node* rightLeftChild = rightChild->left;
    rightChild->left = node;
    node->right = rightLeftChild;
    updateHeight(node);
    updateHeight(rightChild);
    return rightChild;
}

Node* rotateRight(Node* node) {
    Node* leftChild = node->left;
    Node* leftRightChild = leftChild->right;
    leftChild->right = node;
    node->left = leftRightChild;
    updateHeight(node);
    updateHeight(leftChild);
    return leftChild;
}

Node* balance(Node* node) {
    if (node == NULL) {
        return node;
    }
    updateHeight(node);
    int bf = balanceFactor(node);
    if (bf > 1) {
        if (balanceFactor(node->left) < 0) {
            node->left = rotateLeft(node->left);
        }
        return rotateRight(node);
    }
    if (bf < -1) {
        if (balanceFactor(node->right) > 0) {
            node->right = rotateRight(node->right);
        }
        return rotateLeft(node);
    }
    return node;
}

Node* insert(Node* node, int val) {
    if (node == NULL) {
        return createNode(val);
    }
    if (val < node->val) {
        node->left = insert(node->left, val);
    }
    else if (val > node->val) {
        node->right = insert(node->right, val);
    }
    return balance(node);
}

void preOrderTraversal(Node* node) {
    if (node == NULL) {
        return;
    }
    cout << node->val << " ";
    preOrderTraversal(node->left);
    preOrderTraversal(node->right);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        Node* root = NULL;
        for (int i = 0; i < N; i++) {
            int val;
            cin >> val;
            root = insert(root, val);
        }
        preOrderTraversal(root);
        cout << endl;
    }
    return 0;
}

