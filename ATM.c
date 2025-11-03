/*ATM系统项目功能要求及每个功能得分如下(本项目共计100分，AI点评时会给出每个具体功能的得分点)：

1、项目的用户体验好：输入之前有合适的提示、显示结果有合适的暂停、用户界面清晰流畅等(10分)；

2、用户登录，要求输入用户名和密码(10分)；

3、用户名和密码输入只能有三次出错机会(10分)；

4、用户名和密码三次出错直接退出(10分)；

5、用户名和密码验证通过，显示ATM系统菜单(10分)；

6、存款(10分)；

7、取款(10分)；

8、显示余额(10分)；

9、退出(10分)；

10、非法输入有提示(10分)。*/
#include <stdio.h>
#include <string.h>
#include <windows.h>
unsigned int money = 10000;
int login(char *username, char *password);
void ATMSyatem();
unsigned int showMoney()
{
    return money;
}
void saveMoney(int m)
{
    money += m;
    printf("存款成功，当前余额为：%u\n",showMoney());
}
void getMoney(int m)
{
    if(money >= m){
        money -= m;
        printf("取款成功，当前余额为：%u\n",showMoney());
    }else{
        printf("余额不足，请重新输入！！！\n");
    }
}

void ATMSyatem()
{
    int flag = -1;
    int choose = 0;
    while (flag)
    {
        /* code */
        printf("---------------主菜单-------------\n");
        printf("欢迎使用ATM系统，请输入您的操作：\n");
        printf("1、存款\n");
        printf("2、取款\n");
        printf("3、显示余额\n");
        printf("4、退出\n");

        scanf("%d",&choose);

        switch (choose)
        {
        case  1:
            printf("存款功能\n");
            int m;
            printf("请输入存款金额：\n");
            scanf("%d",&m);
            saveMoney(m);
            break;
        case  2:
            printf("取款功能\n");
            int m1;
            printf("请输入取款金额：\n");
            scanf("%d",&m1);
            getMoney(m1);
            break;
        case  3:
            printf("显示余额\n");
            printf("当前余额为：%u\n",showMoney());
            break;
        case  4:
            flag = 0;
            printf("欢迎下次使用！！！\n");
            break;
        default:
            printf("输入指令有误，请重新输入！！！\n");
            break;
        }
    }
}
int login(char *username, char *password)
{
    int count = 3;
    while(count != 0){
        printf("欢迎使用ATM系统，请输入您的用户名：\n");
        scanf("%s",username);
        printf("请输入您的密码：\n");
        scanf("%s",password);
        if(strcmp(username,"admin") == 0
        && strcmp(password,"123456")== 0){
            system("cls");
            return 1;
        }else{
            system("cls");
            printf("用户名或密码错误，请重新输入！！！\n");
            printf("您还有%d次机会\n",--count);
        }
    }
    return 0;    
}
int main(int argc, char const *argv[])
{
    char username[10];
    char password[10];
    if(login(username,password) == 1){
        ATMSyatem();
    }else{
        system("cls");
        printf("卡已被冻结，请前往前台咨询相关业务！！\n");
        exit(0);
    }
    return 0;
}