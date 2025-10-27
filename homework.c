#if 0 //数组存储星期几并打印
#include <stdio.h>

int main()
{
    //定义一个二维字符数组存储星期几
    char ch[5][20] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    for(int i = 0; i<5;i++)
    {
        printf("%s\n",ch[i]);
    }

    //从键盘输入字符串，并打印
    char str[10];
    scanf("%s",str);
    printf("%s\n",str);
    return 0;
}
#endif

#if 0 //数组交换

#include <stdio.h>

int main()
{
    int a[5] = {1,53,56,23,78};
    int n = sizeof(a)/sizeof(a[0]);
    for(int i = 0; i < n/2; i++)
    {
        int temp = a[i];
        a[i] = a[n - 1 -i];
        a[n - 1 -i] = temp;
    }
    for(int j = 0; j < n; j++)
    {
        printf("%-5d",a[j]);
    }
    return 0;
}

#endif

#if 0 //strlen()的使用

#include <stdio.h>
#include <string.h>

int main()
{
    //char d[6] = {'1','2','3','4','5','6'};
    char a[3] = {'a','b','c'};//输出的不是3
    char b[] = "qwer";
    char c[] = {"asdfg"};

    printf("a的长度是：%lu\n",strlen(a));
    printf("b的长度是：%lu\n",strlen(b));
    printf("c的长度是：%lu\n",strlen(c));
    //printf("d的长度是：%lu\n",strlen(d));
    printf("a的长度是：%lu\n",strlen(a));
    
    return 0;
}
#endif

#if 0//定义一个数组，在数组中保存1到10，定义函数将所有数组元素相乘并输出结果

#include <stdio.h>

int multiply(int arr[], int size)
{
    int result = 1;
    for(int i = 0; i < size; i++)
    {
        result *= arr[i];
    }
    return result;
}

int main()
{
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(a)/sizeof(a[0]);
    int product = multiply(a,n);
    printf("数组元素相乘后的结果：%d\n",product);
    return 0;
}
#endif

#if 0
// 定义一个字符串，例如：char str[]="aBc3hu4usA84" ;统计这个字符串中大写字母、小写字母以及数字的个数
// 例如：
// 大写字母有2个
// 小写字母有6个
// 数字有4个
#include <stdio.h>

int main()
{
    char str[]="aBc3hu4usA84";
    int upperCount =0;
    int lowerCount =0;
    int digitCount =0;

    for(int i = 0; str[i] != '\0'; i++)
    {
        if(str[i] >= 'A'&& str[i] <= 'Z')
        {
            upperCount++;
        }else if(str[i] >='a' && str[i] <= 'z')
        {
            lowerCount++;
        } else {
            digitCount++;
        }

    }
    printf("大写字母有%d个\n", upperCount);
    printf("小写字母有%d个\n", lowerCount);
    printf("数字有%d个\n", digitCount);
    return 0;
}
#endif

#if 0 //编写一个函数，实现字符串的翻转。例如：输入abcdef，输出fedcba

#include <stdio.h>
#include <string.h>
void reverseString1(char* str)
{
    int l = 0;
    int r = strlen(str) - 1;
    while(l < r)
    {
        char temp = str[l];
        str[l] = str[r];
        str[r] = temp;
        l++;
        r--;

    }
}
void reverseString(char str[], int size)
{
    for(int i = 0; i < size/2; i++)
    {
        char temp = str[i];
        str[i] = str[size - 1 - i];
        str[size - 1 - i] = temp;
    }
    printf("翻转后的字符串是：%s\n", str);
}
int main()
{
    char str[100];
    printf("请输入一个字符串：\n");
    scanf("%s", str);
    int n = strlen(str);
    
    printf("原字符串是：%s\n", str);
    reverseString(str,n);
    return 0;
}
#endif

#if 0 //从键盘输入11个数存入一维数组中，将左半部分的元素值取倒数后重新存入该数组中，并输出所有元素

#include <stdio.h>

int main()
{

    double arr[11]={0};
    printf("请输入11个整数：\n");
    for(int i = 0; i < 11; i++)
    {
        scanf("%lf",&arr[i]);
    }

    for(int j = 0; j < 11/2; j++)
    {
        arr[j] = 1.0 / arr[j];
    }

    printf("处理后的数组元素为：\n");
    for(int k = 0; k < 11; k++)
    {
        printf("%.2f ", arr[k]);
    }
    return 0;
}
#endif

