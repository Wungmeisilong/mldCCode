#ifndef MENU_H
#define MENU_H

#include "student.h"
//声明菜单显示函数
void displayMainMenu(void);
void displayAdminMenu(void);
void displayStudentMenu(void);
//声明菜单处理函数
void handleMainMenu(StudentNode** head,int *idCounter);
void handleAdminMenu(StudentNode** head,int *idCounter);
void handleStudentMenu(StudentNode* head,int id);

#endif