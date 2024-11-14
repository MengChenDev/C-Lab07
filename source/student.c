// student
#include "../header/student.h"

Student students[MAX_STUDENTS];
int studentCount = 0;

void inputScores()
{
  printf("请输入学生人数（最多不超过30人）：");
  scanf("%d", &studentCount);

  if (studentCount > MAX_STUDENTS)
  {
    printf("人数超过上限，请重新输入。\n");
    return;
  }

  for (int i = 0; i < studentCount; i++)
  {
    printf("请输入第%d个学生的学号和成绩（用空格分隔）：", i + 1);
    scanf("%d %f", &students[i].id, &students[i].score);
  }
}

void calculateTotalAndAverage()
{
  float total = 0;
  for (int i = 0; i < studentCount; i++)
  {
    total += students[i].score;
  }
  float average = total / studentCount;
  printf("总分：%.2f\n", total);
  printf("平均分：%.2f\n", average);
}

void sortByScore()
{
  for (int i = 0; i < studentCount - 1; i++)
  {
    for (int j = 0; j < studentCount - i - 1; j++)
    {
      if (students[j].score < students[j + 1].score)
      {
        Student temp = students[j];
        students[j] = students[j + 1];
        students[j + 1] = temp;
      }
    }
  }
  printf("按成绩从高到低排序完成。\n");
}

void sortByID()
{
  for (int i = 0; i < studentCount - 1; i++)
  {
    for (int j = 0; j < studentCount - i - 1; j++)
    {
      if (students[j].id > students[j + 1].id)
      {
        Student temp = students[j];
        students[j] = students[j + 1];
        students[j + 1] = temp;
      }
    }
  }
  printf("按学号从小到大排序完成。\n");
}

void searchByID()
{
  int searchID;
  printf("请输入要查询的学号：");
  scanf("%d", &searchID);

  for (int i = 0; i < studentCount; i++)
  {
    if (students[i].id == searchID)
    {
      printf("学号：%d，成绩：%.2f\n", students[i].id, students[i].score);
      return;
    }
  }
  printf("未找到学号为%d的学生。\n", searchID);
}

void statistics()
{
  int excellent = 0, good = 0, medium = 0, pass = 0, fail = 0;

  for (int i = 0; i < studentCount; i++)
  {
    if (students[i].score >= 90)
    {
      excellent++;
    }
    else if (students[i].score >= 80)
    {
      good++;
    }
    else if (students[i].score >= 70)
    {
      medium++;
    }
    else if (students[i].score >= 60)
    {
      pass++;
    }
    else
    {
      fail++;
    }
  }

  printf("优秀（90-100分）：%d人，占比：%.2f%%\n", excellent, (float)excellent / studentCount * 100);
  printf("良好（80-89分）：%d人，占比：%.2f%%\n", good, (float)good / studentCount * 100);
  printf("中等（70-79分）：%d人，占比：%.2f%%\n", medium, (float)medium / studentCount * 100);
  printf("及格（60-69分）：%d人，占比：%.2f%%\n", pass, (float)pass / studentCount * 100);
  printf("不及格（0-59分）：%d人，占比：%.2f%%\n", fail, (float)fail / studentCount * 100);
}

void displayAllScores()
{
  printf("所有学生成绩如下：\n");
  for (int i = 0; i < studentCount; i++)
  {
    printf("学号：%d，成绩：%.2f\n", students[i].id, students[i].score);
  }
}