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

#if 1 //从键盘输入6个学生5门课程的成绩,求每个人的总分与平均分

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
