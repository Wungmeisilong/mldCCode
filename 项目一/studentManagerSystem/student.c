#include "student.h"
#include <math.h>
//定义浮点数比较的误差范围
#define FLOAT_EPSILON 0.001f;

void addStudent(StudentNode** head,int *idCounter){
    StudentNode* newNode = (StudentNode*)malloc(sizeof(StudentNode));
    if(newNode == NULL){
        printf("堆内存分配失败！\n");
        return;
    }
    newNode->info.id = (*idCounter)++;
    printf("请输入学生姓名：");
    scanf("%s",newNode->info.name);
    char password1[MAX_PASSWORD_LENGTH];
    char password2[MAX_PASSWORD_LENGTH];
    do{
        printf("Enter student's password:");
        scanf("%s",password1);
        printf("Confirm student's password:");
        scanf("%s",password2);
        if(strcmp(password1,password2)!=0){
            printf("Password do not match. Please try again!\n");
        }
    }while(strcmp(password1,password2)!=0);
    strcpy(newNode->info.password,password1);
    printf("Enter student's class name:");
    scanf("%s",newNode->info.className);
    printf("Enter student's scores(3 subjects):");
    for(int i=0;i<MAX_SUBJECTS;i++){
        scanf("%f",&newNode->info.scores[i]);
    }
    printf("Enter student's age:");
    scanf("%d",&newNode->info.age);
    newNode->info.rank = 0;

    newNode->next = *head;//在学生链表头部添加新节点
    *head = newNode;      //修改头指针，让头指针始终指向第一个节点
    printf("学生添加成功！\n");
}

void displayStudents(StudentNode* head){
    calculateRank(&head);  //即使更新学生的名次
    StudentNode* current = head;
    while(current != NULL){
        printf("id:%d,name:%s,class:%s,scores:%.2f,%.2f,%.2f,age:%d,rank:%d\n",
            current->info.id,current->info.name,current->info.className,
            current->info.scores[0],current->info.scores[1],current->info.scores[2],
            current->info.age,current->info.rank);
        current = current->next;
    }
}
//使用双指针技术(current和previous)实现删除链表节点的操作
void deleteStudentById(StudentNode** head,int id){
    StudentNode* current = *head;
    StudentNode* previous = NULL;
    while(current != NULL && current->info.id != id){
        previous = current;
        current = current->next;
    }
    if(current == NULL){
        printf("Student not found!\n");
        return;
    }
    if(previous == NULL){  //首元节点就是要删除的节点
        *head = current->next;  //修改头指针，指向第二个节点
    }else{
        previous->next = current->next;
    }
    free(current);
    current = NULL;
    printf("Student deleted successfully!\n");
}
void modifyStudent(StudentNode* head,int id){
    StudentNode* current = head;
    while(current != NULL && current->info.id != id){
        current = current->next;
    }
    if(current == NULL){
        printf("Student not found!\n");
        return;
    }
    int choice = 0;
    printf("Which field to modify?\n");
    printf("1.Name\n");
    printf("2.Password\n");
    printf("3.Class\n");
    printf("4.Scores\n");
    printf("5.Age\n");
    printf("Enter your choice:");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            printf("Enter new name:");
            scanf("%s",current->info.name);
            break;
        case 2:
            printf("Enter new password:");
            scanf("%s",current->info.password);
            break;
        case 3:
            printf("Enter new class name:");
            scanf("%s",current->info.className);
            break;
        case 4:
            printf("Enter new scores(3 subjects):");
            for(int i=0;i<MAX_SUBJECTS;i++){
                scanf("%f",&current->info.scores[i]);
            }
            break;
        case 5:
            printf("Enter new age:");
            scanf("%d",&current->info.age);
            break;
        default:
            printf("Invalid choice!\n");
            return;
    }
    printf("Student's info is modified successfully!\n");
}

int writeStudentInfoToFile(FILE* file,const StudentInfo* student){
    if(fwrite(student,sizeof(StudentInfo),1,file)!=1){
        return 0;
    }
    return 1;  //保存单个学生信息成功
}
void saveStudentsToFile(StudentNode* head,const char* filename){
    FILE* file = fopen(filename,"wb");
    if(file == NULL){
        printf("Failed to open file for writing...\n");
        return;
    }
    int count = 0;
    StudentNode* current = head;
    //计算学生人数
    while(current != NULL){
        count++;
        current = current->next;
    }   
    if(fwrite(&count,sizeof(int),1,file)!=1){
        printf("Failed to write student's count!\n");
        fclose(file);
        return;
    }
    current = head;
    while(current != NULL){
        if(!writeStudentInfoToFile(file,&current->info)){
            printf("Failed to write student's info!\n");
            fclose(file);
            return;
        }
        current = current->next;
    }
    fclose(file);
    printf("Students saved to file successfully!\n");
}

void calculateRank(StudentNode** head){
    
}