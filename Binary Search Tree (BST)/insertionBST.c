// How to Insert a value in a Binary Search Tree:
// A new key is always inserted at the leaf by maintaining the property of the binary search tree. We start searching for a key from the root until we hit a leaf node. Once a leaf node is found, the new node is added as a child of the leaf node.
// The below steps are followed while we try to insert a node into a binary search tree:
// Check the value to be inserted (say X) with the value of the current node (say val) we are in:
// If X is less than val move to the left subtree.
// Otherwise, move to the right subtree.
// Once the leaf node is reached, insert X to its right or left based on the relation between X and the leaf node’s value.

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *left, *right;
}Node;

// A utility function to create a new BST node
Node* newNode(int item){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

// A utility function to insert
// a new node with given key in BST
Node* insert(Node* node, int key){
    // If the tree is empty, return a new node
    if (node == NULL){
        return newNode(key);
    }
    // Otherwise, recur down the tree
    else if (key < node->data){
        node->left = insert(node->left,key);
    }
    else if (key > node->data){
        node->right = insert(node->right,key);
    }
    // Return the (unchanged) node pointer
    return node;
}

// A utility function to do inorder traversal of BST
void inorder(Node* node){
    if (node != NULL){
        inorder(node->left);
        printf("%d ",node->data);
        inorder(node->right);
    }
}

int main(){
    printf("How many elements you want to enter in the BST: ");
    int n,ele;
    Node* root = NULL;
    scanf("%d",&n);
    printf("Enter the elements\n");
    while (n--){
        scanf("%d",&ele);
        root = insert(root, ele);
    }
    printf("The inorder traversal is as follows:\n");
    inorder(root);

    return 0;
}

// Time Complexity: 
// The worst-case time complexity of insert operations is O(h) where h is the height of the Binary Search Tree. 
// In the worst case, we may have to travel from the root to the deepest leaf node. 
// The height of a skewed tree may become n and the time complexity of insertion operation may become O(n). 

// Auxiliary Space: The auxiliary space complexity of insertion into a binary search tree is O(1)
