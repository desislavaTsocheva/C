#include <stdio.h>
#include <stdlib.h>

struct Student
{
    char name[20];
    double grade;
};

struct Class
{
    char name[10];
    int studentsCount;
    struct Student students[30];

};

struct Grade
{
    //int year;
    int classCount;
    struct Class classes[3];
};

void inputClass(struct Class *cls)
{
    printf("Enter name: ");
    fgets(cls->name, sizeof(cls->name), stdin);
    cls->name[strcspn(cls->name, "\n")] = 0;

    printf("Enter students count: ");
    scanf("%d",&cls->studentsCount);

    getchar();

    for(int i=0;i<cls->studentsCount;i++)
    {
            printf("Enter student name: ");
            fgets(cls->students[i].name, sizeof(cls->students[i].name), stdin);
            cls->students[i].name[strcspn(cls->students[i].name, "\n")] = 0;

            printf("Enter student grade: ");
            scanf("%lf",&cls->students[i].grade);

            getchar();
    }

}

double AverageClassGrade(struct Class *cls)
{
    double sum=0;
    for(int i=0;i<cls->studentsCount;i++)
    {
            sum+=cls->students[i].grade;
    }
    return sum/cls->studentsCount;
}

double AverageGrade(struct Grade *grade)
{
    double sum=0;
    int counterStudents=0;
    for(int i=0;i<grade->classCount;i++)
    {
            for(int j=0;j<grade->classes[i].studentsCount;j++)
            {
                    sum+=grade->classes[i].students[j].grade;
                    counterStudents++;
            }
    }
    return sum/counterStudents;
}

int main()
{
    struct Grade grade;
    printf("Class in the grade: ");
    scanf("%d",&grade.classCount);
    getchar();
    double avr=0;
    for(int i=0;i<grade.classCount;i++)
    {
            printf("Class:\n ");
            inputClass(&grade.classes[i]);
            avr=AverageClassGrade(&grade.classes[i]);
            printf("Average class grade for %s is: %.2lf \n",grade.classes[i].name,avr);
    }
      double average=AverageGrade(&grade);
      printf("\nAverage grade is: %.2lf",average);

    return 0;
}
