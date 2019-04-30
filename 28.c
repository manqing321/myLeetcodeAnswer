#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int strStr(char* haystack, char* needle); 

int main(int argc, char *argv[]) {
	char* p=(char*)malloc(100*(sizeof(char)));
	char* q=(char*)malloc(100*(sizeof(char)));
	scanf("%s %s",p,q);
	int temp=strStr(p,q);
	printf("\n %d",temp);
	return 0;
}

int strStr(char* haystack, char* needle) {
    if(needle[0]=='\0')
        return 0;
    int i;
    int nlen=strlen(needle);
    int hlen=strlen(haystack);
    //printf("\n nlen=%d hlen=%d",nlen,hlen);
    for(i=0;i<hlen-nlen+1;i++)
    {
        if(haystack[i]==needle[0])
        {
            int j;
            for(j=0;j<nlen;j++)
            {
                //printf("\na %d %d",i,j);
                if(haystack[i+j]!=needle[j])
                {
                    //printf("\nb %c %c",haystack[i+j],needle[i]);
                    break;
                }                
            }
            //printf("\n i=%d, j=%d,nlen=%d",i,j,nlen);
            //printf("\nc j=%d nlen=%d %c %c",j,nlen,needle[j-1],haystack[i+j-1]);
            if(j==(nlen) && needle[j-1]==haystack[i+j-1] )
            {
                //printf("\n j=%d",j);
                return i;
            }
        }
    }
    return -1;
    
}
