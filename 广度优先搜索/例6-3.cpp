/*
    有两个杯子容量为N和M，可乐体积为S，S=N+M，三者之间相互倒（无刻度）。输出能平分时要倒的最少次数
*/

#include <stdio.h>
#include <queue>
using namespace std;
struct N{
    int a, b, c;
    int t;
};
queue<N> Q;
bool mark[101][010][101];
void AtoB(int &a, int sa, int &b, int sb){  //由容积为sa的杯子向sb的杯子倒可乐
    if(sb - b >= a){    //若a可以全部倒到b中
        b += a;
        a = 0;
    }
    else{
        a -= sb - b;
        b = sb;
    }
}
int BFS(int s, int n, int m){
    while(Q.empty() == false){
        N now = Q.front();
        Q.pop();
        int a, b, c;
        a = now.a;
        b = now.b;
        c = now.c;
        AtoB(a, s, b, n);   //a倒向b
        if(mark[a][b][c] == false){
            mark[a][b][c] = true;
            N tmp;
            tmp.a = a;
            tmp.b = b;
            tmp.c = c;
            tmp.t = now.t + 1;
            if(a == s/2 && b == s/2)
                return tmp.t;
            if(c == s/2 && b == s/2)
                return tmp.t;
            if(a == s/2 && c == s/2)
                return tmp.t;   //已经平分
            Q.push(tmp);
        }
        a = now.a;
        b = now.b;
        c = now.c;  //重置
        AtoB(b, n, a, s);   //b倒向a
        if(mark[a][b][c] == false){
            mark[a][b][c] = true;
            N tmp;
            tmp.a = a;
            tmp.b = b;
            tmp.c = c;
            tmp.t = now.t + 1;
            if(a == s/2 && b == s/2)
                return tmp.t;
            if(c == s/2 && b == s/2)
                return tmp.t;
            if(a == s/2 && c == s/2)
                return tmp.t;
            Q.push(tmp);
        }
        a = now.a;
        b = now.b;
        c = now.c;  //重置
        AtoB(a, s, c, m);   //a倒向c
        if(mark[a][b][c] == false){
            mark[a][b][c] = true;
            N tmp;
            tmp.a = a;
            tmp.b = b;
            tmp.c = c;
            tmp.t = now.t + 1;
            if(a == s/2 && b == s/2)
                return tmp.t;
            if(c == s/2 && b == s/2)
                return tmp.t;
            if(a == s/2 && c == s/2)
                return tmp.t;
            Q.push(tmp);
        }
        a = now.a;
        b = now.b;
        c = now.c;  //重置
        AtoB(c, m, a, s);   //c倒向a
        if(mark[a][b][c] == false){
            mark[a][b][c] = true;
            N tmp;
            tmp.a = a;
            tmp.b = b;
            tmp.c = c;
            tmp.t = now.t + 1;
            if(a == s/2 && b == s/2)
                return tmp.t;
            if(c == s/2 && b == s/2)
                return tmp.t;
            if(a == s/2 && c == s/2)
                return tmp.t;
            Q.push(tmp);
        }
        a = now.a;
        b = now.b;
        c = now.c;  //重置
        AtoB(b, n, c, m);   //b倒向c
        if(mark[a][b][c] == false){
            mark[a][b][c] = true;
            N tmp;
            tmp.a = a;
            tmp.b = b;
            tmp.c = c;
            tmp.t = now.t + 1;
            if(a == s/2 && b == s/2)
                return tmp.t;
            if(c == s/2 && b == s/2)
                return tmp.t;
            if(a == s/2 && c == s/2)
                return tmp.t;
            Q.push(tmp);
        }
        a = now.a;
        b = now.b;
        c = now.c;  //重置
        AtoB(c, m, b, n);   //c倒向b
        if(mark[a][b][c] == false){
            mark[a][b][c] = true;
            N tmp;
            tmp.a = a;
            tmp.b = b;
            tmp.c = c;
            tmp.t = now.t + 1;
            if(a == s/2 && b == s/2)
                return tmp.t;
            if(c == s/2 && b == s/2)
                return tmp.t;
            if(a == s/2 && c == s/2)
                return tmp.t;
            Q.push(tmp);
        }
    }
    return -1;
}
int main(){
    int s, n, m;
    while(scanf("%d%d%d", &s, &n, &m) != EOF){
        if(s == 0)
            break;
        if(s % 2 == 1){
            puts("NO");
            continue;
        }
        for(int i=0; i<=s; i++){
            for(int j=0; j<=n; j++){
                for(int k=0; k<=m; k++){
                    mark[i][j][k] = false;
                }
            }
        }
        N tmp;
        tmp.a = s;
        tmp.b = 0;
        tmp.c = 0;
        tmp.t = 0;
        while(Q.empty() == false)
            Q.pop();
        Q.push(tmp);
        mark[s][0][0] = true;
        int rec = BFS(s, n, m);
        if(rec == -1)
            puts("NO");
        else
            printf("%d\n", rec);
    }
    return 0;
}


//x, y, z表示三个瓶子中的可乐体积，t表示从初始状态到该状态所需的杯子间互相倾倒的次数；即转换为搜索到平分的状态

