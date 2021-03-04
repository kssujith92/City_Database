# include <stdio.h>
# include <string.h>
# include <math.h>

typedef struct
{
char n[100][25];
int x[100],y[100];
int l;
}city;

city insert(city);
city delete(city);
int nsearch(city, char [25]);
int csearch(city,int,int);
city remov(city,int);
void printall(city);
void display(city,int);
void find(city);
void sort(int *,int *);
void look(city,int,int,int,int);
void saveto(city);

void main()
{
city c;
int s=0,i=0;
char a[5][25]={"Thopramkudy","New Delhi","San Francisco","Kolkata","Nedumkandam"};
int x[5]={55,88,77,66,323};
int y[5]={55,-45,-164,34,5};
for(i=0;i<5;i++)
{
strcpy(c.n[i],a[i]);
c.x[i]=x[i];
c.y[i]=y[i];
}
c.l = i;
while (s!=-1)
{
printf("\n CITY DATABASE MENU - Select a Number \n 1. New Entry\n 2. Delete Item\n 3. Save to File\n 4. Print All\n 5. Find Cities\n  -1. Exit\n");
scanf("%d",&s);
switch (s)
{
case 1: c = insert(c);
break;
case 2: 
if (c.l==0)
printf("Database Empty\n");
else
c = delete(c);
break;
case 3:
if (c.l==0)
printf("Database Empty\n");
else
saveto(c);
break;
case 4: 
if (c.l==0)
printf("Database Empty\n");
else
printall(c);
break;
case 5:  
if (c.l==0)
printf("Database Empty\n");
else
find(c);
break;
case -1: printf("Bye :) Thank You\n\n");
break;
default: printf("Invalid choice :( Try Again \n\n");
break;
}
}
}

city insert(city c)
{
int sl,p1,p2,x,y;
char a[25];
printf("Enter the name of the city: ");
while ( getchar() != '\n' );
fgets(a,25,stdin);
sl= strlen(a);
a[sl-1] = '\0';
p1=nsearch(c,a);
printf("Enter the latitude and longitude: ");
scanf("%d%d",&x,&y);
if(x>90 || x<-90 || y>180 || y<-180)
{
printf("Invalid coordinates\nBack to main menu\n");
return c;
}
p2=csearch(c,x,y);
if(p1==-1)
if(p2==-1)
{
strcpy(c.n[c.l],a);
c.x[c.l]=x;
c.y[c.l]=y;
printf("Entry added :) \n");
c.l += 1;
}
else
{
printf("Sorry, The coordinates already exists :)\n");
display(c,p2);
}
else
{
printf("Sorry, The name already exists :)\n");
display(c,p1);
}
return c;
}

void printall(city c)
{
int i;
printf("Sl.No.\t\tCity Name\t\tLatitude  Longitude\n");
for (i=0;i<c.l;i++)
display(c,i);
return;
}

void display(city c, int p)
{
printf("  %d%25s\t\t  %d\t  %d\n",p+1,c.n[p],c.x[p],c.y[p]);
return;
}

void find(city c)
{
int x1,x2,y1,y2,i,v,p,sl;
char a[25];
printf("\n Find Menu - Select a Number \n 1. Between two latitudes\n 2. Between two longitudes\n 3. Between two set of coordinates\n 4. By Name\n  -1. Return to main menu\n");
scanf("%d",&v);
switch (v)
{
case 1:
printf("Enter two latitudes: ");
scanf("%d%d",&x1,&x2);
sort(&x1,&x2);
look(c,x1,x2,-180,180);
break;
case 2:
printf("Enter two longitudes: ");
scanf("%d%d",&y1,&y2);
sort(&y1,&y2);
look(c,-90,90,y1,y2);
break;
case 3:
printf("Enter two latitudes: ");
scanf("%d%d",&x1,&x2);
sort(&x1,&x2);
printf("Enter two longitudes: ");
scanf("%d%d",&y1,&y2);
sort(&y1,&y2);
look(c,x1,x2,y1,y2);
break;
case 4:
printf("Enter the name of the city: ");
while ( getchar() != '\n' );
fgets(a,25,stdin);
sl= strlen(a);
a[sl-1] = '\0';
p=nsearch(c,a);
if (p!=-1)
display(c,p);
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

void look(city c,int x1,int x2,int y1,int y2)
{
int i,t=0;
if(x1>90 || x1<-90 || x2>90 || x2<-90 || y1>180 || y1<-180 || y2>180 || y2<-180)
{
printf("Invalid coordinates\nBack to main menu\n");
return;
}
for(i=0;i<c.l;i++)
if (c.x[i]<=x2 && c.x[i]>=x1 && c.y[i]<=y2 && c.y[i]>=y1)
{
t+=1;
display(c,i);
}
if (t==0)
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

city delete(city c)
{
int v,sl,x,y,p=-1;
char a[25];
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
p = nsearch(c,a);
break;
case 2:
printf("Enter the latitude and longitude: ");
scanf("%d%d",&x,&y);
p = csearch(c,x,y);
break;
case -1: printf("Back to the main menu\n");
break;
default: printf("Invalid choice :( Back to the main menu \n");
break;
}
if (p!=-1)
{
c = remov(c,p);
printf("Entry deleted\n");
c.l=c.l-1;
}
else if (v==1 || v==2)
printf("No such Entry found :(\nBack to the main menu\n");
return c;
}

int csearch(city c,int x,int y)
{
int p=-1,i;
for(i=0;i<c.l;i++)
if (x==c.x[i] && y==c.y[i])
{
p=i;
break;
}
return p;
}

int nsearch(city c, char a[25])
{
int p=-1,i,j,f;
for(i=0;i<c.l;i++)
{
f=1;
if (strlen(a)==strlen(c.n[i]))
{
f=0;
for (j=0;j<strlen(a);j++)
if (a[j] != c.n[i][j])
f=1;
}
if(f==0)
{
p=i;
break;
}
}
return p;
}

city remov(city c,int p)
{
int i;
for (i=p;i<c.l-1;i++)
{
strcpy(c.n[i],c.n[i+1]);
c.x[i] = c.x[i+1];
c.y[i] = c.y[i+1];
}
c.l = c.l-1;
return c;
}

void saveto(city c)
{
FILE *p;
int i;
p=fopen("city_database.dat","w");
for(i=0;i<c.l;i++)
fprintf(p,"%s\t%d\t%d\n",c.n[i],c.x[i],c.y[i]);
fclose(p);
printf("Data saved to 'city_database.dat'\n");
return;
}
