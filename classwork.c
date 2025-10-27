#include <stdio.h>

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
int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
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
    printf("交换后：a = %d, b = %d\n",a, b);

    return 0;
}