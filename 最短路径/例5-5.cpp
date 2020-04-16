/*
    最短路径
*/
/*
//Floyd算法
#include <stdio.h>
int ans[101][101];  
int main(){
    int n, m;
    while(scanf("%d%d", &n, &m) != EOF){
        if(n == 0 && m == 0)
            break;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++)
                ans[i][j] = -1;
            ans[i][i] = 0;
        }
        while(m--){
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            ans[a][b] = ans[b][a] = c;  //无向图
        }
        for(int k=1; k<=n; k++){    //允许经过的中间节点编号小于等于k
            for(int i=1; i<=n; i++){
                for(int j=1; j<=n; j++){
                    if(ans[i][k] == -1 || ans[k][j] == -1)
                        continue;   //值为无穷则跳过
                    if(ans[i][j] == -1 || ans[i][k] + ans[k][j] < ans[i][j])
                        ans[i][j] = ans[i][k] + ans[k][j];  //更新值
                }
            }
        }
        printf("%d\n", ans[1][n]);
    }
    return 0;
}
*/

//Dijstra算法
#include <stdio.h>
#include <vector>
using namespace std;
struct E{   //邻接链表
    int next;
    int c;
};
vector<E> edge[101];
bool mark[101]; //标记该节点最短路径已经得到，该节点已经加入集合
int Dis[101];   //距离

int main(){
    int n, m;
    while(scanf("%d%d", &n, &m) != EOF){
        if(n==0 && m==0)
            break;
        for(int i=1; i<=n; i++)
            edge[i].clear();
        while(m--){
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            E tmp;
            tmp.c = c;
            tmp.next = b;
            edge[a].push_back(tmp);
            tmp.next = a;
            edge[b].push_back(tmp); //加入邻接链表，无向图每条边有两个顶点都要加入
        }
        for(int i=1; i<=n; i++){
            Dis[i] = -1;    //初始不可达
            mark[i] = false;    //结点不加入
        }
        Dis[1] = 0; 
        mark[1] = true; //最近结点加入集合，长度为0
        int newP = 1;   //新加入的结点
        for(int i=1; i<n; i++){
            for(int j=0; j<edge[newP].size(); j++){ //遍历与该新加入集合中的结点直接相邻的边
                int t = edge[newP][j].next; //该边的另一个结点
                int c = edge[newP][j].c;
                if(mark[t] == true)
                    continue;   //若另一个结点属于集合则跳过
                if(Dis[t] == -1 || Dis[t] > Dis[newP] + c)
                    Dis[t] = Dis[newP] + c;
            }
            int min = 123131123;
            for(int j=1; j<=n; j++){
                if(mark[j] == true)
                    continue;
                if(Dis[j] == -1)
                    continue;
                if(Dis[j] < min){
                    min = Dis[j];
                    newP = j;
                }
            }
            mark[newP] = true;
        }
        printf("%d\n", Dis[n]);
    }
    return 0;
}


