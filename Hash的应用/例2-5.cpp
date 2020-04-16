/*
    读入N名学生的成绩，将获得某一分数的学生人数输出
*/

#include <stdio.h>

int main(){
    int N;
    while(scanf("%d", &N) != EOF && N != 0){    //注意0边界
        int Hash[101] = {0};  
        for(int i=0; i<N; i++){
            int x;
            scanf("%d", &x);
            Hash[x]++;
        }
        int x;
        scanf("%d", &x);
        printf("%d\n", Hash[x]);
    }
    return 0;
}

//给有限的101种分数输入分别计数，与数组下标对应