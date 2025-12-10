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

#if 0
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

#if 0//声明表示颜色的枚举类型(RED,GREEN,BLUE,YELLOW,BLACK)，定义并初始化3个颜色变量， 编写函数打印颜色名称，调用函数输出所有颜色

#include <stdio.h>

enum Color{
    RED,
    GREEN,
    BLUE,
    YELLOW,
    BLACK
};
enum Color color1 = RED;
enum Color color2 = GREEN;
enum Color color3 = BLUE;

void printColor(enum Color color)
{
    switch(color)
    {
        case RED:
            printf("红色\n");
            break;
        case GREEN:
            printf("绿色\n");
            break;
        case BLUE:
            printf("蓝色\n");
            break;
        default:
            printf("未知颜色\n");
            break;
    }
}

int main()
{
    printColor(color1);
    printColor(color2);
    printColor(color3);
    return 0;
}
#endif

#if 0//声明表示状态的枚举类型(IDLE,RUNNING,PAUSED,STOPPED)，定义状态变量并初始化为RUNNING，使用switch语句打印当前状态的描述信息。

#include <stdio.h>

typedef enum State{
    IDLE,
    RUNNING,
    PAUSED,
    STOPPED
} State;

int main()
{
    State state = RUNNING;
    switch(state){
        case IDLE:
            printf("状态：空闲\n");
            break;
        case RUNNING:
            printf("状态：运行中\n");
            break;
        case PAUSED:
            printf("状态：暂停\n");
            break;
        case STOPPED:
            printf("状态：停止\n");
            break;
        default:
            printf("未知状态\n");
            break;
    }
    return 0;
}
#endif

# if 0//设计一个程序，要求读取文件中的一串字符串。要求识别字符串中的单词个数，并打印输出

#include <stdio.h>
#include <ctype.h>
#include <string.h>
int wordNum(const char* str)
{
    int count = 0;
    int in_word = 0;

    while (*str) {
        if (isalpha(*str)) {
            if (!in_word) {  // 进入一个新单词
                count++;
                in_word = 1;
            }
        } else {
            in_word = 0;  // 非字母，退出单词
        }
        str++;
    }
    return count;
}
void fRead(const char* fileName, char* line)
{
    FILE *fp = fopen(fileName,"r");
    if(fp == NULL)
    {
        printf("open file %s failed\n",fileName);
        return;
    }
    fgets(line,99,fp);
    fclose(fp);
}

void printWordNum(const char* fileName)
{
    char line[100] = {0};
    fRead(fileName,line);
    printf("%s\n单词个数为:\n%d\n",line,wordNum(line));
}
int main()
{
    printWordNum("test.txt");
    return 0;
}
#endif

#if 0 //编写一个程序，统计文本文件中字符串abc的个数，例如文件文件中内容为：”abcaaabcdefabc”则统计的”abc”的个数3

#include <stdio.h>
#include <string.h>
int ABCNum_Streaming(const char* fileName) {
    FILE *fp = fopen(fileName, "r");
    if (!fp) {
        perror("打开文件失败");
        return -1;
    }

    int count = 0;
    char a, b = 0, c = 0;
    int ch;

    while ((ch = fgetc(fp)) != EOF) {
        a = b;
        b = c;
        c = (char)ch;

        if (a == 'a' && b == 'b' && c == 'c') {
            count++;
        }
    }

    fclose(fp);
    return count;
}
int main()
{
    int count = ABCNum_Streaming("test.txt");
    printf("count:%d\n",count);
    return 0;
}
#endif

#if 0//将一个文件中的信息如果含有数字，将数字打印出来，其余字符不打印

#include <stdio.h>

void printNumber(const char* fileName)
{
    FILE *fp = fopen(fileName,"r");
    if(!fp)
    {
        perror("open file failed!!");
        return;
    }
    int ch = '\0';
    while((ch = fgetc(fp)) != EOF)
    {
        if(ch >= '0' && ch <= '9')
        {
            printf("%c ",ch);
        }
    }
    printf("\n");
    fclose(fp);
}
int main()
{
    printNumber("test.txt");
    return 0;
}
#endif

