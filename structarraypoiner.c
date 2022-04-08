#include<stdio.h>
#include<string.h>
struct Student
{
   char name[20],course[10],city[20],area[30],state[30],usn[10];
   long long int fees;
   int marks[6],house_no,cross;
   char grade;
};
int main()
{
    int n;
    printf("How many students?");
    scanf("%d",&n);
    struct Student studs[n];
    struct Student *stud[n];
    int average[n],sum[n];
    for(int j=0;j<n;j++)
    {
        printf("Enter name,course acronym,house no,cross,area,city,state,usn,fees:");
        scanf("%s\n%s\n%d\n%d\n%s\n%s\n%s\n%s\n%lld",&studs[j].name,&studs[j].course,&studs[j].house_no,&studs[j].cross,&studs[j].area,&studs[j].city,&studs[j].state,&studs[j].usn,&studs[j].fees);
    }
    for(int k=0;k<n;k++)
    {
        sum[k]=0;
        for(int i=0;i<6;i++)
        {
            printf("Enter student %d's marks in subject %d:",k+1,i+1);
            scanf("%d\n",&studs[k].marks[i]);
            
            sum[k]+=studs[k].marks[i];
        }
        average[k]=sum[k]/6;
        if(average[k]>=85)
        {
            studs[k].grade='A';
        }
        else if(75<=average[k]<85)
        {
            studs[k].grade='B';
        }
        else if(50<=average[k]<75)
        {
            studs[k].grade='C';
        }
        else if(30<=average[k]<50)
        {
            studs[k].grade='D';
        }
        else
        {
            studs[k].grade='F';
        }
        printf("\n\n");
    }


    for(int i=0;i<n;i++)
    {
       stud[i]=&studs[i];
    }
    printf("\t\t*****STUDENT INFORMATION*****\n");
    for(int i=0;i<n;i++)
    {
        printf("Name:%s\nCourse:%s\nAddress:#%d,%dth cross,%s, %s, %s\nUSN:%s\nFees:$%lld\nGrade:%c\n\t***MARKS***\nSub 1=%d\nSub 2=%d\nSub 3=%d\nSub 4=%d\nSub 5=%d\nSub 6=%d\n\n",stud[i]->name,stud[i]->course,stud[i]->house_no,stud[i]->cross,stud[i]->area,stud[i]->city,stud[i]->state,stud[i]->usn,stud[i]->fees,stud[i]->grade,stud[i]->marks[0],stud[i]->marks[1],stud[i]->marks[2],stud[i]->marks[3],stud[i]->marks[4],stud[i]->marks[5]);
    }
  return 0;  

}