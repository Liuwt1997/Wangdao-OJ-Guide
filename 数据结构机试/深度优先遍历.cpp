//邻接矩阵

#include <cstdio>

#define MAX_VERTEX_NUM 100  //邻接矩阵中最大的顶点数目
#define INF 9999999 //顶点不可达
int n, Ggrph[MAX_VERTEX_NUM][MAX_VERTEX_NUM] = {
    {0, 1, INF, 1},
    {INF, 0, 1, INF},
    {INF, INF, 0, INF},
    {INF, INF, INF, 0},
};
bool isVisited[100] = {false};   //访问标记数组

//从顶点v开始DFS
void DFS(int v, int deep){
    isVisited[v] = true;
    printf("%d\n", v);
    for(int i=0; i<n; i++){
        if(Ggrph[v][i] != INF && isVisited[i] == false){
            DFS(i, deep+1); //递归
        }
    }
}

//对整个图DFS，非连通的点也被访问到
void DFSTraverse(){
    for(int v=0; v<n; v++){
        if(isVisited[v] == false){
            DFS(v, 1);
        }
    }
}

int main(){
    n = 4;
    DFSTraverse();
}