#if 0 //键盘输入10个元素的整数数组，求所有偶数下标的元素和，以及所有偶数元素和。

#include <stdio.h>
int test1(int arr[], int size)//所有偶数下标元素和
{
    int sum = 0;
    for(int i = 0; i < size; i += 2)
    {
        sum += arr[i];
    }
    return sum;
}
int test2(int arr[], int size)//所有偶数元素和
{
    int sum = 0;
    for(int i = 0; i < size; i ++)
    {
        if(arr[i] % 2 == 0)
        {
            sum += arr[i];
        }
    }
    return sum;
}

int main()
{
    int arr[10] = {0};
    printf("请输入10个整数：\n");
    for(int i = 0; i < 10; i++)
    {
        scanf("%d",&arr[i]);
    }

    int sum1 = test1(arr,10);
    int sum2 = test2(arr,10);

    printf("所有偶数下标元素和为：%d\n", sum1);
    printf("所有偶数元素和为：%d\n", sum2);

    return 0;
}
#endif

#if 0 //从键盘输入11个数存入一维数组中，先输出下标为奇数的元素，再输出下标为偶数的元素。
#include <stdio.h>

int main()
{
    int arr[11] = {0};
    printf("请输入11个整数：\n");
    for(int i = 0; i < 11; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("下标为奇数的元素有：\n");
    for(int i = 0; i < 11; i++)
    {
        if(i % 2 != 0)
        {
            printf("%d ", arr[i]);
        }
    }
    printf("\n下标为偶数的元素有：\n");
    for(int i = 0; i < 11; i++)
    {
        if(i % 2 == 0)
        {
            printf("%d ", arr[i]);
        }
    }

    return 0;
}
#endif

#if 0 //从键盘输入一组数据存入数组a[4][4]中，求其四周元素之和

#include <stdio.h>

int main()
{
    int a[4][4] = {0};
    int sum = 0;
    printf("请输入16个整数，存入4x4数组中：\n");
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            printf("%-5d",a[i][j]);
        }
        printf("\n");
    }
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(i == 0 || i == 3 || j == 0 || j == 3)
            {
                sum += a[i][j];
            }
        }
    }
    printf("四周元素之和为：%d\n", sum);
    return 0;
}
#endif

#if 0 //输入3行3列个整数，求其对角线所有数之和
#include <stdio.h>

int main()
{
    int a[3][3] = {0};
    int sum = 0;
    printf("请输入9个整数，存入3x3数组中：\n");
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            printf("%-5d",a[i][j]);
        }
        printf("\n");
    }
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(i == j)
            {
                sum += a[i][j];
            }
            if(i + j == 2)
            {
                sum += a[i][j];
            }
        }
    }
    printf("对角线元素之和为：%d\n", sum - a[1][1]); //中间元素重复加了一次，减去
    return 0;
}
#endif

#if 0 //从键盘输入6个学生5门课程的成绩,求每个人的总分与平均分

#include <stdio.h>
int main()
{
    float scores[6][5] = {0};
    float sum = 0.0;
    float avg = 0.0;
    printf("请输入6个学生5门课程的成绩：\n");
    for(int i = 0; i < 6;i++)
    {
        printf("第%d个学生的5门课程成绩：", i + 1);
        for(int j = 0; j<5; j++)
        {
            scanf("%f",&scores[i][j]);
        }
        printf("\n");
    } 

    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            sum += scores[i][j];
        }
        avg = sum / 5.0;
        printf("第%d个学生的总分为：%.2f，平均分为：%.2f\n", i + 1, sum, avg);
        sum = 0.0;
        avg = 0.0;
    }
}
#endif

#if 0 //定义一个int类型的数组，通过指针逆序输出数组数据

#include <stdio.h>

int main()
{
    int a[] = {10,20,30,40,50};
    int n = sizeof(a) / sizeof(a[0]);
    int *p = a;
    printf("原数组元素：\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", *(p + i));
    }
    printf("\n逆序输出数组元素：\n");
    for(int i = n-1; i>=0; i--)
    {
        printf("%d ",*(p + i));
    }
    return 0;
}

#endif

#if 0 //从键盘输入10个数,用按降序排序并输出。(使用指针实现冒泡排序)

