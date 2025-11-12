#include <stdio.h>

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
    Stud std = {"zhangsan",20,90};
    dBlockWrite("dblock.txt",&std);
    dBlockRead("dblock.txt");
    return 0;
}