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

       printf("\nEnter process name :\t"); // print process name
       scanf("%s",pn[i]);
       printf("\nEnter arrivaltime:\t"); //print arrival time
       scanf("%d",&at[i]);
       printf("\nEnter burst time:\t"); //print burst time
       scanf("%d",&et[i]);
       printf("\nEnter priority :\t"); //print priority for process
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
                strcpy(t,pn[i]); //copy the strings
                strcpy(pn[i],pn[j]);
                strcpy(pn[j],t);
            }
        }
    for(i=0; i<n; i++)
 
    {
 
        if(i==0)
        {
            st[i]=at[i]; // st=starting time
            wt[i]=st[i]-at[i]; // calculate waiting time
            ft[i]=st[i]+et[i]; // cal completion time
            ta[i]=ft[i]-at[i]; // cal turn around time
        }
        else
        {
            st[i]=ft[i-1];
            wt[i]=st[i]-at[i];
            ft[i]=st[i]+et[i];
            ta[i]=ft[i]-at[i];
        }
        totwt+=wt[i]; // totwt=totwt+wt;
        totta+=ta[i]; //totta=totta+ta;
    }
    awt=(float)totwt/n;//cal average waiting time
    ata=(float)totta/n;//cal average tur around time
    printf("\nPname\tarrivaltime\tburstime\tpriority\twaitingtime\ttatime");
    for(i=0; i<n; i++)
        printf("\n%s\t%5d\t\t%5d\t\t%5d\t\t%5d\t\t%5d",pn[i],at[i],et[i],p[i],wt[i],ta[i]);
    printf("\nAverage waiting time is:%f",awt); // print average waiting time
    printf("\nAverage turnaroundtime is:%f",ata); // print turn around time
    getch();
}
