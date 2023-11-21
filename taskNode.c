// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
struct lnode{
    int data;
    struct lnode* next;
};
typedef struct lnode node;
node* head=NULL;
void insertAtBegining(){
    node* newNode=(node*)malloc(sizeof(node));
    if(newNode ==  NULL){
        printf("Out of Memory");
        return;
    }
    printf("\nenter the Element : ");
    scanf("%d",&newNode->data);
    if(head == NULL){
        newNode->next=NULL;
        head=newNode;
    }
    else{
        newNode->next=head;
        head=newNode;
    }
    printf("inserted %d at the begining .",newNode->data);
}
void display(){
    node* temp=head;
    int i=0;
    if(temp==NULL){
        printf("List are empty ");
        return;
    }
   
    printf("list are : \n");
    while(temp!=NULL){
        printf("| %d | %u |     -->",temp->data,&temp);
      
        temp=temp->next;
        i++;
    }
    printf("\n");
     for(int j=0;j<i;j++){
    printf("-------------------         ");
  
    }
    printf("\n");
    for(int j=0;j<i;j++){
    printf("value |   address |         |");
  
    }
}
void insertAtPostion(int pos,int val){
    int i;
    node* temp=head;
    node* newNode=(node*)malloc(sizeof(node));
    if(newNode==NULL){
        printf("Out of memory...");
        return;
    }
    newNode->data=val;
    for(i=1;i<=pos-1;i++){
        temp=temp->next;
        if(temp==NULL){
            printf("invalit position");
            return;
        }
    }
    newNode->next=temp->next;
    temp->next=newNode;

    
}
void deleteAtPostion(int pos){
    node* temp=head;
    node *pre;
    int i;
    if(pos==0){
        head=head->next;
        free(temp);
            printf("Deleted ");
        return;
    }
    for(int i=0;i<pos;i++){
        pre=temp;
        temp=temp->next;
        if(temp==NULL){
            return;
        }
    }
    pre->next=temp->next;
    free(temp);
        printf("Deleted ");
    
}
void deleteFirstElement(){
    node* temp=head;
    head=head->next;
    free(temp);
    printf("First element deleted ..");
    
}
void search(int pos){
   int i;
   node* temp=head;
   if(pos==0){
       printf("%d",temp->data);
       return;
   }
   for(i=1;i<=pos;i++){
       if(i==pos){
       printf("%d",temp->data);
       return;
       }
       temp=temp->next;
   }
}
int main() {
    int choice,pos,val,i;
    while(1){
    printf("\n-------------------------------------------------\n");
    printf("                Enter your choice  \n");
    printf("\n1.insert at first element         2.Display");
    printf("\n3.insert at Postion               4.delete at Postion   ");
    printf("\n5.delete first element            6.search and view");
    printf("\n-------------------------------------------------\n");
    scanf("%d",&choice);
    switch(choice){
        case 1:
        insertAtBegining();
        break;
        case 2:
        display();
        break;
        case 3:
        printf("\nEnter the position /(start from 0 :)");
        scanf("%d",&pos);
        if(pos<0){
            printf("\nplease enter the correct postion");
        }
        if(pos==0){
            insertAtBegining();
        }
        else{
            printf("\nEnter the value :");
            scanf("%d",&val);
            insertAtPostion(pos,val);
        }
        break;
        case 4:
         printf("\nEnter the position /(start from 0 :)");
        scanf("%d",&pos);
        if(pos<0){
            printf("\nplease enter the correct postion");
        }
        else{
         
            deleteAtPostion(pos);
        }
        break;
        case 5:
        deleteFirstElement();
        break;
        case 6:
          printf("\nEnter the position /(start from 0 :)");
        scanf("%d",&pos);
        if(pos<0){
            printf("\nplease enter the correct postion");
        }
        else{
        search(pos);
        }
        break;
    }
    }
    return 0;
}
