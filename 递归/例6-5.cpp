/*
    由给定的1到n数字中，将数字依次填入环中，使得环中任意两个相邻的数字间的和为素数。对于给定的n，按字典序由小到大输出所有符合条件的解(1<n<17)
*/

#include <stdio.h>
#include <string.h>
int ans[22];    //保存环中放入的数
bool hash[22];  //标记已经被放入环中的数
int n;
int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};
bool judge(int x){  //判断是否为素数
    for(int i=0; i<13; i++){
        if(prime[i] == x)
            return true;
    }
    return false;
}
void check(){
    if(judge(ans[n] + ans[1]) == false) //判断最后一个数与第一个数的和是否为素数，若不是则返回
        return;
    for(int i=1; i<=n; i++){    //输出解
        if(i != 1)
            printf(" ");
        printf("%d", ans[i]);
    }
    printf("\n");
}
void DFS(int num){  //num为当前已经放入环中的数字
    if(num > 1)
        if(judge(ans[num] + ans[num - 1]) == false)
            return; //最后两数字的和是否为素数，不是则继续枚举
    if(num == n){   //已经放入n个数
        check();
        return;
    }
    for(int i=2; i<=n; i++){    //把数放入环中
        if(hash[i] == false){   //若i没有被放入环中
            hash[i] = true;
            ans[num + 1] = i;
            DFS(num + 1);
            hash[i] = false;
        }
    }
}
int main(){
    int cas = 0;
    while(scanf("%d", &n) != EOF){
        cas++;
        for(int i=0; i<22; i++)
            hash[i] = false;
        ans[1] = 1;
        printf("Case %d:\n", cas);
        hash[1] = true;
        DFS(1);
        printf("\n");
    }
    return 0;
}

//回溯枚举
