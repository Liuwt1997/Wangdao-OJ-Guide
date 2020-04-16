/*
    实现一个加法器，使其能够输出a+b的值（a和b的数位不超过1000位）
*/

#include <stdio.h>
#include <string.h>
struct bigInteger{
    int digit[1000];    //四位数为一个单位保存数值
    int size;   //下一个未使用的数组单元
    void init(){
        for(int i=0; i<1000; i++)
            digit[i] = 0;
        size = 0;
    }
    void set(char str[]){   //从字符串中提取整数
        init();
        int L = strlen(str);
        for(int i=L-1, j=0, t=0, c=1; i>=0; i--){   //j：每四位数为一个单位保存 t：临时保存 c：数位权值
            t += (str[i] - '0') * c;    //当前数字*权重
            j++;    //下一位数字
            c *= 10; //下一位权重
            if(i == 0 || j == 4){    //每四位或者到了最后一个字符
                digit[size++] = t;
                j = 0;
                t = 0;
                c = 1;
            }
        }
    }
    void output(){  //输出高精度整数
        for(int i=size-1; i>=0; i--){
            if(i != size - 1)   
                printf("%04d", digit[i]);   //不是最高位数字，前面补充0
            else 
                printf("%d", digit[i]);
        }
        printf("\n");
    }
    bigInteger operator + (const bigInteger &A) const {
        bigInteger ret;
        ret.init();
        int carry = 0;
        for(int i = 0; i < A.size || i < size; i++){
            int tmp = A.digit[i] + digit[i] + carry;    //计算两个整数当前位及来自低位的进位和
            carry = tmp / 10000;
            tmp %= 10000;
            ret.digit[ret.size++] = tmp;
        }
        if(carry != 0)
            ret.digit[ret.size++] = carry;
        return ret;
    }
}a, b, c;

char str1[1002], str2[1002];
int main(){
    while(scanf("%s%s", str1, str2) != EOF){
        a.set(str1);
        b.set(str2);
        c = a + b;
        c.output();
    }
    return 0;
}

//高精度加法：拆开各位数，从低位开始各位相加并加上来自低位的进位
