#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#define N 100

char name[N],password[N];
int id,leave;
struct time{int start,end;
};
int selecter(int m,int n);
void Sreg(int m,int n);
void Slogin(int m,int n);
void Mlogin(int m,int n);
void Mreg(int m,int n);
void request(int m,int n);
void check_request(int m,int n);
void create_routine(int m,int n);
void m_select(int m,int n);
void sec_select(int m,int n);
void check_request_status(int m,int n);
void take_action(int m,int n);
void view_routine(int m,int n);
void give_salary(int m,int n);

int main()
{int m,n;
printf("Enter total number of security persons:\n");
scanf("%d",&m);
printf("Enter no. of places[The places are named as 1,2,3,4......n]\n");
scanf("%d",&n);
selecter(m,n);
}

int selecter(int m,int n)
{int ch;
 printf("\n\n\t 1. SECURITY REGISTRATION\t2.MANAGER REGISTRATION");
 printf("\n\n\t 3. SECURITY LOGIN\t\t4.MANAGER LOGIN");
printf("\n\n\t\t\tENTER YOUR CHOICE: ");
scanf("%d",&ch);
switch(ch)
  {
    case 1:{
        Sreg(m,n);
        break;}
   case 2:{
        Mreg(m,n);
        break;}
    case 3:{
        Slogin(m,n);
        break;}
    case 4:{
        Mlogin(m,n);
        break;}
    default:{printf("\n\n\t\t\t\tNO MATCH FOUND");
            selecter(m,n);}
  }
  }

int match(char s1[],char s2[])
{
  int i,l;
  if(strlen(s1)>strlen(s2))l=strlen(s1);else l=strlen(s2);
  for (i = 0; i < l; ++i)
    {
      if(s1[i]!=s2[i]) return 0;
      if(i=l-1)return 1;
    }
}
void add(char s1[])
{
  int i,j;
  char s2[]=".txt";
  for(i = 0; s1[i] != '\0'; ++i);

  for(j = 0; s2[j] != '\0'; ++j, ++i)
    {
      s1[i] = s2[j];
    }
}

void give_salary(int m,int n)
{int e,s,l;
  printf("enter leave\n");
  scanf("%d",&l);
printf("max. leaves are 5\n");
 printf("Salary per day 300rs.Fine is 50 rs per day at leave more than 5\n");
 if(l>5)
   {e=l-5;
     s=((30-l)*300)-(50*e);}
 else s=(30-l)*300;
 printf("Monthly salary is %d",s);}


void Sreg(int m,int n)
{char s1[20];int l=0;
  printf("Enter your ID(NOTE:Every person have a unique id):\n");
  printf("ID NO. is a 4 digit no. starting from 1001(e.g 1001,1002,1003,1004..)\n");
  scanf("%s",s1);
  add(s1);
  FILE *fp=fopen(s1,"r");
  if(fp!=NULL)
    {
      fclose(fp);
      printf("you are already Registered.Enter 3 for security_login.\n");
      selecter(m,n);
    }
  else
    {
      fp=fopen(s1,"w+");
      printf("Enter employee name:\n");
      scanf("%s",name);
      printf("Enter password\n");
      scanf("%s",password);
      fprintf(fp,"%s\t%s\t%d\n",name,password,l);
      printf("\t\t\tSuccessfully Registered\tEnter 3 to login\n");
      fclose(fp);
    }
  selecter(m,n);
}

void Mreg(int m,int n)
{int k;
  char a[20],m_name[N],m_pass[N];
  printf("Enter Manager ID:\n");
  scanf("%s",a);
  add(a);
  FILE *fp=fopen(a,"r");
  if (fp==NULL)
    {
      fp=fopen(a,"w");
      printf("Enter name:\n");
      scanf("%s",m_name);
      printf("Enter password\n");
      scanf("%s",m_pass);
      fprintf(fp,"%s\t%s\n",m_name,m_pass);
      fclose(fp);
      selecter(m,n);
    }
  else
    {
      puts("You are already Registered\n");
      selecter(m,n);
    }
}

