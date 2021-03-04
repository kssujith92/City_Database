# include <stdio.h>
# include <string.h>
# include <stdlib.h>

typedef struct node
{
char a[25];
int x,y;
struct node *n;
}city;

void insert(struct node *);
void add(struct node *,char [25],int,int);
void delete(struct node *);
int nsearch(struct node *,char [25]);
int csearch(struct node *,int,int);
void remov(struct node *,int);
void printall(struct node *);
void display(struct node *,int);
void find(struct node *);
void sort(int *,int *);
void look(struct node *,int,int,int,int);
void saveto(struct node *);

void main()
{
struct node *h,*t;
t=h;
t->n=NULL;
int s=0,i;
char a[5][25]={"Thopramkudy","New Delhi","San Francisco","Kolkata","Nedumkandam"};
int x[5]={55,88,77,66,32};
int y[5]={55,-45,-164,34,5};
for(i=0;i<5;i++)
{
add(t,a[i],x[i],y[i]);
}
while (s!=-1)
{
h=t;
printf("\n CITY DATABASE MENU - Select a Number \n 1. New Entry\n 2. Delete Item\n 3. Save to File\n 4. Print All\n 5. Find Cities\n  -1. Exit\n");
scanf("%d",&s);
switch (s)
{
case 1: insert(h);
break;
case 2: 
if (h->n==NULL)
printf("Database empty :(\n");
else
delete(h);
break;
case 3:
if (h->n==NULL)
printf("Database empty :(\n");
else
saveto(h);
break;
case 4:
if (h->n==NULL)
printf("Database empty :(\n");
else
printall(h);
break;
case 5:
if (h->n==NULL)
printf("Database empty :(\n");
else
find(h);
break;
case -1: printf("Bye :) Thank You\n\n");
break;
default: printf("Invalid choice :( Try Again \n\n");
break;
}
}
}

void insert(struct node *h)
{
int sl,p1,p2,x,y;
char a[25];
struct node *t;
t=h;
printf("Enter the name of the city: ");
while ( getchar() != '\n' );
fgets(a,25,stdin);
sl= strlen(a);
a[sl-1] = '\0';
p1=nsearch(t,a);
t=h;
printf("Enter the latitude and longitude: ");
scanf("%d%d",&x,&y);
if(x>90 || x<-90 || y>180 || y<-180)
{
printf("Invalid coordinates\nBack to main menu\n");
return;
}
p2=csearch(t,x,y);
t=h;
if(p1==-1)
if(p2==-1)
{
add(t,a,x,y);
printf("Entry added :) \n");
}
else
{
printf("Sorry, The coordinates already exists :)\n");
display(t,p2);
}
else
{
printf("Sorry, The name already exists :)\n");
display(t,p1);
}
return;
}

void add(struct node *t,char a[25],int x,int y)
{
while(t->n!=NULL)
t=t->n;
t->n=(struct node *)malloc(sizeof(struct node));
t=t->n;
strcpy(t->a,a);
t->x=x;
t->y=y;
t->n=NULL;
return;
}

void printall(struct node *t)
{
int i=0;
if(t->n==NULL)
printf("The Database is empty\n");
else
{
printf("Sl.No.\t\tCity Name\t\tLatitude  Longitude\n");
while(t->n!=NULL)
{
t=t->n;
printf("  %d%25s\t\t  %d\t  %d\n",i+1,t->a,t->x,t->y);
i+=1;
}
}
return;
}

void display(struct node *t,int p)
{
int i;
for(i=0;i<=p;i++)
t=t->n;
printf("  %d%25s\t\t  %d\t  %d\n",p+1,t->a,t->x,t->y);
return;
}

