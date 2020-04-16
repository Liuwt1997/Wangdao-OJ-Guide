/*
    节目有开始和结束时间，目标是看尽量多的完整节目
*/

#include <stdio.h>
#include <algorithm>
using namespace std;

struct program {
    int startTime;
    int endTime;
    bool operator < (const program & A) const {
        return endTime < A.endTime;
    }
}buf[100];

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        if(n==0) break;
        for(int i=0; i<n; i++){
            scanf("%d%d", &buf[i].startTime, &buf[i].endTime);
        }
        sort(buf, buf+n);   //按结束时间升序排列
        int currentTime = 0, ans = 0;   //当前时间、节目数
        for(int i=0; i<n; i++){
            if(currentTime <= buf[i].startTime){    //当前时间小于该节目开始时间，则收看
                currentTime = buf[i].endTime;   //收看完毕，当前时间变为结束时间
                ans ++; 
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

//每次都选结束时间最早的节目