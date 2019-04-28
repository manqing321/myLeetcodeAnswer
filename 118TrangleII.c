#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int* getRow(int rowIndex, int* returnSize);
int main(int argc, char *argv[]) {
	printf("\nplease entry the num of line(less than 33 ): ");
	int k;
	scanf("%d",&k);
	k++;
	//printf("\n%d",k);
	int result=0;
	int* p=getRow(k,&result);
	
	printf("this arr is ");
	int i;
	for(i=0;i<result;i++)
	{
		printf("\t%d",p[i]);
	}
	printf("\n\n");
	return 0;
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize){
    int i;
    int j;
    *returnSize=rowIndex;
    //printf("\n%d",rowIndex);
    int* p=(int*)malloc(rowIndex*(sizeof(int)));
    for(i=0;i<rowIndex;i++)
    {
    	for(j=i;j>=0;j--)
    	{
    		if(0==j||i==j)
    		    p[j]=1;
    		else
    		    p[j]+=p[j-1];
		}
	}
	return p;
}