#if 0 
/*
动态分配一个包含5个整数的数组，给数组赋值1,3,5,7,9并打印所有元素，最后释放内存。
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr = NULL;
    int size = 5;
    arr = (int *)malloc(sizeof(int) * size);
    if(NULL == arr)
    {
        perror("malloc failed");
        return 1;
    }
    for(int i = 0; i < size; i++)
    {
        *(arr + i) = 2*i +1;
    }

    for(int i = 0; i<size; i++)
    {
        printf("%d ",*(arr + i));
    }
    free(arr);
    arr = NULL;
    return 0;
}
#endif

#if 0
/*
动态分配一个包含3个整数的数组并赋值，使用realloc将数组扩容到5个元素，添加新元素后打印所有元素，最后释放内存
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr = NULL;
    int size = 3;
    int new_size = 5;

    arr = (int*)malloc(sizeof(int) * size);
    if(NULL == arr)
    {
        perror("malloc failed");
        return 1;
    }
    for(int i = 0; i < size; i++)
    {
        *(arr + i) = 2*i +1; //另一种写法：arr[i] = 2*i + 1;
    }
    int *temp = realloc(arr,sizeof(int) * new_size);
    if(temp == NULL)
    {
        perror("realloc failed");
        free(arr);
        return 1;
    }
    arr = temp;
    for(int i = 0; i < new_size; i++)
    {
        *(arr + i) = 2*i +1;
    }
    printf("新元素的值为：\n");
    for(int i = 0; i < new_size; i++)
    {
        printf("arr[%d] = %d \n", i, arr[i]);
    }
    free(arr);
    arr = NULL;
    temp = NULL;
    return 0;
}
#endif

#if 0
/*
动态分配足够的内存来存储用户输入的字符串，将用户输入的字符串复制到动态分配的内存中，打印该字符串后释放内存。
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char str[100] = {0};
    char *str1 = NULL;
    printf("请输入字符:");

    /*重点：fgets(stdin)的意思是从标准输入流中读取字符串，注意该操作会读取'\n'，所以需要去掉*/
    if(fgets(str,sizeof(str),stdin) != NULL)
    {
        //移除换行符
        int len = strlen(str);
        if(len > 0 && str[len-1] == '\n')
        {
            str[len - 1] = '\0';
            len--;
        }
        str1 = (char*)malloc(sizeof(char) * (len + 1));

        if(str1 == NULL)
        {
            perror("malloc failed");
            return 1;
        }

        strcpy(str1,str);
        printf("str1:%s\n",str1);
        free(str1);
        str1 = NULL;
    }else {
        perror("fgets failed");
        return 1;
    }
    
    return 0;
}
#endif

#if 0

