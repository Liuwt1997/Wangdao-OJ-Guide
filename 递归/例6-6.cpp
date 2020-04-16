/*
    在给定的n*m图中，确定有几个符合以下条件的@块：其中的任意对@均直接或间接连通，两个@直接相邻或对角相邻则被视为连通
*/

#include <stdio.h>
char maze[101][101];    //地图信息
bool mark[101][101];    //图上每一个点设立一个状态
int n, m;   //地图大小n*m
int go[][2] = {1, 0, -1, 0, 0, 1, 0, -1,
1, 1, 1, -1, -1, -1, -1, 1};    //八个相邻点与当前位置的坐标差
void DFS(int x, int y){ //遍历所有与x, y直接或间接相邻的@
    for(int i=0; i<8; i++){ //遍历八个相邻点
        int nx = x + go[i][0];
        int ny = y + go[i][1];
        if(nx < 1 || nx > n || ny < 1 || ny > m)    //坐标在地图外
            continue;   
        if(maze[nx][ny] == '*')
            continue;
        if(mark[nx][ny] == true)    //坐标已经被计算过
            continue;
        mark[nx][ny] = true;
        DFS(nx, ny);    //递归查询相邻点
    }
    return;
}
int main(){
    while(scanf("%d%d", &n, &m) != EOF){
        if(n == 0 && m == 0)
            break;
        for(int i=1; i<=n; i++){
            scanf("%s", maze[i] + 1);
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                mark[i][j] = false;
            }
        }
        int ans = 0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(mark[i][j] == true)
                    continue;
                if(maze[i][j] == '*')
                    continue;
                DFS(i, j);
                ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

//图的遍历