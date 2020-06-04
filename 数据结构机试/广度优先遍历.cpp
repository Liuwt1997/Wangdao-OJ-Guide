//邻接矩阵

#include <cstdio>
#include <queue>
using namespace std;

#define MAX_VERTEX_NUM 100  //邻接矩阵中最大的顶点数目
#define INF 9999999 //顶点不可达
int n, Ggrph[MAX_VERTEX_NUM][MAX_VERTEX_NUM] = {
    {0, INF, 1},
    {INF, 0, 3},
    {INF, 1, 0},
};
bool isVisited[100] = {false};   //访问标记数组

void visit(int i){
    printf("i=%d\n", i);
}

//从顶点v出发进行BFS
void BFS(int v){
    queue<int> Q;
    Q.push(v);
    visit(v);
    isVisited[v] = true;
    while(!Q.empty()){
        int v = Q.front();  //取出队首元素
        Q.pop();
        for(int i=0; i<n; i++){ //遍历v的邻接点i
            if(isVisited[i] == false && Ggrph[v][i] != INF){
                Q.push(i);
                visit(i);
                isVisited[i] = true;
            }
        }
    }
}

//对图G进行BFS
void BFSTraverse(){
    for(int v=0; v<n; v++){
        if(isVisited[v] != true){   //顶点未访问过
            BFS(v);
        }
    }
}

int main(){
    n = 3;
    BFSTraverse();
}