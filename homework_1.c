#include <stdio.h>
#include <stdlib.h>
//题目1
int* create_array(int n);
void test1();
//题目2
int add(int a, int b);
int multiply(int a, int b);
void test2();
//题目3
void calculate(int a, int b, int (*operation)(int, int));
void test3();
//题目4
static int count = 0;
int *getCount();
void test4();
//题目5
int add1(int a,int b);
int subtract1(int a, int b);
int multiply1(int a, int b);
void calculate1(int a, int b, int n, int (*operate[])(int, int));
void test5();
int main(){
    //test1();
    //test2();
    //test3();
    //test4();
    test5();
    return 0;
}
int* create_array(int n)
{
    int *p = (int *)malloc( n * sizeof(int));
    if(p == NULL)
    {
        printf("malloc off\n");
    }
    return p;
}
void test1()
{
    int *p = create_array(10);
    if(p == NULL) return;//安全检查
    for(int i = 0; i < 10; i++)
    {
        p[i] = i*10;
    }
    for(int i =0; i < 10; i++)
    {
        printf("%d ",p[i]);
    }
    free(p);//释放内存
    p = NULL;//避免野指针
}

int add(int a, int b)
{
    return a + b;
}
int multiply(int a, int b)
{
    return a * b;
}
void test2()
{
    int (*func_ptr)(int, int) = NULL;
    int a,b;
    char op;
    printf("按照1 + 2输入数字与运算符：\n");
    scanf("%d %c %d",&a,&op,&b);
    if(op == '+')
    {
        func_ptr = add;
        printf("%d\n",func_ptr(a,b));
    }else if(op == '*')
    {
        func_ptr = multiply;
        printf("%d\n",func_ptr(a,b));
    }else{
        printf("输入操作符%c有误，请重新输入！！！\n",op);
    } 
}

void calculate(int a, int b, int (*operation)(int, int))
{
    printf("%d\n",operation(a,b));
}

void test3()
{
    int (*func_ptr)(int, int) = NULL;
    int a,b;
    char op;
    printf("按照1 + 2输入数字与运算符：\n");
    scanf("%d %c %d",&a,&op,&b);
    if(op == '+') func_ptr = add;
    else if(op == '*') func_ptr = multiply;
    else {
        printf("输入操作符%c有误，请重新输入！！！\n",op);
        return;
    }
    calculate(a,b,func_ptr);
}
int *getCount()
{
    count++;

    return &count;
}

void test4()
{
    while(count<3)
    {
        getCount();
    }
    printf("%d\n",count);
}

int add1(int a,int b)
{
    return a + b;
}

int subtract1(int a, int b)
{
    return a - b;
}

int multiply1(int a, int b)
{
    return a * b;
}

void calculate1(int a, int b, int n, int (*operate[])(int, int))
{
    printf("%d\n",operate[n](a,b));
}

void test5()
{
    int (*ops[3])(int, int) = {add1, subtract1, multiply1};
    int a,b,n;
    printf("输入两个数字和运算符：(例如：1 2 0)\n");
    printf("0:+\n1:-\n2:*\n");
    scanf("%d %d %d",&a,&b,&n);
    if(n < 0 || n > 2)
    {
        printf("输入运算符有误，请重新输入！！！\n");

        return;
    }
    calculate1(a,b,n,ops);
}