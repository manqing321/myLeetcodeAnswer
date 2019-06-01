
bool canConstruct(char * ransomNote, char * magazine){
    //边界 两个字符串是否有 null
    //方法1 两层循环 O(n^2) O(1)
    //方法2  
    //int arr[26] 'a'+i 
    //遍历 s2 将 有的字符置为1
    //遍历 s1 arr[c-'a'] 如果是 1 continue 如果不是 false 遍历完 返回 true
    //O(1) O(1)
    //采用方法2
    
    /*
    ** 边界
    */
    if(ransomNote==NULL || magazine==NULL)
        return false;
    
    /*
    ** 生成字典数组 Dictionary
    */
    int i;
    int dictionaryArr[26];
    for(i=0;i<26;i++)
    {
        dictionaryArr[i]=0;
    }
    
    /*
    ** 将杂志字符串导入到字典中
    */
    int lenOfMagazine=strlen(magazine);
    for(i=0;i<lenOfMagazine;i++)
    {
        dictionaryArr[magazine[i]-'a']++;
    }
    
    /*
    ** 遍历赎金信 查询数组中是否存在赎金信中的字符
    */
    int lenOfRansomNote=strlen(ransomNote);
    for(i=0;i<lenOfRansomNote;i++)
    {
        dictionaryArr[ransomNote[i]-'a']--;
        if (dictionaryArr[ransomNote[i]-'a'] < 0)        
            return false; 
                      
    }
    return true;
}