/*
动态创建包含3个学生结构体的数组，给每个学生赋值并打印所有学生信息，最后释放内存。
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME_LENGH 20
#define STUDENT_NUM 3

typedef struct Student
{
    char name[MAX_NAME_LENGH];
    int age;
    float score;
}Student;

void inputStudentInfo(Student *s, int count)
{
    printf("请输入学生信息:\n");
    for(int i = 0; i < count; i++)
    {
        printf("请输入第%d个学生姓名:",i+1);
        scanf("%s",s[i].name);
        printf("请输入第%d个学生年龄:",i+1);
        scanf("%d",&s[i].age);
        printf("请输入第%d个学生成绩:",i+1);
        scanf("%f",&s[i].score);
    }

}
void printStuentInfo(Student *s, int count)
{
    printf("学生信息:\n");
    for(int i = 0; i < count; i++)
    {
        printf("第%d个学生的信息：\n",i+1);
        printf("  姓名：%s\n",s[i].name);
        printf("  年龄：%d\n",s[i].age);
        printf("  成绩：%g\n",s[i].score);
    }
}

int main()
{
    Student * s = (Student*)malloc(sizeof(Student) * STUDENT_NUM);
    if(s == NULL)
    {
        perror("malloc failed");
        return 1;
    }
    inputStudentInfo(s,STUDENT_NUM);
    printStuentInfo(s,STUDENT_NUM);
    free(s);
    s = NULL;

    return 0;
}

#endif

#if 0
/*
定义学员结构体包括：姓名，学号(int)，编写代码

a) 创建3个学员数组并键盘录入学生姓名和学号；

b) 学号重复，重新录入；

c) 打印所有学员信息。
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_NAME_LENGH 20
#define STUDENT_NUM 3
typedef struct Student{
    int id;
    char name[MAX_NAME_LENGH];
}Stud;

int checkStudentId(Stud *s, int count, int id)
{

    for(int i = 0; i < count; i++)
    {
        if(s[i].id == id)
        {
            return 1;
        }
    }
    return 0;
}
void inputStudentInfo(Stud *s, int count)
{
    printf("请输入学生信息：\n");
    int i = 0;
    while(i < count)
    {
        printf("第%d个学生\n学号:",i+1);
        scanf("%d",&s[i].id);
        printf("姓名:");
        scanf("%s",s[i].name);
        if(i != 0)
        {
            int ret = checkStudentId(s,i,s[i].id);
            if( ret == 1)
            {
                printf("学号重复，请重新输入！\n");
                continue;
            }
        }
        i++;
        
    }
}


void printfStudentInfo(Stud *s, int count)
{
    printf("学生信息：\n");
    printf("序号\t姓名\t学号\n");
    printf("-----------------------------------\n");
    for(int i = 0; i < count; i++)
    {
        
        printf("%d\t%s\t%d\n",i+1,s[i].name,s[i].id);
        
    }
    printf("-----------------------------------\n");
}

int main()
{
    Stud *s = (Stud*)malloc(sizeof(Stud) * STUDENT_NUM);
    if(s == NULL)
    {
        perror("malloc failed");
        return 1;
    }
    inputStudentInfo(s,STUDENT_NUM);
    printfStudentInfo(s,STUDENT_NUM);

    free(s);
    s = NULL;

    return 0;
}
#endif

#if 0
/*
现有学生结构体(id,name,score),在堆上定义3个结构体元素并初始化，并将学员信息遍历打印；然

后使用realloc进行堆空间扩展5个元素，然后输出
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME_LENGH 20
#define STUDENT_NUM 3
typedef struct Student{
    int id;
    char name[MAX_NAME_LENGH];
    float score;
}Stud;

void printfStudentInfo(Stud *s, int count)
{
    printf("学生信息：\n");
    printf("学号\t姓名\t分数\n");
    printf("-----------------------------------\n");
    for(int i = 0; i < count; i++)
    {
        printf("%d\t%s\t%g\n",s[i].id,s[i].name,s[i].score);
    }
    printf("-----------------------------------\n");
}

int main()
{
    Stud *s = (Stud*)malloc(sizeof(Stud) * STUDENT_NUM);
    if(s == NULL)
    {
        perror("malloc failed");
        return 1;
    }
    int id[] = {1001,1002,1003};
    char *pname[STUDENT_NUM]= {"张三","李四","王五"};
    float score[] = {90.0,80.0,70.0};
    for(int i = 0; i < STUDENT_NUM; i++)
    {
        s[i].id = id[i];
        strcpy(s[i].name,pname[i]);
        s[i].score = score[i];
    }

    printfStudentInfo(s,STUDENT_NUM);
    Stud *s1 = (Stud*)realloc(s,sizeof(Stud) * (STUDENT_NUM + 5));
    if(s1 == NULL)
    {
        perror("realloc failed");
        free(s);
        s = NULL;
        return 1;
    }
    s = s1;
    int id1[] = {1004,1005,1006,1007,1008};
    char *p1name[]= {"赵六","孙七","周八","吴九","郑十"};
    float score1[] = {90.0,80.0,70.0,60.0,50.0};
    for(int i = 0; i < 5; i++)
    {
        s[i+STUDENT_NUM].id = id1[i];
        strcpy(s[i+STUDENT_NUM].name,p1name[i]);
        s[i+STUDENT_NUM].score = score1[i];
    }
    printfStudentInfo(s,STUDENT_NUM + 5);

    free(s);
    s = NULL;
    return 0;
}
#endif

#if 0

/*
编写函数在链表中查找特定值是否存在，如果存在返回1，否则返回0。
*/
#include <stdio.h>
typedef struct Node{
    int data;
    struct Node *next;
}Node;

int findLinkListByValue(Node* pheader, int value)
{
    Node* current = pheader;
    while(current->next != NULL)
    {
        if(current->next->data == value)
        {
            return 1;
        }
        current = current->next;
    }
    if(current == NULL) {
        printf("链表为空！！");
    }
    return 0;
}
#endif

