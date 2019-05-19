
void reverseString(char* s, int sSize){
    if(sSize<=1)
        return;
    
    int left=0;
    char temp;
    int right=sSize-1;
    
    while(left<right)
    {
        if(s[left]!=s[right]){            
            temp=s[left];
            s[left]=s[right];
            s[right]=temp;
        }
        left++;
        right--;
    }
    
}


