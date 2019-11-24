#include <stdio.h>
#include <stdlib.h>

int number = 0;

typedef struct BiNode {
	char data;
	struct BiNode * LChild;	
	struct BiNode * RChild;	
}*BiTree;

void createBiTree(BiTree * root) {
	char ch;
	ch = getchar();
	if(ch == '#') {
		* root = NULL;
	} else {
		* root = (BiTree) malloc (sizeof(struct BiNode));
		(* root)->data = ch;
		createBiTree(&((* root)->LChild));
		createBiTree(&((* root)->RChild));
	}
}

int getHeight(BiTree root)
{
	int hl,hr,h;
	if(root)
	{
		hl = getHeight(root->LChild);
		hr = getHeight(root->RChild);
		h = (hr>hl?hr:hl)+1;
		return h;
	}
	else
		return 0;
}

void preOrder(BiTree root) {
	if(root) {
		printf("%c" , root->data);
		preOrder(root->LChild);
		preOrder(root->RChild);
	}
}

void inOrder(BiTree root) {
	if(root) {
		inOrder(root->LChild);
		printf("%c" , root->data);
		inOrder(root->RChild);
	}
}

void postOrder(BiTree root) {
	if(root) {
		postOrder(root->LChild);
		postOrder(root->RChild);
		printf("%c" , root->data);
	}
}

void getNum(BiTree root)
{
	if(!root) return;
	if(root->LChild || root->RChild) 
		number += 1;
	getNum(root->LChild);
	getNum(root->RChild);
}

int main() {
	BiTree root;
	createBiTree(&root);
//	preOrder(root);
//	printf("\n");
//	inOrder(root);
//	printf("\n");
//	postOrder(root);
//	printf("%d" , getHeight(root));
	getNum(root);
	printf("%d" , number);
}
