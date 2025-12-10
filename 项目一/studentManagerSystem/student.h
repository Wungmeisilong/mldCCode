#ifndef STUDENT_H
#define STUDENT_H

//包含系统头文件
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
//定义宏常量
#define MAX_NAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 50
#define MAX_CLASS_LENGTH 20
#define MAX_SUBJECTS 3
//定义结构体类型
typedef struct StudentInfo{
    int id;
    char name[MAX_NAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    char className[MAX_CLASS_LENGTH];
    float scores[MAX_SUBJECTS];
    int age;
    int rank;
}StudentInfo;
typedef struct StudentNode{
    StudentInfo info;
    struct StudentNode* next;
} StudentNode;
//功能函数声明
void addStudent(StudentNode** head,int *idCounter);
void displayStudents(StudentNode* head);
void deleteStudentById(StudentNode** head,int id);
void modifyStudent(StudentNode* head,int id);
void saveStudentsToFile(StudentNode* head,const char* filename);
void loadStudentsFromFile(StudentNode** head,int *idCounter,const char* filename);
StudentNode* searchStudentByName(StudentNode* head,const char* name);
StudentNode* searchStudentByScore(StudentNode* head,float score);
StudentNode* searchStudentByRank(StudentNode* head,int rank);
void sortStudentByName(StudentNode** head);
void sortStudentByScore(StudentNode** head,int subject);
void sortStudentByRank(StudentNode** head);

void viewPersonalInfo(StudentNode* head,int id);
void changePassword(StudentNode* head,int id);

int loginAdmin(const char* username,const char* password);
int longinStudent(StudentNode* head,int id,const char* password);
//工具函数声明
float calculateTotalScore(StudentInfo* student);
void calculateRank(StudentNode** head);
   //序列化单个学生信息到文件
int writeStudentInfoToFile(FILE* file,const StudentInfo* student);
   //从文件反序列化单个学生信息
int readStudentInfoFromFile(FILE* file,StudentInfo* student);
   //将链表转换为纯学生信息数组
StudentInfo* convertListToArray(StudentNode* head,int *count);
   //从学生信息数组创建链表
StudentNode* createListFromArray(StudentInfo* array,int count);

#endif