void Slogin(int m,int n)
{int k,l;
  char a[20],b[20];
  printf("Employee ID:\n");
  scanf("%s",a);
  printf("Password\n");
  scanf("%s",b);
  add(a);
  FILE *fp=fopen(a,"r");
  if(fp==NULL)
    {
      puts("you are not Registered yet. please Register first.");
      selecter(m,n);
    }
  else
    {
      fscanf(fp,"%s\t%s\t%d\n",name,password,&l);//l=leaves
      if(match(b,password)==0)
	{
	  puts("\t\tWrong Password\n");
	  fclose(fp);
	  selecter(m,n);
	}
      else
	{
	  puts("\t\tlogin successful\n ");
	  fp=fopen(a,"r+");
printf("Enter your choice.\n 1.Request leave\t2.Check request status\t3.Total leaves\t4.View Routine\t5.Salary\t6.logout\n");
	  scanf("%d",&k);
	  switch(k)
	    {
	    case 1:request(m,n);
          break;
	    case 2:check_request_status(m,n);
	      break;
	   case 3:printf("Total leave:%d",l);
	   sec_select(m,n);
	      break;
	    case 4:view_routine(m,n);
	      break;
	    case 5:give_salary(m,n);
	      break;
	    case 6:  fclose(fp);
	      selecter(m,n);
	      break;
	    default:
	      printf("choose correct option\n");
	      sec_select(m,n);
	    }
	}
      fclose(fp);
    }
}
void request(int m,int n)
{char r[N],i[N];
FILE *fp=fopen("leave.txt","w+"); 
      printf("Enter employee id:\n");
      scanf("%s",i);
      printf("Enter reason\n");
      scanf("%s",r);
     fprintf(fp,"id no:%s\nreason:%s",i,r);
      fclose(fp);
      printf("\t\t\tRequested Successfully\n");
      sec_select(m,n);
}
void sec_select(int m,int n)
{printf("Enter your choice.\n 1.Request leave\t2.Check request status\t3.Total leaves\t4.View Routine\t5.Salary\t6.logout\n");int l;
	 int k; scanf("%d",&k);
	  switch(k)
	    {
	    case 1:request(m,n);
          break;
	    case 2:check_request_status(m,n);
	      break;
	   case 3:selecter(m,n);
	      break;
	    case 4:view_routine(m,n);
	    break;
	    case 5:give_salary(m,n);
	      break;
	    case 6: selecter(m,n);
	      break;
	    default:
	      printf("choose correct option\n");
	      sec_select(m,n);
}}

void view_routine(int m,int n)
{int h,dd,mm,i=1,j=1,s=0,start,end;
h=(24*n)/m;
printf("Enter today's date and month\n");
scanf("%d%d",&dd,&mm);
printf("Current date:%d.%d.2017\n",dd,mm);
struct time* K=(struct time*)malloc(m*sizeof(struct time));
while(i<m+1)
{printf("for person with id no. :%d at place :%d\n",i+1000,j);
K[i-1].start=(i-1)*h;
K[i-1].end=i*h;
if(K[i-1].start>=24)
K[i-1].start=K[i-1].start%24;
if(K[i-1].end>=24)
K[i-1].end=K[i-1].end%24;
 printf("Start time:%d hrs to End time :%d hrs\n ",K[i-1].start,K[i-1].end);
s=s+h;
if(s>=24)
{j++;
s=s-24;
//if(dd==30)
//{dd=1;
//mm=mm+1;}
//else dd++;
}
i++;
}
printf("\n\n\t");
sec_select(m,n);
}


