/*
    有m元钱，n种物品；每种物品有j磅，总价值f元，可以使用0到f的任意价格购买相应磅的物。求m元钱最多能买多少磅物品
*/

#include <stdio.h>
#include <algorithm>
using namespace std;

struct goods {
    double j;   //重量
    double f;   //价值
    double s;   //性价比
    bool operator < (const goods &A) const {    //重载小于运算符，使数组按性价比降序排列
        return s > A.s;
    }
}buf[1000];

int main(){
    double m;   //有m元钱
    int n;  //有n种物品
    while(scanf("%lf%d", &m, &n) != EOF){
        if(m == -1 && n == -1) break;
        for(int i=0; i<n; i++){
            scanf("%lf%lf", &buf[i].j, &buf[i].f);
            buf[i].s = buf[i].j / buf[i].f; //计算性价比
        }
        sort(buf, buf + n); //按性价比排序
        int idx = 0;    //当前货物下标
        double ans = 0; //累积总重量
        while(m>0 && idx<n){    //钱和物还剩有
            if(m > buf[idx].f){ //能买下全部
                ans += buf[idx].j;
                m -= buf[idx].f;
            }   
            else {  //能买下部分
                ans += buf[idx].j * m / buf[idx].f;
                m = 0;
            }
            idx++;
        }
        printf("%.3lf\n", ans);
    }
    return 0;
}

//背包问题，贪心法，按性价比排列一个一个买