#if 0 //����洢���ڼ�����ӡ
#include <stdio.h>

int main()
{
    //����һ����ά�ַ�����洢���ڼ�
    char ch[5][20] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    for(int i = 0; i<5;i++)
    {
        printf("%s\n",ch[i]);
    }

    //�Ӽ��������ַ���������ӡ
    char str[10];
    scanf("%s",str);
    printf("%s\n",str);
    return 0;
}
#endif

#if 0 //���齻��

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

#if 0 //strlen()��ʹ��

#include <stdio.h>
#include <string.h>

int main()
{
    //char d[6] = {'1','2','3','4','5','6'};
    char a[3] = {'a','b','c'};//����Ĳ���3
    char b[] = "qwer";
    char c[] = {"asdfg"};

    printf("a�ĳ����ǣ�%lu\n",strlen(a));
    printf("b�ĳ����ǣ�%lu\n",strlen(b));
    printf("c�ĳ����ǣ�%lu\n",strlen(c));
    //printf("d�ĳ����ǣ�%lu\n",strlen(d));
    printf("a�ĳ����ǣ�%lu\n",strlen(a));
    
    return 0;
}
#endif

#if 0//����һ�����飬�������б���1��10�����庯������������Ԫ����˲�������

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
    printf("����Ԫ����˺�Ľ����%d\n",product);
    return 0;
}
#endif

#if 0
// ����һ���ַ��������磺char str[]="aBc3hu4usA84" ;ͳ������ַ����д�д��ĸ��Сд��ĸ�Լ����ֵĸ���
// ���磺
// ��д��ĸ��2��
// Сд��ĸ��6��
// ������4��
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
    printf("��д��ĸ��%d��\n", upperCount);
    printf("Сд��ĸ��%d��\n", lowerCount);
    printf("������%d��\n", digitCount);
    return 0;
}
#endif

#if 0 //��дһ��������ʵ���ַ����ķ�ת�����磺����abcdef�����fedcba

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
    printf("��ת����ַ����ǣ�%s\n", str);
}
int main()
{
    char str[100];
    printf("������һ���ַ�����\n");
    scanf("%s", str);
    int n = strlen(str);
    
    printf("ԭ�ַ����ǣ�%s\n", str);
    reverseString(str,n);
    return 0;
}
#endif

#if 0 //�Ӽ�������11��������һά�����У�����벿�ֵ�Ԫ��ֵȡ���������´���������У����������Ԫ��

#include <stdio.h>

int main()
{

    double arr[11]={0};
    printf("������11��������\n");
    for(int i = 0; i < 11; i++)
    {
        scanf("%lf",&arr[i]);
    }

    for(int j = 0; j < 11/2; j++)
    {
        arr[j] = 1.0 / arr[j];
    }

    printf("����������Ԫ��Ϊ��\n");
    for(int k = 0; k < 11; k++)
    {
        printf("%.2f ", arr[k]);
    }
    return 0;
}
#endif

#if 0 //��������10��Ԫ�ص��������飬������ż���±��Ԫ�غͣ��Լ�����ż��Ԫ�غ͡�

#include <stdio.h>
int test1(int arr[], int size)//����ż���±�Ԫ�غ�
{
    int sum = 0;
    for(int i = 0; i < size; i += 2)
    {
        sum += arr[i];
    }
    return sum;
}
int test2(int arr[], int size)//����ż��Ԫ�غ�
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
    printf("������10��������\n");
    for(int i = 0; i < 10; i++)
    {
        scanf("%d",&arr[i]);
    }

    int sum1 = test1(arr,10);
    int sum2 = test2(arr,10);

    printf("����ż���±�Ԫ�غ�Ϊ��%d\n", sum1);
    printf("����ż��Ԫ�غ�Ϊ��%d\n", sum2);

    return 0;
}
#endif

#if 0 //�Ӽ�������11��������һά�����У�������±�Ϊ������Ԫ�أ�������±�Ϊż����Ԫ�ء�
#include <stdio.h>

int main()
{
    int arr[11] = {0};
    printf("������11��������\n");
    for(int i = 0; i < 11; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("�±�Ϊ������Ԫ���У�\n");
    for(int i = 0; i < 11; i++)
    {
        if(i % 2 != 0)
        {
            printf("%d ", arr[i]);
        }
    }
    printf("\n�±�Ϊż����Ԫ���У�\n");
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

#if 0 //�Ӽ�������һ�����ݴ�������a[4][4]�У���������Ԫ��֮��

#include <stdio.h>

int main()
{
    int a[4][4] = {0};
    int sum = 0;
    printf("������16������������4x4�����У�\n");
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
    printf("����Ԫ��֮��Ϊ��%d\n", sum);
    return 0;
}
#endif

#if 0 //����3��3�и�����������Խ���������֮��
#include <stdio.h>

int main()
{
    int a[3][3] = {0};
    int sum = 0;
    printf("������9������������3x3�����У�\n");
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
    printf("�Խ���Ԫ��֮��Ϊ��%d\n", sum - a[1][1]); //�м�Ԫ���ظ�����һ�Σ���ȥ
    return 0;
}
#endif

#if 1 //�Ӽ�������6��ѧ��5�ſγ̵ĳɼ�,��ÿ���˵��ܷ���ƽ����

#include <stdio.h>
int main()
{
    float scores[6][5] = {0};
    float sum = 0.0;
    float avg = 0.0;
    printf("������6��ѧ��5�ſγ̵ĳɼ���\n");
    for(int i = 0; i < 6;i++)
    {
        printf("��%d��ѧ����5�ſγ̳ɼ���", i + 1);
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
        printf("��%d��ѧ�����ܷ�Ϊ��%.2f��ƽ����Ϊ��%.2f\n", i + 1, sum, avg);
        sum = 0.0;
        avg = 0.0;
    }
}
#endif
