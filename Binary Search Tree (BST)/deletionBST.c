// Given a BST, the task is to delete a node in this BST, which can be broken down into 3 scenarios:

// Case 1. Delete a Leaf Node in BST
// Case 2. Delete a Node with Single Child in BST
// Deleting a single child node is also simple in BST. Copy the child to the node and delete the node. 
// Case 3. Delete a Node with Both Children in BST
// Deleting a node with both children is not so simple. Here we have to delete the node is such a way, that the resulting tree follows the 
// properties of a BST.  
// The trick is to find the inorder successor of the node. Copy contents of the inorder successor to the node, and delete the inorder successor.

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

/* Given a binary search tree and a key, this function
   deletes the key and returns the new root */
Node* deleteNode(Node* root, int k){
    // Base case
    if (root == NULL){
        return root;
    }

    // Recursive calls for ancestors of
    // node to be deleted
    if (root->data > k){
        root->left = deleteNode(root->left, k);
        return root;
    }
    else if (root->data <k){
        root->right = deleteNode(root->right, k);
    }

    // We reach here when root is the node
    // to be deleted.
    // If one of the children is empty
    if (root->left == NULL){
        Node* temp = root->right;
        free(root);
        return temp;
    }
    else if (root->right == NULL){
        Node* temp = root->left;
        free(root);
        return temp;
    }

    // If both children exist
    else{
        Node* succParent = root;
        // Find successor
        Node* succ = root->right;

        while(succ->left != NULL){
            succParent = succ;
            succ = succ->left;
        }

        // Delete successor.  Since successor
        // is always left child of its parent
        // we can safely make successor's right
        // right child as left of its parent.
        // If there is no succ, then assign
        // succ->right to succParent->right
        if (succParent != root){
            succParent->left = succ->right;
        }
        else{
            succParent->right = succ->right;
            }
        // Copy Successor Data to root
        root->data = succ->data;
        // Delete Successor and return root
        free(succ);
        return root;
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
    printf("\n");

    printf("Which element you want to delete: ");
    scanf("%d",&ele);
    deleteNode(root, ele);

    printf("The inorder traversal is as follows:\n");
    inorder(root);

    return 0;
}

// Time Complexity: O(h), where h is the height of the BST. 
// Auxiliary Space: O(n).