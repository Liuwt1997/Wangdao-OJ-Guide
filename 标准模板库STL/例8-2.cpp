/*
    如果A打败了B，B打败了C，那么认定A一定能打败C；如果A打败B，B打败C，C打败A，则无冠军。根据比赛结果判断是否产生了冠军
*/

#include <stdio.h>
#include <vector>
#include <map>
#include <string>
#include <queue>
using namespace std;
map<string, int> M; //从string到int映射
int in[2002];
int main(){
    int n;
    while(scanf("%d", &n) != EOF && n != 0){
        for(int i=0; i<2*n; i++){   
            in[i] = 0;  //初始化入度
        }
        M.clear();  //清空map中的映射关系
        int idx = 0;    //下一个被映射的数字
        for(int i=0; i<n; i++){
            char str1[50], str2[50];
            scanf("%s%s", str1, str2);  
            string a = str1, b = str2;  //两选手名称保存至string中
            int idxa, idxb;
            if(M.find(a) == M.end()){   //若map中没保存对a的映射则返回M.end()
                idxa = idx; //设定其映射为idx
                M[a] = idx++;   
            }
            else    idxa = M[a];    //直接读出该映射
            if(M.find(b) == M.end()){
                idxb = idx;
                M[b] = idx++;
            }
            else    idxb = M[b];
            in[idxb]++; //b的入度增加
        }
        int cnt = 0;
        for(int i=0; i<idx; i++){   //入度为0的个数
            if(in[i] == 0)
                cnt++;
        }
        puts(cnt == 1 ? "Yes" : "No");
    }
    return 0;
} 