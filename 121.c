#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int maxProfit(int* prices, int pricesSize);


int main(int argc, char *argv[]) {
	int arr[]= {7,1,5,3,6,4};
	printf("%d\n",maxProfit(arr,6));
	return 0;
}
/*
int maxProfit(int* prices, int pricesSize) {
	int left=0;
	int right=pricesSize-1;
	int max=0;
	int temp=0;
	while(left<right) {
		while( left<right && prices[left]>=prices[left+1] )
			left++;
		if(left==right)
			return 0;
		while(right>left&&prices[right]<=prices[right-1])
			right--;
		//printf("left=%d prices[%d]=%d right=%d prices[%d]=%d\n",left,left,prices[left],right,right,prices[right]);
		temp=prices[right]-prices[left];
		if(right>left&& temp>max  )
			max=temp;
		if(right>left && (prices[left+1]-prices[left])>(prices[right]-prices[right-1]))
			right--;
		else
			left++;
		if((right-left)<=1)
		{
			while(left>0)
			{
				int temp=prices[right]-prices[left];
				if(temp>max)
				    max=temp;
				left--;
			}
			while(right<pricesSize)
			{
				int temp=prices[right]-prices[left];
				if(temp>max)
				    max=temp;
				right++;
			}
			break;
		}
	}
	return max;
}
*/

/*
int maxProfit(int* prices, int pricesSize){
    int i;
    int j;
    int max=0;
    for(i=0;i<pricesSize-1;i++)
    {
    	for(j=i+1;j<pricesSize;j++)
    	{
    		int temp=prices[j]-prices[i];
    		if(temp>max)
    		    max=temp;
		}
	}
    return max;
}
*/
int maxProfit(int* prices, int pricesSize) {
	if(pricesSize==1)
		return prices[0];
	else if(pricesSize==0)
		return 0;
	int min=0;
	int max=0;
	int result=0;
	int i=1;
	if(prices[0]<prices[1]) {
		max=prices[1];
		min=prices[0];
		result=max-min;
	} else
		min=max=prices[1];
	for(; i<pricesSize; i++) {
		
		if(prices[i]>max) {
			max=prices[i];
			result=max-min;
		} 
		
		if(prices[i]<min)
			min=prices[i];
	}
	return result;
}




