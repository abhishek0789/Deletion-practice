#include <stdio.h>
#include<stdlib.h>

struct node {
int data;
struct node *next;
}; 

struct node *GetData(struct node *head, int size){
  struct node *ptr = head;
  for(int i = 0; i < size-1; i++){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    printf("\nenter %d element ", i+2);
    scanf("%d", &temp->data);
    ptr->next = temp;
    temp->next = NULL;
    ptr = temp;
  }
  return head;
  
}


struct node *deletionAtFirst(struct node *head){
  struct node *ptr = head;
  head = ptr->next; 
  free(ptr);

  return head;
}

struct node *deletionInBetween(struct node* head, int index){
  struct node *p = head;
  struct node *q = head->next;
  for(int i = 0 ; i< index-1; i++){
    p = p->next;
    q = q->next;
  }

 p->next = q->next;
free(q);
return head;
}

struct node *deletionAtEnd(struct node *head){
  struct node *p = head;
  struct node *q = head->next;
  while(q->next != NULL){
p = p->next; 
q = q->next;
}
p->next = NULL;
  free(q);
return head;
} 

struct node *deletionGivenValue(struct node *head , int value){
  struct node *p = head;
  struct node *q = head->next;

  while(q->data != NULL && q->data != value){
    p = p->next;
    q = q->next;
  }
  p->next = q->next;
  free(q);
  return head;
}


void display(struct node *head){
  struct node *ptr = head;
  while( ptr!= NULL){
    printf("\n%d", ptr->data);
    ptr = ptr->next;
  }
}

int main(void) {

  int n;
  printf("enter size of liked list");
    scanf("%d", &n);

  struct node *head = (struct node*)malloc(sizeof(struct node));
  

  printf("\nenter 1 element : ");
  scanf("%d", &head->data);

  head = GetData(head,n);
  
int option;
  printf("\nenter 1 if you want to perform deletion \nenter 0 if you don't want to");
  scanf("%d", &option);
  if(option == 1){
    int choose;
    printf("\enter 1 to perform deletion at first postion \nenter 2 to perform deletion at index \nenter 3 to perform deletion at end position \nenter 4 to perform deletion with given value : \n");
    scanf("%d", &choose); 
    printf("\nlinked list before deletion : \n");
    display(head); 

    printf("\n Linked list after Deletion : ");
    if(choose == 1){
      head = deletionAtFirst(head);
    } 

    else if(choose == 2){
      int index;
  printf("enter index: "); 
  scanf("%d", &index);
  head = deletionInBetween(head, index);
    } 

    else if(choose == 3){
     head = deletionAtEnd(head); 
    } 

    else if(choose== 4){
     int value;
  printf("\nenter value you want to delete: ");
  scanf("%d", &value);
    
  head = deletionGivenValue(head , value); 
    } 

    else{
      printf("wrong input");
  }

  display(head); 
  } 
else if( option == 0){
  printf("ok so here is your linked list");
  display(head);
}

  return 0;
}