#include <stdio.h>

void rotate(int* nums, int numsSize, int k);
void swap(int *a,int *b);
void changeArr(int *nums, int numsSize);
void rotateMin(int *p,int startIndex,int endIndex);

int main(void) {
	int arr[]= {1,2,3,4,5,6,7};
	int i;
	printf("before:");
	for(i=0; i<sizeof(arr)/sizeof(*arr); i++) {
		printf("%d ",arr[i]);
	}
	int k=3;
	rotate(arr, 7, k);
	printf("\nafter: ");
	for(i=0; i<sizeof(arr)/sizeof(*arr); i++) {
		printf("%d ",arr[i]);
	}
	return 0;
}


void rotate(int* nums, int numsSize, int k) {
	/*
	** 输入：数组和目标位数
	** 输出；
	** 边界：nums null numSize<0 k<0 如果k>numsSize?
	** 空间复杂度O(1)
	*/

	/*
	**边界
	*/
	if(NULL==nums)
		return;
	if(numsSize<=1 || k<=0)
		return;
	if(k>=numsSize)
		k=k%numsSize;

	/*
	** 1 前后指针法 0和numsSize-k交换
	*/
	/*
	int left=0;
	int right=numsSize-k;
	for(;left<k;left++,right++)
	{
	    if(nums[right]!=nums[left])
	        swap(&nums[right],&nums[left]);
	}
	*/
	/* 
	** 2 写个旋转函数 旋转K次
	*/ 
	/*
	int time;
	for(time=0; time<k; time++) {
		changeArr(nums,numsSize);
	}
	*/
	/* 
	** 跳跃交换值
	*/ 
	rotateMin(nums,0,numsSize-k-1);
	rotateMin(nums,numsSize-k,numsSize-1);
	rotateMin(nums,0,numsSize-1);
}

/*
** 交换两个值
*/
void swap(int *a,int *b) {
	*a+=*b;
	*b=*a-*b;
	*a=*a-*b;
}

void changeArr(int *nums, int numsSize) {
	int tmp=nums[numsSize-1];
	int i;
	for(i=numsSize-1; i>0; i--) {
		nums[i]=nums[i-1];
	}
	nums[0]=tmp;
}

void rotateMin(int *p,int startIndex,int endIndex)
{
	while(startIndex < endIndex)
	{
		p[startIndex]+=p[endIndex];
		p[endIndex]=p[startIndex]-p[endIndex];
		p[startIndex]=p[startIndex]-p[endIndex];
		startIndex++;
		endIndex--;
	}
}
