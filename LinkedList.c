#include<stdio.h>
#include<stdlib.h>

struct Node{
  int data;
  struct Node *next;
};

struct linkedlist{
  struct Node *head;
  struct Node *tail;
};

struct Node* createnode(int value){
     struct Node *newnode;
     newnode=malloc(sizeof(struct Node));
     newnode->data=value;
     newnode->next=NULL;

    return newnode;
};
struct linkedlist* createlist(){
    struct linkedlist *list;
    list=malloc(sizeof(struct linkedlist));
    list->head=NULL;
    list->tail=NULL;

    return list;
};
void traverse(struct linkedlist* list){
  struct Node *temp;
  temp=list->head;
  while(temp!=NULL){
    printf("%d ",temp->data);
    temp=temp->next;
  }
  printf("\n");
  return;
}
void insertfront(struct linkedlist* list,int value){
  struct Node *newnode;
  newnode=createnode(value);
  if(list->head==NULL){
    list->head=newnode;
    list->tail=newnode;
  }
  else{
    newnode->next=list->head;
    list->head=newnode;
  }
  return;
}

void insertrear(struct linkedlist* list,int value){
    struct Node *newnode;
    newnode=createnode(value);
    if(list->head==NULL){
    list->head=newnode;
    list->tail=newnode;
  }
  else{
    list->tail->next=newnode;
    list->tail=newnode;
  }
  return;
}
int search(struct linkedlist* list,int value){
   int position=1;
   struct Node *temp=list->head;
   while(temp!=NULL){
    if(temp->data==value){
        return position;
    }
    temp=temp->next;
    position++;
   }
   return -1;
}
void update(struct linkedlist* list,int old,int nev){
  struct Node *node=list->head;
  while (node!=NULL){
    if(node->data==old){
    node->data=nev;
    printf("The value is changed.\n");
    traverse(list);
    return;
    }
    node=node->next;
  }
  return;
}
void insertmid(struct linkedlist* list,int value,int position){
int i=1;
if(position<0){
    printf("The position is no correct");
    return;
}
struct Node *temp=list->head;
    while(temp!=NULL&&i<position-1){
        i++;
        temp=temp->next;
    }
    if(temp==NULL){
        printf("Out of boundry.\n");
        return;
    }
    struct Node *newnode=createnode(value);
    newnode->next=temp->next;
    temp->next=newnode;
    return;
}
void deletefront(struct linkedlist *list){
struct Node *temp=list->head;
if(list->head==NULL){
    printf("The list is empty");
}
list->head=list->head->next;
free(temp);
return;
}

void deleterear(struct linkedlist *list){
struct Node *temp=list->head;
if(list->head==NULL){
    printf("The list is empty");
}
if(list->head==list->tail){
    free(list->head);
    list->head=NULL;
    list->tail=NULL;
    return;
}
while(temp->next->next!=NULL){
    temp=temp->next;
}
free(temp->next);
temp->next=NULL;
list->tail=temp;
return;
}

void deletemid(struct linkedlist *list,int position){
int i=1;
if(list->head==NULL){
    printf("The list is empty");
    return;
}
if(position==1){
    deletefront(list);
    return;
}
if (position<=0){
    printf("ERROR!\n");
    return;
}
struct Node *temp=list->head;
while(temp!=NULL&&i<position-1){
    temp=temp->next;
    i++;
}
if(temp==NULL){
    printf("Invalid\n");
   return;
}
temp->next=temp->next->next;
return;

}


int main(){
struct Node *Node1;
struct Node *Node2;
struct Node *Node3;
struct linkedlist *mylist;
int a;
int b;

Node1=createnode(10);
Node2=createnode(20);
Node3=createnode(30);
mylist=createlist();

Node1->next=Node2;
Node2->next=Node3;
Node3->next=NULL;

mylist->head=Node1;
mylist->tail=Node3;
traverse(mylist);
//insertfront(mylist,50);
//traverse(mylist);
//insertrear(mylist,35);
//traverse(mylist);
//a=search(mylist,50);
//if (a!=-1){
//    printf("The value is at %d",a);
//    return 0;
//}else{
//    printf("The value not found");
//}
//update(mylist,50,60);
//insertmid(mylist,72,3);
//traverse(mylist);
//deletefront(mylist);
//deleterear(mylist);
//deletemid(mylist,3);
traverse(mylist);

return 0;

}
