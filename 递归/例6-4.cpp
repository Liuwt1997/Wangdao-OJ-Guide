/*
    汉诺塔变形：每次移动一定是移到中间杆或从中间杆移出，而不允许最左右两边互相移动
*/

#include <stdio.h>
#include <string.h>
long long F(int num){
    if(num == 1)
        return 2;
    else
        return 3 * F(num - 1) + 2;
}
int main(){
    int n;
    while(scanf("%d", &n) != EOF)
        printf("%lld\n", F(n));
    return 0;
}

