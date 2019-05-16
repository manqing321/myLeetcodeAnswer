#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int isPalindrome(char * s);

int main(int argc, char *argv[]) {
	char* s=(char*)malloc(100*sizeof(char));
	printf("pls entry your string(limited 100 word): ");
	//scanf("%s",s);
	printf("\n\n\n");
	char* s2="0P";
	printf("%s\n",s2);
	if(isPalindrome(s2))
		printf("true");
	else
		printf("false");
	free(s);
	return 0;
}


int isPalindrome(char * s) {
	//±ß½ç
	if(NULL==s)
		return 0;
	int len=strlen(s);
	char *p=(char*)malloc((len+1)*sizeof(char));
	int i=0;
	int j=0;
	while(i<len){
		if(s[i]>47 && s[i]<58)
		{
			p[j]=s[i];
			j++;
		}else if(s[i]>64 && s[i]<91)
		{
			p[j]=s[i];
			j++;
		}else if(s[i]>96 && s[i]<123)
		{
			p[j]=s[i]-32;
			j++;
		}
	    i++;
	}
	p[j]='\0';
	/*
	printf("s is %s \n",s);
	printf("p is %s \n",p);
	*/
	int plen=strlen(p);
	int right=plen-1;
	int left=0;
	while(left<right)
	{
		if(p[left]!=p[right])
		    return 0;
		left++;
		right--;
	}	 	
	free(p);
	return 1;
	//1 - true   0 - false
}


