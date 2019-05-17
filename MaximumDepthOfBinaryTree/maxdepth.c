#include <stdio.h>
#include <stdlib.h>
#include "TreeNode.h"

int maxDepth(struct TreeNode* root){
	//printf("maxDepth is \n"); 
	int result=1;
    return getdeep(result,root);
}

int getdeep(int depth,struct TreeNode *tree){
	//printf("getdeep is %d\n",depth); 
    if(tree!=NULL)
        depth+=1;
    else return depth;    
    return max(getdeep(depth,tree->right),getdeep(depth,tree->left));
}

int max(int a,int b)
{
	return a>b?a:b;
}