#include <stdio.h>

void bubbleSort(int *p, int size)
{
    for(int i = 0; i < size - 1; i++)
    {
        for(int j = 0; j < size - i - 1; j++)
        {
            if(p[j] < p[j+1])
            {
                int t = p[j];
                p[j] = p[j+1];
                p[j+1] = t;
            }
        }
    }
}

int main()
{
    int arr[10] = {0};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("请输入10个整数：\n");
    for(int i = 0; i < 10; i++)
    {
        scanf("%d",&arr[i]);
    }
    bubbleSort(arr,n);
    for(int j = 0; j<n; j++)
    {
        printf("%d ",arr[j]);
    }
    return 0;
}

#endif

#if 0 //编写求两个数中最大数的函数，并调用该函数求出主函数中两个数中的最大数（不能使用全局变量）

#include <stdio.h>

int  maxNum(int max,int min)
{
    return max > min ? max : min;
}
int main()
{
    int a =30, b = 90;
    printf("最大值为：%d\n", maxNum(a, b));
    return 0;
}
#endif

#if 0//编写交换两个变量值的函数，并调用该函数交换主函数中两个变量的值（不能使用全局变量传递数据）
#include <stdio.h>

void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    int a =30, b = 90;
    printf("交换前：a = %d, b = %d\n", a, b);
    swap(&a, &b);
    printf("交换后：a = %d, b = %d\n", a, b);
    return 0;
}
#endif

#if 0//从键盘输入11个数存入一维数组中，将该数组中左半部分与右半部分的值平移交换后重新存入该数组中并输出

#include <stdio.h>

void swapArr(float *p, int size);

int main()
{
    float arr[11] = {0.0};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("请输入11个数:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%f", &arr[i]);
    }
    swapArr(arr,n);
    for(int i = 0; i < n; i++)
    {
        printf("%-3g ", arr[i]);
    }
    return 0;
}

void swapArr(float *p, int size)
{
    for(int i = 0; i<size/2; i++)
    {
        float t = p[i];
        p[i] = p[size - i - 1];
        p[size - i - 1] = t;
    }
}
#endif

#if 0 //从键盘输入十个整数存入一维数组中，再按反序输出（要求用指针访问数组元素）

#include <stdio.h>

int main()
{
    int arr[10] = {0};
    int n = sizeof(arr) / sizeof(arr[0]);
    int *p = arr;
    printf("请输入10个数:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for(int i = n - 1; i >= 0; i--)
    {
        printf("%-4d ", p[i]);
    }
    return 0;
}

#endif

#if 0 //从键盘输入十个整数存入一维数组中，使用函数求出它们的和并输出（要求用指针访问数组元素）

#include <stdio.h>

void sumArray(int *p, int size, int *sum)
{
    for(int i = 0; i < size; i++)
    {
        *sum += p[i];
    }
}

int main()
{
    int arr[10] = {0};
    int n = sizeof(arr) / sizeof(arr[0]);
    int *p = arr;
    int sum = 0;
    printf("请输入10个数:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    sumArray(p, n, &sum);
    printf("数组元素之和为：%d\n", sum);
    return 0;
}
#endif

#if 1 //给定两个含有n个元素的有序整形数组a和b，求出其共同元素

#include <stdio.h>

void findNum(int *a, int *b, int size)
{
    
    for(int i = 0; i < size; i++)
    {
        int l = 0;
        int r = size - 1;
        //二分查找
        while(l <= r)
        {
            int mid = l + (r -l) /2;
            if(b[mid] == a[i])
            {
                printf("%d ", a[i]);
                break;
            }else if(b[mid] < a[i])
            {
                l = mid + 1;
            }else
            {
                r = mid - 1;
            }
        }
            
    }

}

void findNum1(int *a, int *b, int size)
{
    
    for(int i = 0; i < size; i++)
    {
        
        for(int j = 0; j<size; j++)
        {
            if(a[i] == b[j])
            {
                printf("%d ", a[i]);
            }
        }
            
    }

}
int main()
{
    int a[] = {1,3,5,7,9,11,13,15,17,19};
    int b[] = {2,3,5,7,11,13,17,19,23,29};
    int n = sizeof(a) / sizeof(a[0]);
    printf("数组a和b的共同元素有：\n");
    findNum(a, b, n);
    return 0;
}

#endif