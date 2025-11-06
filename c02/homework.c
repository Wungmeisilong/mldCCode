#if 0
#include <stdio.h>
//定义三个学生结构体（姓名、身高、体重）数组，键盘录入学生信息，并输出身高最高的学生全部信息
typedef struct Student{
    char name[20];
    int height;
    int weight;
    struct Student *Next;
}Std;
void input(Std *std, int count)
{
    for(int i = 0;i < count;i++)
    {
        printf("请输入第%d个学生的姓名：",i+1);
        scanf("%s",std[i].name);
        printf("请输入第%d个学生的身高：",i+1);
        scanf("%d",&std[i].height);
        printf("请输入第%d个学生的体重：",i+1);
        scanf("%d",&std[i].weight);      
    }
    return ;
}
void printStd(Std *std, int count)
{
    for(int i = 0;i < count;i++)
    {
        printf("第%d个学生的姓名：%s，身高：%d，体重：%d\n",i+1,std[i].name,std[i].height,std[i].weight);    
    }
}

int findMaxHeight(const Std *p,int count)
{
    int maxHeight = p->height;
    int index = 0;
    for(int i = 1;i < count;i++)
    {
        if(p[i].height >= maxHeight) 
        {
            maxHeight = p[i].height;
            index = i;
        }
    }
    return index;
}
int main()
{
    Std std[3];
    int count = sizeof(std) / sizeof(Std);
    input(std,count);
    printStd(std,count);
    int index = findMaxHeight(std,count);
    printf("身高最高的学生是：%s，身高：%d，体重：%d\n",std[index].name,std[index].height,std[index].weight);
    return 0;
}
#endif

#if 0
//求平面直角坐标系中两点之间的距离，使用结构体和函数。

#include <stdio.h>
#include <math.h>
typedef struct Point{
    double x;
    double y;
}Point;

double distance(Point p1, Point p2)
{
    return sqrt(pow(p1.x - p2.x,2) + pow(p1.y - p2.y,2));
}
int main()
{
    Point p1 = {4.0,3.0};
    Point p2 = {2.1,10.5};
    printf("（%g,%g）与（%g,%g）之间的距离为：%g\n",p1.x,p1.y,p2.x,p2.y,distance(p1,p2));
    return 0;
}
#endif

#if 1
//求4个学生中平均成绩最高者的学号、姓名和成绩（包括3门课成绩和1个总成绩）
#include <stdio.h>
typedef struct Course{
    float Chinese;
    float Math;
    float English;
    float sum;
    float avg;
}Course;
typedef struct Student{
    int id;
    char name[20];
    Course *p_course;
}Stud;
void courseSumAndAvg(Course *p, int count)
{
    for (int i = 0; i < count; i++)
    {
        p[i].sum = p[i].Chinese + p[i].Math + p[i].English;
    }
    for (int i = 0; i < count; i++)
    {
        p[i].avg = (p[i].Chinese + p[i].Math + p[i].English) / 3.0;
    }
    return;
}

int findMaxAVG(const Stud *p, int count)
{
    int index = 0;
    float maxAVG = p->p_course->avg;
    for(int i = 1; i < count; i++)
    {
        if(p[i].p_course->avg > maxAVG)
        {
            maxAVG = p[i].p_course->avg;
            index = i;
        }
    }
    return index;
}
int main()
{
    Course course[4]={
        {60,70,80},
        {70,80,90},
        {80,90,100},
        {90,100,70}
    };
    Stud s[4] = {
        {1001,"zhangsan",  &course[0]},
        {1002,"lisi",      &course[1]},
        {1003,"wangwu",    &course[2]},
        {1004,"zhaoliu",   &course[3]}
    };
    int count_s = sizeof(s) / sizeof(Stud);
    int count_c = sizeof(course) / sizeof(Course);
    courseSumAndAvg(course,count_c);
    int i = findMaxAVG(s,count_s);
    printf("学号L:%d,姓名:%s,成绩:\n语文:%g,数学:%g,英语:%g,总分:%g\n",
            s[i].id,s[i].name,s[i].p_course->Chinese,s[i].p_course->Math,s[i].p_course->English,s[i].p_course->sum);
    return 0;
}
#endif