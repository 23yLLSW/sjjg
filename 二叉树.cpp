#include<stdio.h>
#include<malloc.h>
#include<string.h>
typedef struct tree {
	char id;
	struct tree* l;
	tree* r;
}tree;

void creat(tree *r,char *data,int*i)
{
	char ch;
	ch = *(data+*i);
	*i+=1;
	if (ch == '#')
	{
		r = NULL; 
	}
	else
	{
		tree* r = (tree*)malloc(sizeof(tree));
		((r)->id) = ch;
		creat(((r)->l),data,i);
		creat(((r)->r), data, i);
	}
}
void out(tree* root)
{
	while (root != NULL)
	{
		printf("%c\n", root->id);
		out(root->l);
		out(root->r);
	}
}
void main()
{
	char date[] = { 'a','b','#','c','#'};
	char* p = date;
	int i = 0;
	tree* head;
	head = (tree*)malloc(sizeof(tree));
	creat(head,date,&i);
	out(head);
}