void find(struct node *h)
{
int x1,x2,y1,y2,i,v,p,sl;
char a[25];
printf("\n Find Menu - Select a Number \n 1. Between two latitudes\n 2. Between two longitudes\n 3. Between two set of coordinates\n 4. Find by Name\n  -1. Return to main menu\n");
scanf("%d",&v);
switch (v)
{
case 1:
printf("Enter two latitudes: ");
scanf("%d%d",&x1,&x2);
sort(&x1,&x2);
look(h,x1,x2,-180,180);
break;
case 2:
printf("Enter two longitudes: ");
scanf("%d%d",&y1,&y2);
sort(&y1,&y2);
look(h,-90,90,y1,y2);
break;
case 3:
printf("Enter two latitudes: ");
scanf("%d%d",&x1,&x2);
sort(&x1,&x2);
printf("Enter two longitudes: ");
scanf("%d%d",&y1,&y2);
sort(&y1,&y2);
look(h,x1,x2,y1,y2);
break;
case 4:
printf("Enter the name of the city: ");
while ( getchar() != '\n' );
fgets(a,25,stdin);
sl= strlen(a);
a[sl-1] = '\0';
p=nsearch(h,a);
if (p!=-1)
display(h,p);
else
printf("No matches found\n Back to main menu\n");
break;
case -1: printf("Back to main menu\n");
break;
default: printf("Invalid choice :( Back to main menu \n");
break;
}
return;
}

void look(struct node *t,int x1,int x2,int y1,int y2)
{
int i=0,f=0;
struct node *h;
h=t;
if(x1>90 || x1<-90 || x2>90 || x2<-90 || y1>180 || y1<-180 || y2>180 || y2<-180)
{
printf("Invalid coordinates\nBack to main menu\n");
return;
}
while (t->n!=NULL)
{
t=t->n;
if (t->x<=x2 && t->x>=x1 && t->y<=y2 && t->y>=y1)
{
f+=1;
display(h,i);
}
i++;
}
if (f==0)
printf("No matches found :(\n Back to the main menu\n");
return;
}

void sort(int *p1,int *p2)
{
int t;
if(*p1>*p2)
{
t = *p1;
*p1 = *p2;
*p2 = t;
}
return;
}

void delete(struct node *h)
{
int v,sl,x,y,p=-1;
char a[25];
struct node *t;
t=h;
printf(" Delete MENU :-\n To delete by name, Enter 1\n To delete by coordinates, Enter 2\n To go back to the main menu, Enter -1\n");
scanf("%d",&v);
switch (v)
{
case 1:
printf("Enter the name of the city: ");
while ( getchar() != '\n' );
fgets(a,25,stdin);
sl= strlen(a);
a[sl-1] = '\0';
p = nsearch(h,a);
break;
case 2:
printf("Enter the latitude and longitude: ");
scanf("%d%d",&x,&y);
p = csearch(h,x,y);
break;
case -1: printf("Back to the main menu\n");
break;
default: printf("Invalid choice :( Back to the main menu \n");
break;
}
h=t;
if (p!=-1)
{
remov(h,p);
printf("Entry deleted\n");
}
else if (v==1 || v==2)
printf("No such Entry found :(\nBack to the main menu\n");
return;
}

int csearch(struct node *t,int x,int y)
{
int p=-1,i=0;
t=t->n;
while(t!=NULL)
{
if (x==t->x && y==t->y)
{
p=i;
break;
}
i++;
t=t->n;
}
return p;
}

int nsearch(struct node *t,char a[25])
{
int p=-1,i=0,j,f;
t = t->n;
while(t!=NULL)
{
f=1;
if (strlen(a)==strlen(t->a))
{
f=0;
for (j=0;j<strlen(a);j++)
if (a[j] != t->a[j])
f=1;
}
if(f==0)
{
p=i;
break;
}
i++;
t=t->n;
}
return p;
}

void remov(struct node *t,int pos)
{
struct node *p;
int i;
for (i=0;i<=pos;i++)
{
p=t;
t=t->n;
}
p->n=t->n;
free(t);
return;
}

void saveto(struct node *c)
{
FILE *p;
p=fopen("city_database.dat","w");
while(c->n != NULL)
{
c=c->n;
fprintf(p,"%s\t%d\t%d\n",c->a,c->x,c->y);
}
fclose(p);
printf("Data saved to 'city_database.dat'\n");
return;
}
