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

// Insert level order from array
struct Node* insertLevelOrder(int arr[], int i, int n) {
    struct Node* root = NULL;

    if (i < n) {
        root = createNode(arr[i]);
        root->left = insertLevelOrder(arr, 2 * i + 1, n);
        root->right = insertLevelOrder(arr, 2 * i + 2, n);
    }

    return root;
}

// Height of tree
int height(struct Node* root) {
    if (root == NULL)
        return -1;

    int leftH = height(root->left);
    int rightH = height(root->right);

    return (leftH > rightH ? leftH : rightH) + 1;
}

// Count total nodes
int countNodes(struct Node* root) {
    if (root == NULL)
        return 0;

    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Count leaf nodes
int countLeaves(struct Node* root) {
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return 1;

    return countLeaves(root->left) + countLeaves(root->right);
}

// Check if tree is balanced
int isBalanced(struct Node* root) {
    if (root == NULL)
        return 1;

    int leftH = height(root->left);
    int rightH = height(root->right);

    int diff = leftH - rightH;
    if (diff < 0) diff = -diff;

    if (diff > 1)
        return 0;

    return isBalanced(root->left) && isBalanced(root->right);
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
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements (level order):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = insertLevelOrder(arr, 0, n);

    printf("\nInorder Traversal: ");
    inorder(root);

    printf("\nHeight of Tree: %d", height(root));
    printf("\nTotal Nodes: %d", countNodes(root));
    printf("\nLeaf Nodes: %d", countLeaves(root));
    printf("\nIs Balanced: %s", isBalanced(root) ? "Yes" : "No");

    printf("\n");
    return 0;
}
