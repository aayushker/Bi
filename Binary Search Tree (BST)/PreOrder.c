// Unlike linear data structures (Array, Linked List, Queues, Stacks, etc) which have only one logical way to traverse them, trees can be 
// traversed in different ways. 

// A Tree Data Structure can be traversed in following ways:

// Depth First Search or DFS
// Inorder Traversal
// Preorder Traversal
// Postorder Traversal

// Level Order Traversal or Breadth First Search or BFS
// Boundary Traversal
// Diagonal Traversal

// Algorithm Preorder(tree)

// Visit the root.
// Traverse the left subtree, i.e., call Preorder(left->subtree)
// Traverse the right subtree, i.e., call Preorder(right->subtree) 

// C program for different tree traversals
#include <stdio.h>
#include <stdlib.h>

// A binary tree node has data, pointer to left child
// and a pointer to right child
struct node {
	int data;
	struct node* left;
	struct node* right;
};

// Helper function that allocates a new node with the
// given data and NULL left and right pointers.
struct node* newNode(int data)
{
	struct node* node
		= (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

// Given a binary tree, print its nodes in preorder
void printPreorder(struct node* node)
{
	if (node == NULL)
		return;

	// First print data of node
	printf("%d ", node->data);

	// Then recur on left subtree
	printPreorder(node->left);

	// Now recur on right subtree
	printPreorder(node->right);
}

// Driver code
int main()
{
	struct node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	// Function call
	printf("Preorder traversal of binary tree is \n");
	printPreorder(root);

	getchar();
	return 0;
}

// Time Complexity: O(N)
// Auxiliary Space: If we don’t consider the size of the stack for function calls then O(1) otherwise O(h) where h is the height of the tree. 