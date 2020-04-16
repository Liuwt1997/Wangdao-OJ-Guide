/*
    有一个N*M的迷宫，起点S，终点D，墙X。0秒时主人公从S出发，每秒能走到四个与其相邻位置中的一个，且每个位置被行走之后都不能再次走入，问是否存在这样一条路径使主人公在T秒时刚好走到D
*/

#include <stdio.h>
char maze[8][8];    //地图信息
int n, m, t;    //地图大小为n*m，从起点到终点能否恰好t秒
bool success;   //是否找到所需状态
int go[][2] = {1, 0, -1, 0, 0, 1, 0, -1};   //四方向行走
void DFS(int x, int y, int time){
    for(int i=0; i<4; i++){
        int nx = x + go[i][0];
        int ny = y + go[i][1];
        if(nx < 1 || nx > n || ny < 1 || ny > m)
            continue;
        if(maze[nx][ny] == 'X')
            continue;
        if(maze[nx][ny] == 'D'){
            if(time + 1 == t){  //所用时间恰好为t
                success = true;
                return;
            }
            else
                continue;
        }
        maze[nx][ny] = 'X'; //由该状态扩展的后续状态中该位置都不能被经过
        DFS(nx, ny, time + 1);
        maze[nx][ny] = '.';
        if(success)
            return;
    }
}

int main(){
    while(scanf("%d%d%d", &n, &m, &t) != EOF){
        if(n == 0 && m == 0 && t == 0)
            break;
        for(int i=1; i<=n; i++){
            scanf("%s", maze[i] + 1);
        }
        success = false;
        int sx, sy;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(maze[i][j] == 'D'){
                    sx = i;
                    sy = j;
                }
            }
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(maze[i][j] == 'S' && (i+j) % 2 == ((sx + sy) % 2 + t % 2) % 2){  //判断奇偶
                    maze[i][j] = 'X';
                    DFS(i, j, 0);
                }
            }
        }
        puts(success == true ? "YES" : "NO");
    }
    return 0;
}