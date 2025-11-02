#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//冒泡排序
void bubbleSort(int *p, int size)
{
    for(int i = 0; i < size - 1; i++)
    {
        for(int j = 0; j < size - i - 1; j++)
        {
            if(p[j] > p[j+1])
            {
                int t = p[j];
                p[j] = p[j+1];
                p[j+1] = t;
            }
        }
    }
}
void swap(int *a, int *b)
{
    int t = *a;
    if(a == b)
        return;
    *a = *b;
    *b = t;
}
//指针定义与使用
void prt_test()
{
    int *prt;
    int a = 1;
    prt = &a;
    //打印地址
    printf("%p\n", prt);
    //打印a的地址
    printf("%p\n", &a);
    //打印a的值
    printf("%d\n",*prt);

}

//指针数组
void ptr_array()
{
    int arr1[] = {1,2,3};
    int arr2[] = {4,5,6};
    int arr3[] = {0};
    //arr3 = arr1; //错误，数组名不可更改
    *arr3 = *arr1;
    printf("%d\n",*arr3);

    int *p = arr1;
    printf("%p\n",p);
    printf("%d\n",*p);
    p = p + 1;
    printf("%p\n",p);
    printf("%d\n",*p);
    p = arr1;
    printf("%d\n",*(p += 2));
    
}
//数组地址当做参数传递
void ptr_array_param(int *a, int n)
{
    //求和
    int s = 0;
    for(int i = 0; i < n; i++)
    {
        s += *a++;
    }
    printf("数组元素之和为：%d\n", s);
} 
void ptr_array_param1()
{
    char arr[] = "hello";
    char arr1[] = "world";
    if(strcmp(arr,arr1) == 0)
    {
        printf("相等\n");
    }else{
        printf("不相等\n");
    }

    //字符串冒泡排序
    char str[][5] = {"dog", "cat", "apple", "bana", "pear"};
    int size = sizeof(str)/sizeof(str[0]);

    for(int i = 0; i < size - 1; i++)
    {
        for(int j = i + 1; j <size -i -1; j++)
        {
            if(strcmp(str[i], str[j]) > 0)
            {
                char t[5];
                strcpy(t, str[i]);
                strcpy(str[i], str[j]);
                strcpy(str[j], t);
            }
        }
    }
    printf("排序后的字符串数组为：\n");
    for(int k = 0; k < size; k++)
    {
        printf("%s ", str[k]);
    }
}

//指针数组,即指向数组的指针
void ptr_array_test()
{
    int a[4] = {1,2,3,4};
    int *p[4] = {&a[0], &a[1], &a[2], &a[3]};

    printf("%d\n",a[0+1]);
    printf("%d\n",*(a+1));
    printf("%d\n",*p[0+1]);
    printf("%d\n",*(*(p+1)));
}
//数组指针
void arr_pointer()
{
    int a[5] = {1,2,3,4,5};
    int n = sizeof(a) / sizeof(a[0]);
    int (*p)[5] = &a;

    for(int i = 0; i < n; i++)
    {
        printf("%d ", (*p)[i]);
        printf("%d ", p[0][i]);
        printf("%d ", *(*p + i));
    }
    //p++;//越界
    //解决办法：

    printf("\n");
    int b[4][3] = {{1,2,3},{4,5,6},{7,8,9},{10,11,12}};
    int (*q)[3] = b;
    for(int i = 0; i < 3; i++, q++)
    {
        printf("%d ", (*q)[i]);
    }
}

//指针函数
int *func()
{
    int *p = (int *)malloc(40 *sizeof(int));
    
    return p;
}
void prt_func()
{
    int *q = func();
    for(int i = 0; i < 10; i++)
    {
        q[i] = i*10;
    }

    for(int i = 0; i < 10; i++)
    {
        printf("%d ", q[i]);
    }
    free(q);
    q =NULL;

   // printf("%d\n", q[0]); //未定义行为
}

//函数指针
void (*sortFunc)(int *, int) = bubbleSort;
void func_prt()
{
    int arr[] = {12,14,700,16};
    int n = sizeof(arr)/sizeof(arr[0]);
    sortFunc(arr,n);
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
int main()
{
    /*int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);

    int a = 10, b = 20;
    bubbleSort(arr, n);
    printf("排序后的数组: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    prt_test();
    printf("交换前：a=%d, b=%d\n", a, b);
    swap(&a, &b);
    printf("交换后：a = %d, b = %d\n",a, b);*/
    //ptr_array();
    //int arr[] = {1,2,3,4,5};
    //int n = sizeof(arr)/sizeof(arr[0]);
    //ptr_array_param(arr, n);
    //ptr_array_param1();
    //ptr_array_test();
    //arr_pointer();
    //prt_func();
    func_prt();

    return 0;
} 