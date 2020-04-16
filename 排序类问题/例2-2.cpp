/*
    N个学生按成绩高低排序，成绩相同按姓名字母序排序，姓名字母序相同按年龄排序，并输出排序后的信息
*/

#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

struct student{
    char name[100];
    int age;
    int grade;
    //重载运算符
    /*  bool operator < (const student & s) const{
            if(grade != s.grade){return grade < b.grade;}
            if(strcmp(name, s.name) != 0){return strcmp(name, s.name) < 0;} //strcmp判断两字符串是否相同
            return age < s.age;}
    */
};

bool cmp(student a, student b){
    if(a.grade != b.grade){return a.grade < b.grade;}
    if(strcmp(a.name, b.name) != 0){return strcmp(a.name, b.name) < 0;} //strcmp判断两字符串是否相同
    return a.age < b.age;
}

int main(){
    int N;
    student S[1000];
    while(scanf("%d", &N)!=EOF){
        for(int i=0; i<N; i++){
            scanf("%s %d %d", &S[i].name, &S[i].age, &S[i].grade);
        }
        //sort(S, S+N);
        sort(S, S+N, cmp);
        for(int i=0; i<N; i++){
            printf("%s %d %d\n", S[i].name, S[i].age, S[i].grade);
        }
    }
    return 0;
}

//重载sort函数，对结构体排序