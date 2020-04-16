/*
    给定一个短字符串（不含空格，再给定若干字符串，在这些字符串中删除所含有的短字符串）
*/

#include <stdio.h>
#include <string>
#include <iostream>
#include <ctype.h>
using namespace std;

int main(){
    char str[101];
    gets(str);  //输入短字符串 
    string a = str;
    for(int i=0; i<a.size(); i++){
        a[i] = tolower(a[i]);   //将a中的字符全部改成小写
    }
    while(gets(str)){   //输入长字符串
        string b = str, c = b;
        for(int i=0; i<b.size(); i++){
            b[i] = tolower(b[i]);
        }
        int t = b.find(a, 0);   //在b中查找a的位置
        while(t != string::npos){   //若查找成功则重复循环
            c.erase(t, a.size());   //原串
            b.erase(t, a.size());   //改小写后的串
            t = b.find(a, t);   //查找b中下一个出现字符串a的位置
        }
        t = c.find(' ', 0); //查找c中空格
        while(t != string::npos){   //删除c中所有空格
            c.erase(t, 1);
            t = c.find(' ', 0);
        }   
        cout << c << endl;
    }
    return 0;
}