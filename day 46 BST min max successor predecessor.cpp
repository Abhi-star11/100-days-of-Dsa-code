#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert into BST
struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Find minimum
struct Node* findMin(struct Node* root) {
    while (root && root->left)
        root = root->left;
    return root;
}

// Find maximum
struct Node* findMax(struct Node* root) {
    while (root && root->right)
        root = root->right;
    return root;
}

// Find Inorder Successor
struct Node* inorderSuccessor(struct Node* root, int key) {
    struct Node* successor = NULL;

    while (root != NULL) {
        if (key < root->data) {
            successor = root;
            root = root->left;
        }
        else if (key > root->data) {
            root = root->right;
        }
        else {
            // If right subtree exists, successor is min of right subtree
            if (root->right != NULL)
                return findMin(root->right);
            break;
        }
    }

    return successor;
}

// Find Inorder Predecessor
struct Node* inorderPredecessor(struct Node* root, int key) {
    struct Node* predecessor = NULL;

    while (root != NULL) {
        if (key > root->data) {
            predecessor = root;
            root = root->right;
        }
        else if (key < root->data) {
            root = root->left;
        }
        else {
            // If left subtree exists, predecessor is max of left subtree
            if (root->left != NULL)
                return findMax(root->left);
            break;
        }
    }

    return predecessor;
}

// Inorder display
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    int n = 7;

    // Build BST
    for (int i = 0; i < n; i++) {
        root = insert(root, values[i]);
    }

    printf("BST Inorder: ");
    inorder(root);
    printf("\n");

    printf("Min value: %d\n", findMin(root)->data);
    printf("Max value: %d\n", findMax(root)->data);

    int key;
    printf("\nEnter a value to find successor/predecessor: ");
    scanf("%d", &key);

    struct Node* succ = inorderSuccessor(root, key);
    struct Node* pred = inorderPredecessor(root, key);

    if (succ)
        printf("Inorder Successor of %d: %d\n", key, succ->data);
    else
        printf("No Inorder Successor for %d\n", key);

    if (pred)
        printf("Inorder Predecessor of %d: %d\n", key, pred->data);
    else
        printf("No Inorder Predecessor for %d\n", key);

    return 0;
}
