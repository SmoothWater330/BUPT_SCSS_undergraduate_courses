/*
设计函数int getVowel(char str[],char vowel[])，将只包含小写字母的字符串str中的元音字母“a”“e”“i”“o”“u”复制到字符数组vowel，并返回字符串vowel的长度。

输入样例：
abcdefghiijklmn

输出样例：
4 aeii
*/

int getVowel(char str[],char vowel[])
{
    int len=0;
    for(int i=0;str[i]!='\0';i++)
    {
        if(str[i]=='a'
            ||str[i]=='e'
            ||str[i]=='i'
            ||str[i]=='o'
            ||str[i]=='u')
        {
            vowel[len]=str[i];
            len++;
        }
    }
    vowel[len]='\0';

    return len;
}
