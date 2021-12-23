#include<stdio.h>
#include<stdlib.h>
struct node  
{
	struct node* left;
	struct node* right;
	int data;
};
struct stack 
{
	struct node* data;
	struct stack* next;
};

void push(struct stack** top,struct node* n); 
struct node* pop(struct stack** top);
int isEmpty(struct stack* top);

int tree_traversal(struct node* root) 
{ 
	struct node* temp = root;
	struct stack* s_temp = NULL;
	int flag = 1;
	while(flag) 
	{
		if(temp){
			printf("%4d",temp->data);
                        push(&s_temp,temp);
			temp = temp->left;
		}
		else{
			if(!isEmpty(s_temp)){
				temp = pop(&s_temp);
				temp = temp->right;
			}
			else
				flag = 0;
		}
	 } 
}
void push(struct stack** top,struct node* n) 
{
	struct stack* new_n = (struct stack*)malloc(sizeof(struct stack));
	new_n->data = n;
	new_n->next = (*top);
	(*top) = new_n;
}
int isEmpty(struct stack* top) 
{
	if(top==NULL)
		return 1;
	else
		return 0;
}
struct node* pop(struct stack** top_n) 
{
	struct node* item;
	struct stack* top;
	top = *top_n;
	item = top->data;
	*top_n = top->next;
	free(top);
	return item;
}
struct node* create_node(int data) 
{
	struct node* new_n = (struct node*)malloc(sizeof(struct node));
	new_n->data = data;
	new_n->left = NULL;
	new_n->right = NULL;
	return (new_n);
}

int main() 
{
	struct node* root;
	root = create_node(8);
	root->left = create_node(5);
	root->right = create_node(4);
	root->left->left = create_node(7);
	root->left->right = create_node(6);
	printf("\n Preorder traversal is:");
	tree_traversal(root); 
	return 0;
}
