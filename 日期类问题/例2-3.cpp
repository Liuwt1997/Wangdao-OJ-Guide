/*
    求两日期之间的天数
*/

#include <stdio.h>
#define ISYEAP(x) x%100!=0 && x%4==0 || x%400==0 ? 1 : 0    //定义宏判断闰年

int dayOfMonth[13][2] = {
    0,0,
    31,31,
    28,29,
    31,31,
    30,30,
    31,31,
    30,30,
    31,31,
    31,31,
    30,30,
    31,31,
    30,30,
    31,31
};  //预存每月的天数

struct Date{
    int Day;
    int Month;
    int Year;
    void nextDay(){ //计算下一天日期
        Day++;
        if(Day > dayOfMonth[Month][ ISYEAP(Year) ]){    //进入下一月
            Day = 1;
            Month++;
            if(Month > 12){ //进入下一年
                Month = 1;
                Year++;
            }
        }
    }
};

int temp[10001][13][32];    //保留与原点时间所差天数，大内存空间在函数体外定义
int Abs(int x){ //求绝对值
    return x<0 ? -x : x;
}

int main(){
    Date day;
    int count = 0;  //天数计算
    day.Day = 1;
    day.Month = 1;
    day.Year = 0;   //原点时间为0年1月1日
    while(day.Year != 10000){   //预处理，保存所有日期与原点时间的天数差
        temp[day.Year][day.Month][day.Day] = count;
        day.nextDay();
        count ++;  
    }
    int d1, m1, y1, d2, m2, y2;
    while(scanf("%4d%2d%2d", &y1, &m1, &d1) != EOF){    //拆分scanf输入
        scanf("%4d%2d%2d", &y2, &m2, &d2);
        printf("%d\n", Abs(temp[y2][m2][d2] - temp[y1][m1][d1] + 1));
    }
    return 0;
}


//与某一原点时间做差来计算天数，定义宏判断闰年