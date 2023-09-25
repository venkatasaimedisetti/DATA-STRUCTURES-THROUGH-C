//BST - Insertion and searching
// Inorder,preorder,postorder
#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
		struct node *left;
		struct node *right;
};
typedef struct node Treenode;
Treenode *root = NULL;

void inorder(Treenode *root) {
	if (root != NULL) {
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}
/*void preorder(Treenode *root) {
	if (root != NULL) {
		inorder(root->left);
		printf("%d",root->data);
		inorder(root->right);
	}
}*/
Treenode *create_tree_node(int val) {
	Treenode *nn = (Treenode *)malloc(sizeof(Treenode));
	nn->data = val;
	nn->left = NULL;
	nn->right = NULL;
	return nn;
} 
void insert_bst(Treenode *nn) {
	if (root == NULL) {
		root = nn;
	}
	else {
		Treenode *temp = root;
		while(1) {
			if (nn->data == temp ->data) {
				printf("data already exists\n");
				break;
			}
			else if (nn->data > temp ->data) {
				if (temp -> right == NULL) {
					temp -> right =nn;
					break;
				}
				else {
					temp = temp ->right;
				}
			}
			else {
				if (temp -> left ==NULL) {
					temp->left = nn;
					break;
				}
				else {
					temp = temp ->left;
				}
			}
		}
	}
	
}
int main() {
	int ch;
	while(1) {
		printf("Enter \n1.insetion\n2.search\n3.Inorder\n4.preorder\n5.postorder ");
		scanf("%d",&ch);
		if (ch==1) {
			//insertion
			int val;
			printf("Enter a value for node:");
			scanf("%d",&val);
			Treenode *nn= create_tree_node(val);
			insert_bst(nn);
		}
		else if(ch==2) {
			//search
			int key;
			printf("Enter a key to find: ");
			scanf("%d",&key);
			
			
		}
		else if(ch==3) {
			//inorder
			inorder(root);
		}
		else if(ch==4) {
			//preorder
		}
		else if(ch==5) {
			//post order
		}
		else {
			break;
		}
	}
}

