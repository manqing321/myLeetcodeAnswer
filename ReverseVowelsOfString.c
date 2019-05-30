
char * reverseVowels(char * s){
    int len=strlen(s);
    //printf("%d",len);
    int left=0;
    int right=len-1;
    char tmp;
    while(left<right)
    {
        while(left<=len-1 && 0==isAEIOU(s[left]))
        {
            left++;
        }
        while(right>=0 && 0==isAEIOU(s[right]))            
        {
            right--;
        }
        //printf("left %d %c\tright %d %c\n",left,s[left],right,s[right]);
        if(left>=right)
            return s;
        else{
            tmp=s[left];
            s[left]=s[right];
            s[right]=tmp;
            
            left++;
            right--;
        }     
    }    
    return s;
}
int isAEIOU(int c){
    switch(c){
        case 'a':
        case 'A':
        case 'e':
        case 'E':
        case 'i':
        case 'I':
        case 'o':
        case 'O':
        case 'u':
        case 'U':
            return 1;
            break;
        default:
            return 0;
            break;  
    }
    return 0;
}


