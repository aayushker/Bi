#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

int findLevel(struct Node* root, int key, int level) {
    if (root == NULL) {
        return -1;
    }
    if (root->data == key) {
        return level;
    }
    int leftLevel = findLevel(root->left, key, level + 1);
    if (leftLevel != -1) {
        return leftLevel;
    }
    int rightLevel = findLevel(root->right, key, level + 1);
    return rightLevel;
}

int main() {
    struct Node* root = NULL;
    int key, level;
    
    // Insert nodes into the BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    
    printf("Enter the key to find its level: ");
    scanf("%d", &key);
    
    level = findLevel(root, key, 0);
    if (level == -1) {
        printf("Key not found in the BST!\n");
    } else {
        printf("Level of the key in the BST: %d\n", level);
    }
    
    return 0;
}
