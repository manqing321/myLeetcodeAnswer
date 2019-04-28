#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int isValid(char * s);
int main(int argc, char *argv[]) {
	char*s=(char*)malloc(100*(sizeof(char)));
	printf("Enter your string limit 100 bit: ");
	scanf("%s",s);
	printf("\n");
	printf("%s is %d",s,isValid(s));

	return 0;
}
int isValid(char * s) {
	int len=strlen(s);
	int sum=0;
	int i=0;
	for(; i<len; i++) {
		if(('('==s[i] && ')'==s[i+1])||( '['==s[i]&&']'==s[i+1] )||('{'==s[i]&&'}'==s[i+1])) {
			int k=i;
			printf("%d",i);
			for(; k<len-2; k++)
				s[k]=s[k+2];
			//s[k+1]='\0';
			len-=2;
			s[len]='\0';
			i=-1;
		}
	}
	if(len==0)
		return 1;
	else return 0;

}


