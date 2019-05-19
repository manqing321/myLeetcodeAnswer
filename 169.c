#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int majorityElement(int* nums, int numsSize);
int main(int argc, char *argv[]) {
	int arr[]= {2,2,1,1,1,2,2};
	printf(" %d ",majorityElement(arr,7));
	return 0;
}

int majorityElement(int* nums, int numsSize) {
	
	int result;
	int count;
	int i;

	result=nums[0];
	count=1;

	for(i=1; i<numsSize; i++) {
		if(result==nums[i])
			count++;
		else {
			count--;
		}
		if(count<=0)
		{
			result=nums[i];
			count=1;
		}
	}
	
    return result;
}


/*
int majorityElement(int* nums, int numsSize){
	//第二版 使用双数组

	int i;
	int j;
	int numIndex;
	int countIndex;
	int arrNum[(numsSize+1)/2];
	int arrCount[(numsSize+1)/2];

	numIndex=0;
	countIndex=0;

	for(i=0;i<numsSize;i++)
	{
		j=0;
		while(j<numIndex)
		{
			if(arrNum[j]!=nums[i])
				j++;
			else
			{
				arrNum[j]++;
				break;
			}
		}
		if(j==numIndex)
		{
			arrNum[numIndex]=nums[i];
			arrCount[countIndex]=1;
			numIndex+=1;
			countIndex+=1;
		}
	}

	int max=0;
	int returnIndex=0;
	for(j=0;j<countIndex;j++)
	{
		if(max<arrCount[j])
		{
			max=arrCount[j];
			returnIndex=j;
		}
	}
	int temp=0;
	for(;temp<countIndex;temp++)
	{
		printf("\n 显示 %d %d %d \n",temp,arrNum[temp],arrCount[temp]);
	}
	return arrNum[returnIndex];
}
*/

/* 第一版
int majorityElement(int* nums, int numsSize){

    int i;
    int j;
    int count;
    int halflen;

	halflen=numsSize/2;

    for(i=0;i<numsSize;i++)
    {
    	count=0;
    	for(j=0;j<numsSize;j++)
    	{
    		if(nums[i]==nums[j])
    			count++;
			if(count>=halflen)
			{
				return nums[i];
			}
		}
	}
	return 0;
}
*/


