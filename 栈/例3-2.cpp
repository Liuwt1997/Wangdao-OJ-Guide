/*
    简单计算器：读入一个只包含加减乘除的非负整数计算表达式，计算该表达式的值
*/

#include <stdio.h>
#include <stack>
using namespace std;

char str[201];  //表达式字符串
int mat[][5] = {    //优先级矩阵，若mat[i][j] == 1，则表示i号运算符优先级大于j号
    1,0,0,0,0,  //人为添加在表达式首尾的标记
    1,0,0,0,0,  //加
    1,0,0,0,0,  //减
    1,1,1,0,0,  //乘
    1,1,1,0,0,  //除
};
stack<int> op;  //运算符栈
stack<double> in;   //数栈
void getOp(bool &reto, int &retn, int &i){  //获得表达式中下一个元素，i为遍历到的字符串下标
    if(i==0 && op.empty() == true){ //遍历字符串第一个字符，且运算符栈为空，人为添加标记
        reto = true;    //为运算符
        retn = 0;   //编号为0
        return;
    }
    if(str[i]==0){  //字符串被遍历完，人为添加标记
        reto = true;
        retn = 0;   
        return;
    }
    if(str[i]>='0' && str[i]<='9'){
        reto = false;   //为数字
        retn = 0;   //为数字
        for(;str[i]!=' '&&str[i]!=0; i++){  //计算该数字的值
            retn *= 10;
            retn += str[i] - '0';
        }
        if(str[i] == ' '){
            i++;    //跳过空格   
            return ;
        }
    }
    else{
        reto = true;
        if(str[i] == '+')   retn = 1; 
        else if(str[i] == '-')  retn = 2; 
        else if(str[i] == '*')  retn = 3; 
        else if(str[i] == '/')  retn = 4; 
        i+=2;   //跳过该运算字符和字符后的空格
        return;
    }
    return ;

}

int main(){
    while(gets(str)){
        if(str[0] == '0' && str[1] == 0)    break;  //输入0退出
        bool retop;
        int retnum;
        int idx = 0;    //遍历到的字符串下标
        while(!op.empty())  op.pop();   //清空运算符栈
        while(!in.empty())  in.pop();   //清空数栈
        while(true){
            getOp(retop, retnum, idx);
            if(retop == false){ //该元素为数字
                in.push((double)retnum);
            }
            else{
                double tmp;
                if(op.empty() == true || mat[retnum][op.top()] == 1){ //运算符栈为空或当前运算符优先级大于栈顶运算符
                    op.push(retnum);
                }
                else{
                    while(mat[retnum][op.top()] == 0){
                        int ret = op.top(); //保存栈顶运算符
                        op.pop();
                        double b = in.top();
                        in.pop();
                        double a = in.top();
                        in.pop();   
                        if(ret == 1)    tmp = a + b;
                        else if(ret == 2)    tmp = a - b;
                        else if(ret == 3)    tmp = a * b;
                        else tmp = a / b;
                        in.push(tmp);
                    }
                    op.push(retnum);
                }
            }
            if(op.size() == 2 && op.top() == 0) break;
        }
        printf("%.2f\n", in.top());
    }
    return 0;
}

//用栈计算表达式