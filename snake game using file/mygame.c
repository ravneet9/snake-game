#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
static int score=0;
struct food{
    char value;
    int x;
    int y;
};
struct food f;
struct node{
    char value;
int x;
int y;
struct node* next;
};
struct node*head;
struct node*tail;
void createsnake(){
int i;
    for(i=1;i<5;i++){
             struct node* temp1=(struct node*)malloc(sizeof(struct node));
        if(head==NULL){

        temp1->value='A';
        temp1->x=4;
        temp1->y=3;
        temp1->next=NULL;
        head=temp1;
            }
            else{
            struct node *temp2=head;
            while(temp2->next!=NULL)
                temp2=temp2->next;
              temp1->value='#';
            temp1->x=(temp2->x)+1;
            temp1->y=temp2->y;
             temp2->next=temp1;
            temp1->next=NULL;}
tail=temp1;
    }
}
void write_file(char arr[25][25],FILE *fp){
    FILE *ifp;
    ifp=fp;
    struct node*temp=head;
    while(temp!=NULL){
            char x=temp->value;
            int y=temp->x;
            int z=temp->y;
        fprintf(fp,"%c %d %d",x,y,z);
temp=temp->next;}
//fputc('\n',fp);

fp=ifp;

}

void increaseLength(){
struct node *temp=head;
score+=10;
while(temp->next!=NULL){
            temp=temp->next;
        }
struct node*temp1=(struct node*)malloc(sizeof(struct node));
                temp1->x=temp->x;
                temp1->y=temp->y;
                temp1->value='#';
 temp->next=temp1;
 temp1->next=NULL;
}
void createfood(char arr[25][25]){
    struct node *temp=head;
    if((temp->x==f.x)&&(temp->y==f.y)){
    f.x=rand()%25;
    f.y=rand()%25;
    arr[f.x][f.y]=f.value;
    increaseLength();
            }
            arr[f.x][f.y]=f.value;
            }
void matrix(char arr[25][25],FILE *fp){
     int j,i;
      struct node *temp=head;
      for(i=0;i<25;i++)
        for(j=0;j<25;j++)
        arr[i][j]=' ';
      //createfood(arr);
   while(temp!=NULL){
arr[temp->x][temp->y]=temp->value;
    temp=temp->next;
   }
   write_file(arr,fp);
}
 void copy(struct node* ptr,int m,int n){
 int i=ptr->x;
 int j=ptr->y;
 ptr->x=m;
 ptr->y=n;
 if(ptr->next!=NULL)
 copy(ptr->next,i,j);
  struct node *temp=head;
 if((temp->x==f.x)&&(temp->y==f.y)){
        while(temp->next!=NULL){
            temp=temp->next;
        }
    struct node*temp1=(struct node*)malloc(sizeof(struct node));
                temp1->x=i;
                temp1->y=j;
                temp1->value=temp->value;
 temp->next=temp1;
 temp1->next=NULL;
 }
 }
void display(char arr[25][25]){
    int i,j;
for(i=0;i<25;i++){
        printf("\n");
    for(j=0;j<25;j++)
    printf("%c",arr[i][j]);
}

}
void read_file(char arr[25][25],FILE *fp){
int y,z;
char x;
   fp=fopen("me.dat","r");

int i=1;
while(fscanf(fp,"%c %d %d",&x,&y,&z)!=EOF){
    struct node*temp1=(struct node*)malloc(sizeof(struct node));
    if(i==1){
temp1->value=x;
temp1->x=y;
temp1->y=z;
temp1->next=head;
head=temp1;
    }
    else{

        struct node*temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp1->value=x;
temp1->x=y;
temp1->y=z;
temp->next=temp1;
temp1->next=NULL;}
i++;
}

}


void func(char arr[25][25],char v,FILE *fp){
    fp=fopen("me.dat","w");
char ch;
 display(arr);

 printf("SCORE:%d",score);
int count=0;
struct node* temp=head;
ch=getch();
system("cls");
if(ch=='w'&&v=='s'||ch=='s'&&v=='w'||ch=='a'&&v=='d'||ch=='d'&&v=='a')
    func(arr,v,fp);
    else{//  display(arr);
switch(ch){
case 'w':
if(arr[temp->x-1][temp->y]=='#'){
    return;}
    copy(temp->next,temp->x,temp->y);
    temp->x=temp->x-1;
    if(temp->x<0)
        temp->x=24;
break;
case 's':
    if(arr[temp->x+1][temp->y]=='#')
    return;
    copy(temp->next,temp->x,temp->y);
    temp->x=temp->x+1;
    if(temp->x>24)
        temp->x=0;
break;
case 'a':
    if(arr[temp->x][temp->y-1]=='#')
    return;
copy(temp->next,temp->x,temp->y);

    temp->y=temp->y-1;
if(temp->y<0)
    temp->y=24;
break;
case 'd':
    if(arr[temp->x][temp->y+1]=='#')
    return;
    copy(temp->next,temp->x,temp->y);
    temp->y=temp->y+1;
if(temp->y>24)
    temp->y=0;
break;
default:
    printf("invalid entry");
    }
matrix(arr,fp);
  createfood(arr);
func(arr,ch,fp);}
}



main(){
    int i,j;
    char arr[25][25];
    for(i=0;i<25;i++)
        for(j=0;j<25;j++)
        arr[i][j]=' ';
head=NULL;
char r;
FILE *fp;
fp=fopen("me.dat","a");
if(fp==NULL){
printf("not found");
return;}
printf(" play resume");
scanf("%c",&r);
if(r=='y'){
    read_file(arr,fp);
}
else{
createsnake();}
f.x=2;
f.y=3;
f.value='@';
//createfood(arr);
matrix(arr,fp);
func(arr,'w',fp);
fclose(fp);
printf("game over!!......FINAL_SCORE=%d",score);
system("pause");
}

