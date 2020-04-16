/*
    括号匹配 
*/

#include<stdio.h>
#include<stack>
using namespace std;

stack<int> S; 
char str[110];  //保存输入字符串
char ans[110];  //保存输出字符串

int main() {
    while(scanf("%s",str)!=EOF) {
        int i;
        for(i=0; str[i]!=0; i++) {
            if(str[i]=='(') {
                S.push(i);        
                ans[i]=' ';      
            }
            else if(str[i]==')') {
                if(S.empty()==false) {  //堆栈非空
                    S.pop();      //弹出栈顶匹配的左括号
                    ans[i]=' ';   
                }
                else ans[i]='?';   //堆栈为空，无匹配的左括号
            }
            else ans[i]=' ';
        }
        while(!S.empty()) {  //字符串遍历完成，留在堆栈中的左括号无法匹配
            ans[S.top()]='$';  //修改其在输出位置中的位置为'$'
            S.pop();           
        }
        ans[i]='\0'; //为了使输出形成字符串，在其最后一个字符后添加一个空字符
        puts(str);//输出原字符串
        puts(ans);//输出答案字符串
    }
    return 0;
}