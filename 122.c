#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int maxProfit(int* prices, int pricesSize);
int main(int argc, char *argv[]) {
	int a[]= {1,9,9,6,9,1,7,1,1,5,9,9,9};
	printf("%d",maxProfit(a,13));
	return 0;
}

int maxProfit(int* prices, int pricesSize) {
	if(NULL==prices ||2>pricesSize )
		return 0;
	int i=1;
	int result;
	while(i<pricesSize) {
		if(prices[i]>prices[i-1])//有增加就加起来 
			result+=(prices[i]-prices[i-1]);
		i++;
	}
	return result;
}
/*
int maxProfit(int* prices, int pricesSize) {
	if(pricesSize<2)
		return 0;
	int i;
	int diff=0;
	int min=-1;
	for(i=0; i<pricesSize; i++) {
		if(i<pricesSize-1) {
			if(prices[i]<prices[i+1]) { //递增
				if(min==-1) {
					min=prices[i];
				}
			} else if(prices[i]>=prices[i+1]) {
				if(min!=-1) {
					diff+=(prices[i]-min);
					min=-1;
				}
			}

		} else {
			if(i==pricesSize-1) {
				if(prices[i]>prices[i-1]) {
					diff+=(prices[i]-min);
				}
			}
		}
	}
	return diff;
}
*/


