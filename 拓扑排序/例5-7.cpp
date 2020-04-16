/*
    判断该图是否为有向无环图
*/

#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
vector<int> edge[501];
queue<int> Q;   //保存入度为0的结点
int main(){
    int inDegree[501];  //统计每个结点的入度
    int n, m;
    while(scanf("%d%d", &n, &m) != EOF){
        if(n == 0 && m == 0)
            break;
        for(int i=0; i<n; i++){
            inDegree[i] = 0;
            edge[i].clear();
        }
        while(m--){
            int a, b;
            scanf("%d%d", &a, &b);  //a指向b的有向边
            inDegree[b]++;  //b的入度增加
            edge[a].push_back(b);   //b加入a的邻接链表
        }
        while(Q.empty() == false)
            Q.pop();
        for(int i=0; i<n; i++)
            if(inDegree[i] == 0)
                Q.push(i);
        int cnt = 0;
        while(Q.empty() == false){
            int nowP = Q.front();
            Q.pop();
            cnt++;
            for(int i=0; i<edge[nowP].size(); i++){ //将该结点以及其指向的所有边去除
                inDegree[edge[nowP][i]]--;  //去除某边后，该边所指后继结点入度减一
                if(inDegree[edge[nowP][i]] == 0)
                    Q.push(edge[nowP][i]);  //若入度变为0则加入到队列中
            }
        }
        if(cnt == n)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}

//拓扑排序