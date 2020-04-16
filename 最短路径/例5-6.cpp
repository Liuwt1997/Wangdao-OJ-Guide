/*
    给n个点，m条无向边，每条边都有长度d和花费p。给起点s终点t，要求输出起点到终点的最短距离及其花费，如果最短距离有多条路线则输出花费最少的
*/

#include <stdio.h>
#include <vector>
using namespace std;
struct E{
    int next;
    int c;
    int cost;
};
vector<E> edge[1001];
int Dis[1001];
int cost[1001];
bool mark[1001];
int main(){
    int n, m;
    int S, T;
    while(scanf("%d%d", &n, &m) != EOF){
        if(n==0 && m==0)
            break;
        for(int i=1; i<=n; i++)
            edge[i].clear();
        while(m--){
            int a, b, c, cost;
            scanf("%d%d%d%d", &a, &b, &c, &cost);
            E tmp;
            tmp.c = c;
            tmp.cost = cost;
            tmp.next = b;
            edge[a].push_back(tmp);
            tmp.next = a;
            edge[b].push_back(tmp);
        }
        scanf("%d%d", &S, &T);
        for(int i=1; i<=n; i++){
            Dis[i] = -1;
            mark[i] = false;
        }
        Dis[S] = 0;
        mark[S] = true;
        int newP = S;
        for(int i=1; i<n; i++){
            for(int j=0; j<edge[newP].size(); j++){
                int t = edge[newP][j].next;
                int c = edge[newP][j].c;
                int co = edge[newP][j].cost;
                if(mark[t] == true)
                    continue;
                if(Dis[t] == -1 || Dis[t] > Dis[newP] + c || Dis[t] == Dis[newP] + c && cost[t] > cost[newP] + co){
                    Dis[t] = Dis[newP] + c;
                    cost[t] = cost[newP] + co;
                }
            }
            int min = 123122111;
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
        printf("%d %d\n", Dis[T], cost[T]);
    }
}


//更改Dijstra算法中最近的标准