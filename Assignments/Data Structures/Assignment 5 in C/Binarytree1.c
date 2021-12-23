#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct tree {
	int info;
	struct tree *left;
	struct tree *right;
};
struct tree *insert(struct tree *root, int x) 
{

	if(!root) {
		root=(struct tree*)malloc(sizeof(struct tree));
		root->info = x;
		root->left = NULL;
		root->right = NULL;
		return(root);
	}
	if(root->info > x)
	     root->left = insert(root->left,x); 
		 else {
		if(root->info < x)
			root->right = insert(root->right,x);
	}
	return(root);
}
void delete_tree(struct tree *ptr)
{
	if(ptr)
	{
		delete_tree(ptr->left);
		delete_tree(ptr->right);
		free(ptr);
	}
}
void inorder(struct tree *root) {
	if(root != NULL) {
		inorder(root->left);
		printf(" %d",root->info);
		inorder(root->right);
		return;
	}
	return;
	
	
}
void postorder(struct tree *root) {
	if(root != NULL) {
		postorder(root->left);
		postorder(root->right);
		printf(" %d",root->info);
		
	}
	return;
	
}
void preorder(struct tree *root) {
	if(root != NULL) {
		printf(" %d",root->info);
		preorder(root->left);
		preorder(root->right);
	}
	return;
	
	
}
int main() {
	struct tree *root;
	int choice,data,item_no;
	root = NULL;
	while(1)
	{
		    printf("\n Menu\n");
			printf("\n \t 1. Insert");
			printf("\n\t 2. Delete");
			printf("\n\t 3. Inorder traversal");
			printf("\n\t 4. Postorder traversal");
			printf("\n\t 5. Preorder traversal");
			printf("\n\t 6. Exit ");
			printf("\n\t Enter choice ");
			scanf(" %d",&choice);
			if(choice<1 || choice>5)
				break;
			switch(choice) {
			case 1:
		    printf("\n Enter data  ");
			scanf("%d", &data);
			root= insert(root,data);
			printf("\n root is %d",root->info);
			break;
			case 2:
			delete_tree(root);
			break;
			case 3:
			printf("\n Inorder traversal of binary tree: ");
			inorder(root);
			break;
			case 4:
			printf("\n Postorder traversal of binary tree: ");
			postorder(root);
			break;
			case 5:
		    printf("\n Preorder traversal of binary tree: ");
			preorder(root);
			
    	}
	}
}