#if 1
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;
//打印链表
void printfLinkList(Node* plinkList)
{
    //判断是否销毁
    if(plinkList == NULL)
    {
        printf("链表已被销毁！！");
        return;
    }

    //判断链表是否为空
    Node* current = plinkList->next;
    if(current == NULL)
    {
        printf("链表为空！！");
        return;
    }

    while(current != NULL)
    {
        printf("%d",current->data);
        if(current->next != NULL) printf("\t");
        current = current->next;
    }
    printf("\n");
    return;
}

//销毁链表
void destroyLinkList(Node* pheader)
{
    Node* temp = NULL;
    while(pheader != NULL)
    {
        temp = pheader;
        pheader = pheader->next;
        free(temp);
        temp = NULL;
    }
}

Node* createHearNode()
{
    Node* header = (Node*)malloc(sizeof(Node));
    if(header == NULL)
    {
        perror("头节点内存分配失败");
        exit(0);
    }
    header->next = NULL;
    return header;
}

//6.编写函数在链表头部插入一个新节点，并测试该功能
void addStartNewNode(Node* pheader, int value)
{
    Node* current = pheader;
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL)
    {
        perror("内存分配失败");
        return;
    }
    newNode->data = value;
    newNode->next = current->next;
    current->next = newNode;
}
void test_addtopNode()
{
    Node* pheader = NULL;
    pheader = createHearNode();
    addStartNewNode(pheader,20);
    addStartNewNode(pheader,30);
    printfLinkList(pheader);

    destroyLinkList(pheader);    
}

//5. 编写函数在链表尾部插入一个新节点，并测试该功能
void addEndNewNode(Node* pheader, int value)
{
    Node* current = pheader;
    while(current->next != NULL)
    {
        current = current->next;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL)
    {
        perror("内存分配失败");
        return;
    }
    newNode->data =value;
    newNode->next = NULL;
    current->next = newNode;    
}

void test_addEndNode()
{
    Node* pheader = NULL;
    pheader = createHearNode();
    addEndNewNode(pheader,20);
    addEndNewNode(pheader,30);
    addEndNewNode(pheader,90);
    printfLinkList(pheader);

    destroyLinkList(pheader);    
}

//4.编写函数删除链表中指定值的节点（假设值唯一），并测试该功能。
void deleteLinkListByValue(Node* pheader, int value)
{
    while(pheader->next != NULL)
    {
        if(pheader->next->data == value)
        {
            break;
        }
        pheader = pheader->next;
    }
    if(pheader->next == NULL)
    {
        printf("链表为空！！！\n");
        return;
    }

    Node* p = pheader->next;
    pheader->next = p->next;
    free(p);
    p = NULL;

    printf("删除节点成功！！！\n");
}

void test_deleteNode(){
    Node* pheader = NULL;
    pheader = createHearNode();
    addEndNewNode(pheader,20);
    addEndNewNode(pheader,30);
    addEndNewNode(pheader,90);
    printfLinkList(pheader);

    deleteLinkListByValue(pheader, 90);
    printfLinkList(pheader);

    destroyLinkList(pheader);
}

//3.编写函数修改链表中指定位置节点的值，并测试该功能
void modifyLinkListByValue(Node* pheader, int findValue, int newData)
{
    while(pheader->next != NULL)
    {
        if(pheader->next->data == findValue)
        {
            break;
        }
        pheader = pheader->next;
    }
    if(pheader->next == NULL)
    {
        printf("链表为空！！！\n");
        return;
    }

    pheader->next->data = newData;
    printf("修改节点成功\n");
    return;
}

void test_modifyNode(){
    Node* pheader = NULL;
    pheader = createHearNode();
    addEndNewNode(pheader,20);
    addEndNewNode(pheader,30);
    addEndNewNode(pheader,90);
    printfLinkList(pheader);

    modifyLinkListByValue(pheader, 90, 100);
    printfLinkList(pheader);

    destroyLinkList(pheader);
}

int main()
{
    test_addEndNode();
    test_addtopNode();
    test_deleteNode();
    test_modifyNode();
    return 0;
}
#endif