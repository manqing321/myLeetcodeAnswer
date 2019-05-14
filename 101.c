#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct TreeNode {
	int val;
	struct TreeNode* leftChild;
	struct TreeNode* rightChild;
} TreeNode;

void showBinaryTree(struct TreeNode* top);
void showtree(struct TreeNode* tree);
int isSymmetric(struct TreeNode* root);
int isMirror(struct TreeNode* left,struct TreeNode* right);

int main(int argc, char *argv[]) {

	printf("Ok here we building a binary tree like this :\n");
	printf("================\n");
	printf("         A     \n");
	printf("       /  \\    \n");
	printf("      B    C   \n");
	printf("     / \\  / \\  \n");
	printf("    D  E  F  G \n");
	printf("================\n");
	printf("Ok lets begins\n");
	TreeNode a,b,c,d,e,f,g;
	printf("pls entry the val of A:");
	scanf("%d",&a.val);
	a.leftChild=&b;
	a.rightChild=&c;

	printf("pls entry the val of B:");
	scanf("%d",&b.val);
	b.leftChild=&d;
	b.rightChild=&e;
	printf("pls entry the val of C:");
	scanf("%d",&c.val);
	c.leftChild=&f;
	c.rightChild=&g;

	printf("pls entry the val of D:");
	scanf("%d",&d.val);	
		d.leftChild=NULL;
		d.rightChild=NULL;
	printf("pls entry the val of E:");
	scanf("%d",&e.val);
	e.leftChild=NULL;
	e.rightChild=NULL;
	printf("pls entry the val of F:");
	scanf("%d",&f.val);
	f.leftChild=NULL;
	f.rightChild=NULL;
	printf("pls entry the val of G:");
	scanf("%d",&g.val);
	g.leftChild=NULL;
	g.rightChild=NULL;
	printf("Congratulations.Your binary has be builded.\n");
	printf("         %d     \n",a.val);
	printf("       /  \\    \n");
	printf("      %d    %d   \n",b.val,c.val);
	printf("     / \\  / \\  \n");
	printf("    %d  %d  %d  %d \n",d.val,e.val,f.val,g.val);
	printf("here it is.\n");
	//void showBinaryTree(a);
	printf("前序遍历:  "); 
	showBeforeTree(&a); 
	printf("\n"); 
	printf("中序遍历:  "); 
	showMinTree(&a); 
	printf("\n"); 
	printf("后序遍历:  "); 
	showAfterTree(&a); 
	/*
	int result=(isSymmetric(&a));
	printf("the result is %d",result);
	*/
	
	return 0;
}
int isSymmetric(struct TreeNode* root) {
	return isMirror(root->leftChild,root->rightChild);
}

int isMirror(struct TreeNode* left,struct TreeNode* right) {
	if(NULL==left && NULL==right)
		return 1;
	else if(NULL==left || NULL==right)
		return 0;
	else {
		if(left->val!=right->val)
			return 0;
		else
			return (isMirror(left->leftChild,right->rightChild) && isMirror(left->rightChild,right->leftChild));
	}
}




void showMinTree(struct TreeNode* top) {
	//遍历方式 中序遍历
	if(NULL!=top){
	showMinTree(top->leftChild);
    printf(" %d",top->val); 
    showMinTree(top->rightChild);
	}
}

void showBeforeTree(struct TreeNode* tree) {
	//遍历方式 前序遍历
	if(NULL!=tree){
	printf(" %d",tree->val); 
	showBeforeTree(tree->leftChild);
    showBeforeTree(tree->rightChild);
	}
}

void showAfterTree(struct TreeNode* tree){
	if(NULL!=tree){
	showAfterTree(tree->leftChild);
    showAfterTree(tree->rightChild);    
	printf(" %d",tree->val); 
	}
}






