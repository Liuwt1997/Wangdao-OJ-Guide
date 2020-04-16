/*
    求任意两个不同进制非负整数的转换
*/

#include <stdio.h>
#include <string.h>
int main(){
    int a, b;
    char str[40];
    while(scanf("%d%s%d", &a, str, &b) != EOF){
        int temp = 0, length = strlen(str), c = 1;  //temp：a进制对应的十进制数，c：各个数位的权重，最低为1，之后每位都是前一位的a倍
        for(int i = length - 1; i >= 0; i--){   //从低位到高位遍历每个数位上的数
            int x;
            if(str[i] >= '0' && str[i] <= '9')
                x = str[i] - '0';   //字符在0~9之间
            else if(str[i] >= 'a' && str[i] <= 'z')
                x = str[i] - 'a' + 10;  //字符为小写字母
            else 
                x = str[i] - 'A' + 10; //字符为大写字母
            temp += x * c;
            c *= a;
        }
        char ans[40], size = 0; //ans：转换到b进制的各个数位数字
        do{
            int x = temp % b;
            ans[size++] = (x<10) ? x + '0' : x - 10 + 'A';
            temp /= b;
        }while(temp);
        for(int i = size - 1; i>=0; i--)
            printf("%c", ans[i]);
        printf("\n");
    }
    return 0;
}

//先将a进制转换为十进制，再将得到的十进制数转换成b进制