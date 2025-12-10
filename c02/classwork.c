#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//文件字符读写
void fCharRead(const char *fileName)
{
    FILE *fp = fopen(fileName,"r");
    char ch = '\0';

    if(fp == NULL)
    {
        printf("open file %s failed\n",fileName);
        fclose(fp);
        return ;
    }

    while((ch = fgetc(fp)) != EOF)
    {
        printf("%c ",ch);
    }

    fclose(fp);
}

void fCharWrite(const char* fileName)
{
    FILE *fp = fopen(fileName,"w");
    char ch = '\0';

    if(fp == NULL)
    {
        printf("open file %s failed\n",fileName);
        fclose(fp);
        return ;
    }

    fputc('a',fp);
    fputc('b',fp);

    fclose(fp);

}

//文本行读写
void fLineRead(const char* fileName)
{
    FILE *fp = fopen(fileName, "r");
    char line[100] = {0};

    if(fp == NULL)
    {
        printf("open file %s failed\n",fileName);
        fclose(fp);
        return ;
    }

    while(fgets(line,sizeof(line),fp) != NULL)
    {
        printf("%s",line);
    }

    fclose(fp);
}

void fLineWrite(const char* fileName, const char* contents)
{
    FILE *fp = fopen(fileName, "w");
    if(fp == NULL)
    {
        printf("open file %s failed\n",fileName);
        fclose(fp);
        return ;
    }
    fputs(contents, fp);

    fclose(fp);
}

//格式化读写
typedef struct Student{
    char name[20];
    int  age;
    int  score;
}Stud;

void fFormatRead(const char* fileName, int studentCount)
{
    FILE *fp = fopen(fileName, "r");
    Stud stud[studentCount];
    if(fp == NULL)
    {
        printf("open file %s failed !\n",fileName);
        fclose(fp);
        return;
    }
    for(int i = 0; i < studentCount; i++)
    {
        fscanf(fp,"%s %d %d",stud[i].name,&stud[i].age,&stud[i].score);
        printf("name:%s, age:%d, score:%d\n",
            stud[i].name,stud[i].age,stud[i].score);
    }
    
    fclose(fp);
}

void fFormatWrite(const char* fileName,const Stud* stud,int studentCount)
{
    FILE *fp = fopen(fileName, "w");
    if(fp == NULL)
    {
        perror("open file failed !\n");
        fclose(fp);
        return;
    }
    for(int i = 0; i < studentCount; i++)
    {
        fprintf(fp,"%s %d %d\n",stud[i].name,stud[i].age,stud[i].score);
    }
    fclose(fp);
}

//数据块读写

void dBlockWrite(const char* fileName,const Stud* stud)
{
    FILE *fp = fopen(fileName, "wb");
    if(fp == NULL)
    {
        perror("open file failed !\n");
        fclose(fp);
        return;
    }
    fwrite(stud,sizeof(Stud),1,fp);
    fclose(fp);
}

void dBlockRead(const char* fileName)
{
    FILE *fp = fopen(fileName, "rb");
    Stud stud = {0};
    if(fp == NULL)
    {
        perror("open file failed !\n");
        fclose(fp);
        return;

    }
    fread(&stud,sizeof(Stud),1,fp);
    printf("name:%s, age:%d, score:%d\n",stud.name,stud.age,stud.score);
    fclose(fp);
}

/*
链表操作
-----------------------------------------------------------------------------------------
*/
//链表的创建

typedef struct Node{
    int data;
    struct Node *next;
}Node, *LinkList;

Node* createLinkList()
{
    Node* header = (Node*)malloc(sizeof(Node));
    if(header == NULL)
    {
        perror("头节点创建失败！！");
        return NULL;
    }
    header->next = NULL;
    return header;
}


//1.添加节点
void pushLinkListNode(LinkList plinkList, int data)
{
    Node* current = plinkList;
    //1.尾部插入，先找到最后一个节点
    while(current->next != NULL)
    {
        current = current->next;
    }

    //2.创建新节点
    Node* NewNode = (Node*)malloc(sizeof(Node));
    if(NewNode == NULL)
    {
        perror("内存分配失败！！");
        return;
    }
    NewNode->data = data;
    NewNode->next = NULL;

    current->next = NewNode;
    return;
}
//2.根据值插入到链表中
void insertLinkListByValue(LinkList linkList,int data, int NewData)
{
    while(linkList->next != NULL)
    {
        if(linkList->next->data == data)
        {
            break;
        }
        linkList = linkList->next;
    }

    if(linkList->next == NULL)
    {
        printf("链表中没有找到%d\n",data);
        return;
    }

    //找到节点的情况：
    Node *pnewNode = (Node *)calloc(1,sizeof(Node));
    if(pnewNode == NULL)
    {
        perror("内存分配失败！！");
        return;
    }

    //创建节点
    pnewNode->data = NewData;
    pnewNode->next = NULL;
    //插入新位置
    pnewNode->next = linkList->next;
    linkList->next = pnewNode;
    printf("添加节点%d成功！！\n",NewData);
    return;
}

