// menu.c
#include "../header/menu.h"
#include "student.c"

void Menu()
{
  int choice;
  // 清屏
  system("cls");

  // 显示菜单
  showMenu();

  // 接收用户输入
  choice = getChoice();

  // 路由
  system("cls");
  route(choice);

  printf("按下任意键继续...\n");
  getchar();
  getchar();

  return;
}

void showMenu()
{
  printf("---学生成绩管理系统 v0.1---\n");
  printf("1. 录入成绩\n");
  printf("2. 计算总分和平均分\n");
  printf("3. 按成绩从高分到低分排序\n");
  printf("4. 按学号由小到大排序\n");
  printf("5. 按学号查询学生成绩\n");
  printf("6. 统计分析\n");
  printf("7. 显示所有学生成绩\n");
  printf("8. 退出程序\n");
  printf("----------------------\n");
  printf("请输入要操作的序号 >>");
}

int getChoice()
{
  int choice;
  while (scanf("%d", &choice) != 1)
  {
    // 清空输入缓冲区
    while (getchar() != '\n')
      ;
    printf("输入有误，请重新输入 >>");
  }
  return choice;
}

void route(int choice)
{
  switch (choice)
  {
  case 1:
    inputScores();
    break;
  case 2:
    calculateTotalAndAverage();
    break;
  case 3:
    sortByScore();
    break;
  case 4:
    sortByID();
    break;
  case 5:
    searchByID();
    break;
  case 6:
    statistics();
    break;
  case 7:
    displayAllScores();
    break;
  case 8:
    exit(0);
  default:
    printf("无效的选择，请重新输入。\n");
    break;
  }
  return;
}