//headerfiles
#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
    int et[20],at[10],n,i,j,temp,p[10],st[10],ft[10],wt[10],ta[10];
    //declaration et = burst time
    //at = arrival time
    //p = priority
    //wt = waiting time
    //ta = turn around time
    
    int totwt=0,totta=0;//initialize tot = total waiting time, totta = total turn around time
    float awt,ata; // awt= average waiting time, ata = average turn around time
    char pn[10][10],t[10];
    //clrscr();
    printf("Enter the number of process:"); //print total no of process
    scanf("%d",&n); // input from user
    for(i=0; i<n; i++)
    {
       printf("||||||||||||||||Enter the details for each process wirtten below:-||||||||||||||||");

       printf("\nEnter process name :\t");
       scanf("%s",pn[i]);
       printf("\nEnter arrivaltime:\t");
       scanf("%d",&at[i]);
       printf("\nEnter burst time:\t");
       scanf("%d",&et[i]);
       printf("\nEnter priority :\t");
       scanf("%d",&p[i]);
  }
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
        {
            if(p[i]<p[j])
            {
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
                temp=at[i];
                at[i]=at[j];
                at[j]=temp;
                temp=et[i];
                et[i]=et[j];
                et[j]=temp;
                strcpy(t,pn[i]);
                strcpy(pn[i],pn[j]);
                strcpy(pn[j],t);
            }
        }
    for(i=0; i<n; i++)
 
    {
 
        if(i==0)
        {
            st[i]=at[i];
            wt[i]=st[i]-at[i];
            ft[i]=st[i]+et[i];
            ta[i]=ft[i]-at[i];
        }
        else
        {
            st[i]=ft[i-1];
            wt[i]=st[i]-at[i];
            ft[i]=st[i]+et[i];
            ta[i]=ft[i]-at[i];
        }
        totwt+=wt[i];
        totta+=ta[i];
    }
    awt=(float)totwt/n;
    ata=(float)totta/n;
    printf("\nPname\tarrivaltime\tburstime\tpriority\twaitingtime\ttatime");
    for(i=0; i<n; i++)
        printf("\n%s\t%5d\t\t%5d\t\t%5d\t\t%5d\t\t%5d",pn[i],at[i],et[i],p[i],wt[i],ta[i]);
    printf("\nAverage waiting time is:%f",awt);
    printf("\nAverage turnaroundtime is:%f",ata);
    getch();
}