//3.删除尾节点
void popLinkListTail(LinkList LinkList)
{
    while(LinkList->next != NULL)
    {
        if(LinkList->next->next == NULL)
        {
            break;
        }
        LinkList = LinkList->next;
    }

    if(LinkList->next == NULL)
    {
        printf("链表为空\n");
        return;
    }
    //删除节点，用一个指针指向
    Node *p = LinkList->next;
    free(p);
    p = NULL;

    LinkList->next = NULL;
    printf("删除为节点成功！！\n");
    return;

}

//4.删除任意节点
void deleteLinkListByvalue(LinkList linkList,int data)
{
    while(linkList->next != NULL)
    {
        if(linkList->next->data == data)
        {
            break;
        }
        linkList = linkList->next;
    }

    if(linkList->next == NULL)
    {
        printf("链表中没有找到%d\n",data);
        return;
    }
    //找到节点的情况：
    Node *p = linkList->next;
    linkList->next = p->next->next;
    free(p);
    p = NULL;

    printf("任意删除节点成功\n");
    return;
}

//5.任意查找
void findLinkListByValue(LinkList linkList,int data)
{
    while(linkList->next != NULL)
    {
        if(linkList->next->data == data)
        {
            break;
        }
        linkList = linkList->next;
    }

    if(linkList->next == NULL)
    {
        printf("链表中没有找到%d\n",data);
        return;
    }
    //找到节点的情况：
    printf("找到节点%d\n",linkList->next->data);
    return;
}

//6.修改链表中的值
void modifyLinkListByValue(LinkList linkList, int data, int newData)
{
    while(linkList->next != NULL)
    {
        if(linkList->next->data == data)
        {
            linkList->next->data = newData;
            printf("修改节点成功\n");
            return;
        }
        linkList = linkList->next;
    }

    if(linkList->next == NULL)
        printf("链表中没有找到%d\n",data);
    
    printf("修改节点失败\n");
    return;
}

//7.打印链表
void printfLinkList(LinkList plinkList)
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
//8.销毁链表
void destroyLinkList(LinkList pheader)
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

void testLinkList()
{
    Node* pheader = NULL;
    pheader = createLinkList();
    pushLinkListNode(pheader, 20);
    pushLinkListNode(pheader, 30);
    pushLinkListNode(pheader, 40);
    pushLinkListNode(pheader, 900);
    pushLinkListNode(pheader, 67);
    printfLinkList(pheader);

    insertLinkListByValue(pheader,30,70);
    printfLinkList(pheader);

    popLinkListTail(pheader);
    printfLinkList(pheader);

    deleteLinkListByvalue(pheader,70);
    printfLinkList(pheader);

    findLinkListByValue(pheader,900);
    printfLinkList(pheader);

    modifyLinkListByValue(pheader, 900, 300);
    printfLinkList(pheader);

    destroyLinkList(pheader);
}


/*
无哨兵链表
-----------------------------------------------------------------------------------------
*/
Node* createLinkList_NH(int value)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL)
    {
        perror("内存分配失败！！");
        exit(0);//强制退出
    }
    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}
void appEndNode_NH(Node** pheader, int value)
{
    Node* newNode = createLinkList_NH(value);
    if(*pheader == NULL)//如果链表为空
    {
        *pheader = newNode;
        return;
    }
    Node* current = *pheader;
    if(current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
}
void printfLinkList_NH(Node* header)
{
    Node* current = header;
    while(current != NULL)
    {
        printf("%d ",current->data);
        current = current->next;
    }
    printf("\n");
}

void freeLinkList_NH(Node* header)
{
    Node* current = header;
    Node* temp = NULL;

    if(current != NULL)
    {
        temp = current;
        current = current->next;
        free(temp);
        temp = NULL;
    }
}

void testLinkList_NH()
{
    Node* newNode = NULL;
    int n,value;
    printf("需要输入多少个数？");
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        printf("添加第%d个数：",i + 1);
        scanf("%d",&value);
        appEndNode_NH(&newNode, value);
    }
    printf("打印结果：\n");
    printfLinkList_NH(newNode);
    freeLinkList_NH(newNode);
}
int main()
{
    //fCharWrite("fchar.txt");
    //fCharRead("fchar.txt");

    //fLineWrite("fline.txt","hello work\n88890\n");
    //fLineRead("fline.txt");
    // Stud stud[3] = {0};
    // int count = sizeof(stud) / sizeof(Stud);
    // printf("请输入学生信息：\n");
    // for(int i = 0; i < count; i++)
    // {
    //     printf("请输入第%d个学生的姓名：",i+1);
    //     scanf("%s",&stud[i].name);
    //     printf("请输入第%d个学生的年龄：",i+1);
    //     scanf("%d",&stud[i].age);
    //     printf("请输入第%d个学生的成绩：",i+1);
    //     scanf("%d",&stud[i].score);
    // }

    // fFormatWrite("fformat.txt",stud,count);
    // fFormatRead("fformat.txt",count);
    //Stud std = {"zhangsan",20,90};
    //dBlockWrite("dblock.txt",&std);
    //dBlockRead("dblock.txt");
    //testLinkList();
    testLinkList_NH();
    return 0;
}