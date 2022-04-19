#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <unistd.h>
#include<conio.h>
#define width 20
#define length 20
int snakex=width/2, snakey=length/2;
int gameover, flag;
int foodx,foody,score=0;
void food()
{
  label1:
        srand(time(0));
        foodx=rand()%width;
        if(foodx==0)
        goto label1;
  
  label2:
        srand(time(0));
        foody=rand()%length;
        if(foody==0)
        goto label2;
}


void boundary()
{
   system("cls");
   int i,j;
   for(i=0;i<length;i++)
   {
       printf("|");
       for(j=0;j<=width;j++)
       {
           if(j!=width&&(i==0||i==length-1))
           {
               printf("~");
           }
           else if(!(j==width&&(i==0||i==length-1)))
           {
               if(j!=width-1)
               {
                   if((j==foodx&&i==foody))
                   {
                   printf("#");
                   }
                   else if(j==snakex&&i==snakey)
                   {
                       printf("0");
                   }
                   else
                   {
                      printf(" ");
                   }
               }
           }
           if(j==width)
           {
               printf("|");
           }
               
       }
       printf("\n");
   }
   printf("w->up\ns->down\na->left\nd->right\nx->quit\nPress desired key:");
}
void move()
{
   if(kbhit)
   {
       
       switch (_getch())
       {
       case 'w':
           flag=1;
           break;

        case 'a':
           flag=2;
           break;

        case 's':
           flag=3;
           break;

        case 'd':
           flag=4;
           break;

        case 'x':
           flag=5;
           break;

       default:
           break;
       }
   }
}
void logic()
{
    switch (flag)
    {
    case 1:
        snakey--;
        flag=0;
        break;

    case 2:
        snakex--;
        flag=0;
        break;

    case 3:
        snakey++;
        flag=0;
        break;

    case 4:
        snakex++;
        flag=0;
        break;

    case 5:
       gameover=1;
       break;
    }
    if(snakex==foodx&&snakey==foody)
    {
        score+=10;
        food();
    }
    if(snakex>=width-1||snakey>=length-1||snakex<0||snakey<0)
    {
        boundary();
        gameover=2;
    }
}


int main()
{ 
    food();
    while(gameover==0){
    boundary();
    move();
    logic();
    }
    if(gameover==1)
    {
    printf("\nThanks for playing!\nScore=%d\n",score);
    }
    else
    {
        printf("\nYou bumped into the wall and died *()*\nScore=%d\n",score);
    }
    return 0;

}