/**
Exercise_2_2: write a loop euivalant to the for loop above without && and ||.
Author: Akshat Darji
Created: 4 July 2024
Modified: 4 July 2024
*/


/** REQUIRED HEADER FILES */
#include<stdio.h>

/** MARCO DEFINATIONS */
#define MAXLINE 1000

/** FUNCTION PROTOTYPES */
int mgetline(char line[],int lim);
void copy(char to[],char from[]);


/** MAIN PROGRAM */
/*
 * main: Using a for loop without using && and || Equivalant to below snippet
 * for(i=0;i<lim-1 && (c=getchar())!='\n' && c != EOF; i++){
 *	s[i] = c;
 * }
*/


int main(void)
{
    int len,max;
    char line[MAXLINE],maxline[MAXLINE];

    max =0;

    while((len=mgetline(line,MAXLINE)) > 0)
    {
        if(len > max)
        {
            max = len;
            copy(maxline,line);
        }
    }

    if(max>0)
        printf("%s",maxline);
}

/*
 * mgetline(char line[],int lim): detail of that function like what it accepts
 * Author: Akshat Darji
 * Created: 21 Jun 2024
 * Modified: 21 Jun 2024
*/

int mgetline(char s[],int lim)
{
    int i,c;

    for(i=0; i < lim - 1 ;++i) {
        c = getchar();
        if (c == EOF)
            break;
        if (c == '\n')
            break;
        s[i] = c;
    }

    if(c == '\n')
    {
    s[i] = c;
    ++i;
    }

    s[i] = '\0';
    return i;
}

/*
 * copy(char to[],char from[]): detail of that function like what it accepts
 * Author: Akshat Darji
 * Created: 21 Jun 2024
 * Modified: 21 Jun 2024
*/

void copy(char to[],char from[])
{
    int i;
    i=0;

    while((to[i]=from[i]) != '\0')
    ++i;
}

