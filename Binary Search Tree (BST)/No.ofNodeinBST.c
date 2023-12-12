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

int countNodes(struct node* root) {
    if (root == NULL)
        return 0;
    else
        return 1 + countNodes(root->left) + countNodes(root->right);
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
    printf("The total no. of nodes in BST are %d", countNodes(root));

    return 0;
}