void check_request_status(int m,int n)
{FILE *fp=fopen("app.txt","r");
char idx[N],pass[N],ns[N];int st,l;
fscanf(fp,"%s\t%d\n",idx,&st);
if(fp==NULL)
    {
      puts("PENDING..Visit after some time\n");
      fclose(fp);
      sec_select(m,n);
    }
fclose(fp);
if(st==1)
{printf("APPROVED\n");
add(idx);
FILE *f=fopen(idx,"r");
fscanf(f,"%s\t%s\t\n",ns,pass,&l);
fclose(f);
l++;
FILE *ft=fopen(idx,"w+");
fprintf(ft,"%s\t%s\t\n",ns,pass,l);
fclose(ft);
}
else printf("NO\n");
sec_select(m,n);
}
void check_request(int m,int n)
{char i[N],id1[N];
int ch;
FILE *fp=fopen("leave.txt","r");
char s[150];
while(!feof(fp)){
	fgets(s,150,fp);
	puts(s);
	}take_action(m,n);
	}

void take_action(int m,int n)
{char id1[N];int ch;
FILE *f=fopen("app.txt","w+");
printf("\t\t Approve or Decline leave request\t\t\n");
printf("\tEnter employee id whose request has to be approve/reject\n");
scanf("%s",id1);
printf("1.YES\t\t2.NO\n");
scanf("%d",&ch);
fprintf(f,"%s\t%d\n",id1,ch);
fclose(f);
m_select(m,n);
}

void m_select(int m,int n)
{ int k;
printf("Enter your choice.\n 1.Create Routine\t2.Check Request\t3.logout\n");
	  scanf("%d",&k);
	  switch(k)
	    {
	   case 1:create_routine(m,n);
	   break;
	    case 2:check_request(m,n);
	      break;
	    case 3:
	      selecter(m,n);
	      break;
	    default:
	      printf("choose correct option\n");
	      m_select(m,n);
	    }
}
void create_routine(int m,int n)
{
int h,dd,mm,i=1,j=1,s=0,start,end;
h=(24*n)/m;
printf("Enter today's date and month\n");
scanf("%d%d",&dd,&mm);
printf("Current date:%d.%d.2017\n",dd,mm);
struct time* T=(struct time*)malloc(m*sizeof(struct time));
while(i<m+1)
{printf("for person with id no. :%d at place :%d\n",i+1000,j);
T[i-1].start=(i-1)*h;
T[i-1].end=i*h;
if(T[i-1].start>=24)
T[i-1].start=T[i-1].start%24;
if(T[i-1].end>=24)
T[i-1].end=T[i-1].end%24;
printf("Start time:%d hrs to End time :%d hrs\n ",T[i-1].start,T[i-1].end);
s=s+h;
if(s>=24)
{j++;
s=s-24;
//if(dd==30)
//{dd=1;
//mm=mm+1;}
//else dd++;
}
i++;
}
printf("\n\n\t");
m_select(m,n);
}

void Mlogin(int m,int n)
{int k;
char a[20],b[20];
  printf("Manager ID:\n");
  scanf("%s",a);
  printf("Password\n");
  scanf("%s",b);
  add(a);
  FILE *fp=fopen(a,"r");
  if(fp==NULL)
    {
      puts("Not Registered.Register first.");
      fclose(fp);
      selecter(m,n);
    }
  else
    {
      fscanf(fp,"%s\t%s\n",name,password);
      if(match(b,password)==0)
	{
	  puts("Wrong Password\n");
	  fclose(fp);
	  selecter(m,n);
	}
      else
	{
	  puts("\t\tlogin successful\n ");
	  fp=fopen(a,"r+");
	 int k;
printf("Enter your choice.\n 1.Create Routine\t2.Check Request\t3.logout\n");
	  scanf("%d",&k);
	  switch(k)
	    {
	   case 1:create_routine(m,n);
	   break;
	    case 2:check_request(m,n);
	      break;
	    case 3:
	      fclose(fp);
	      selecter(m,n);
	      break;
	    default:
	      printf("choose correct option\n");
	      m_select(m,n);
	    }}
 fclose(fp);
    }
}

