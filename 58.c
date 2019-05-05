#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int lengthOfLastWord(char * s);

int main(int argc, char *argv[]) {
	char* p="this is for test ";
	printf("%s\n",p);
	printf("%d",lengthOfLastWord(p));
	return 0;
}

int lengthOfLastWord(char * s){    
    int len=strlen(s);
    if(len==0)
        return 0;
    int i=len-1;
    while(i>=0 && ' '==s[i]){
        i--;
    }
    len=i+1;
    while(i>=0 && ' '!=s[i])
    {
        i--;
    }
    /*
    for(;i>=0;i--)
    {
        
        if(' '==s[i])
            break;
    }
    */
    return len-1-i;
    
}


