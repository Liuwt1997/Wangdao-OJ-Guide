/*
    输入N个学生的信息，然后进行查询
*/

#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;


struct Student
{
    char number[10];
    char name[20];
    char sex[5];
    int age;
};
Student student[1000];

int main(){
    int N, M;
    while(scanf("%d", &N) != EOF){
        for(int i=0; i<N; i++){
            scanf("%s %s %s %d", &student[i].number, &student[i].name, &student[i].sex, &student[i].age);
        }
        scanf("%d", &M);
        while(M-- != 0){
            int ans = -1;
            char x[30];
            scanf("%s", x);
            int low = 0, high = N-1;
            while(high >= low){
                int mid = (high + low) / 2;
                int temp = strcmp(student[mid].number, x);
                if(temp == 0){
                    ans = mid;
                    break;
                }
                else if (temp > 0)  high = mid -1;
                else    low = mid + 1;
            }
            if(ans == -1)   printf("No Answer!\n");
            else    printf("%s %s %s %d\n", student[ans].number, student[ans].name, student[ans].sex, student[ans].age);
        }
    }
    return 0;
}

//先排序后二分查找