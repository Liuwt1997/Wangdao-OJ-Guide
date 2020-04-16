/*
    叠筐
*/

#include <stdio.h>

int main(){
    int outPutBuf[82][82];  //缓存数组
    int n;
    char center, border;
    bool firstCase = true;  //是否为第一组数据
    while(scanf("%d %c %c", &n, &center, &border) == 3){
        if(firstCase == true){
            firstCase = false;  //第一组前面不输出换行，其余组前面均输出换行
        }
        else{
            printf("\n");
        }
        for(int i=1, j=1; i<=n; i+=2, j++){    //第j圈边长为i
            int x = n/2+1, y=x;
            x -= j - 1 ;y -= j - 1; //每圈右上角的坐标
            char c = j % 2 == 1 ? center : border;  //奇数用第一个字符，偶数用第二个字符
            for(int k=1; k<=i; k++){
                outPutBuf[x+k-1][y] = c;    //左侧
                outPutBuf[x][y+k-1] = c;    //上方
                outPutBuf[x+i-1][y+k-1] = c;    //右侧
                outPutBuf[x+k-1][y+i-1] = c;    //下方
            }
        }
        if(n != 1){
            outPutBuf[1][1] = ' ';
            outPutBuf[n][1] = ' ';
            outPutBuf[1][n] = ' ';
            outPutBuf[n][n] = ' ';
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                printf("%c", outPutBuf[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}

//先在数组上完成排版，再输出；注意输出格式换行；采用坐标定位；统一输出后再处理四个角