#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize);

int main(int argc, char *argv[]) {
	int k=0;
	scanf("%d",&k);
	printf("k is %d\n",k);
	int len=0;	
	int *p=getRow(k,&len);
	
	printf("The return arr is: ");
	int i=0;
	for(;i<len;i++)
	{
		printf("%d  ",p[i]);
	}
	printf("\n");
	return 0;
}

int* getRow(int rowIndex, int* returnSize){
	//边界判断 
    //位数判断
    *returnSize=rowIndex;
    int *p=(int*)malloc(rowIndex*(sizeof(int)));
    
    int half;
    if(rowIndex%2>0)
        half=rowIndex/2+1;
	else
	    half=rowIndex/2;
	//printf(" half is %d\n",half); 
	//均匀分布
	
	int i=0;
	for(;i<half;i++)
	{
		if(0==i)
		    p[i]=1;
		else if(15>i)
		    p[i]=p[i-1]*(rowIndex-i)/i;
		else
		    p[i]=(p[i-1]/i)*(rowIndex-i);
		//p[i]=i+1;
		//换成阶乘语句 
	}
	//后面取前面 
	
	for(;i<rowIndex;i++)
	{
		p[i]=p[rowIndex-i-1];
	}
	
	
	/*
	int i;
	int j;
	for(i=0;i <= rowIndex;i++)
        for(j = i;j >= 0;j--)
        {
            if(j == 0 || j == i)
                p[j] = 1;
            else
                p[j] = p[j] + p[j-1];
        }
	*/
	return p;
}





