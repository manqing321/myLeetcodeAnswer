#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize);

int main(int argc, char *argv[]) {
	int len;
	int i;
	int target;
	int returnSize;
	int* p;
	printf("pls enter your arr len: ");
	scanf("%d",&len);
	int* arr=(int*)malloc(len*sizeof(int));
	printf("\npls enter your arr: ");
	for(i=0; i<len; i++) {
		scanf("%d",&arr[i]);
	}
	printf("this is origin arr: ");
	for(i=0; i<len; i++) {
		printf("%d  ",arr[i]);
	}
	printf("\n");
	printf("pls enter your target: ");
	scanf("%d",&target);
	printf("\n");

	//printf("f\n");
	p=twoSum(arr, len,  target,  &returnSize);
	//printf("d\n");
	if(1<returnSize) {
		printf("this answer is :");
		for(i=0; i<returnSize; i++) {
			printf(" %d ",p[i]);
		}
		printf("\n");
	}
	return 0;
}

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) 
{
	*returnSize=0;
	if(2>numbersSize)
		return NULL;
	int* p=malloc(2*sizeof(int));
	int left=0;
	int right= numbersSize-1;
	while(left<right && (numbers[left]+numbers[right])!=target)
		(numbers[left]+numbers[right])>target?right--:left++;
	if((numbers[left]+numbers[right])==target)
	{		
	*returnSize=2;
	p[0]=left+1;
	p[1]=right+1;		
	}
	return p;
} 
/* 
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
	if(2>numbersSize) {
		*returnSize=0;
		return NULL;
	}
	int* p=(int*)malloc(2*sizeof(int));
	int i;
	int j;
	for(i=0; i<numbersSize-1; i++) {
		for(j=i+1; j<numbersSize; j++) {
			if((numbers[i]+numbers[j])==target) {
				//printf("a\n");
				p[0]=i;
				p[1]=j;
				*returnSize=2;
				//printf("e\n");
				return p;
			} else if((numbers[i]+numbers[j])>target) {
				//printf("b\n");
				numbersSize=j;
				break;
			}
		}
	}
	*returnSize=0;
	return NULL;
}
*/ 


