#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int maxArea(int* height, int heightSize);
int main(int argc, char *argv[]) {
	int arr[]= {1,8,6,2,5,4,8,3,7};
	int len=9;
	int container=maxArea(arr, len);
	printf("%d\n",container);
	return 0;
}

int maxArea(int* height, int heightSize) {
	int maxS=0;
	//边界
	if(1>=heightSize) {
		return maxS;
	}

	/*
	//case 1 双层循环
	int i;
	int j;
	for(i=0;i<=heightSize-1;i++)
	{
		for(j=i+1;j<heightSize;j++)
		{
			int s=(j-i)*(height[i]>height[j]?height[j]:height[i]);
			if(s>maxS)
			    maxS=s;
		}
	}
	*/
	//case 2 调节
	//既然有更大的，肯定不能比远的柱子低
	int left=0;
	int right=heightSize-1;
	while(left<right) {
		//printf("1\n");
		int s=(right-left)*(height[left]<height[right]?height[left]:height[right]);
		//printf("%d %d\n",height[left],height[right]);
		if(s>maxS)
		{
			//printf("height[%d] %d * heigjt[%d] %d = %d\n",left,height[left],right,height[right],s);
				maxS=s;
		}		
		if(height[left]<=height[right]) {
			int temp=height[left];
			while(left<right) {
				//printf("2\n");
				if(height[left]<=temp)
					left++;
				else
					break;
			}
		} else {
			int temp=height[right];
			while(right>=left)
			{
				if(temp>=height[right])
				    right--;
				else
				    break;
			}			
		}
	}


	//最大面积
	return maxS;
}
