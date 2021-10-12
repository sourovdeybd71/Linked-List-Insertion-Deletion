#include <stdio.h>
#include <stdlib.h>

//create a NODE [data, *next] using structure
struct Node{
  int data;
  struct Node* next;
};

//Initializing head & new node (both are pointer)
struct Node* head=NULL;
struct Node* newNode=NULL;

void printList(struct Node* n){
  if(head==NULL){
    printf("List is Empty");
    return;
  }
  while(n!=NULL){
    printf("%d ", n->data);
    n=n->next;
  }
}


//For insert data at first
void insertFirst(int data){
   //enter or initialize new node into list (taking space via malloc)
  newNode= (struct Node*)malloc(sizeof(struct Node));
  newNode->data=data;
  newNode->next=head;

  head=newNode;
}


//For insert data at Last
void insertLast(int data){
  //enter or initialize new node into list (taking space via malloc)
  newNode=(struct Node*)malloc(sizeof(struct Node));
  newNode->data=data;
  newNode->next=NULL;

  if(head==NULL){
    head=newNode;
    return;
  }

  //create a pointer (ptr) that will traverse the list looking for last NODE
  struct Node* ptr=head;
  while(ptr->next!=NULL)
      ptr=ptr->next;
  
  ptr->next=newNode;
}


//For insert data sorted way
void insertSorted(int data){
  if((head==NULL)|| (head->data>data)){
    insertFirst(data);
    return;
  }
  //enter or initialize new node into list (taking space via malloc)
  newNode = (struct Node*) malloc (sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;
  
  //create two pointer (ptr & prePtr) 
  struct Node* prePtr = NULL;
  struct Node* ptr = head;

  while((ptr->next!=NULL) && (ptr->data<data)){
    prePtr=ptr;
    ptr=ptr->next;
  }
  if(ptr->data>data){
    newNode->next=ptr;
    prePtr->next=newNode;
    return;
  }
  ptr->next=newNode;
}


//Deleting from Linked List
void deleteLL(int data){
    if(head==NULL){
        printf("\nEmpty List");
        return;
    }

    if(head->data == data){
        head = head->next;
        return;
    }

    struct Node* prePtr = NULL;
    struct Node* ptr = head;

    while(ptr->data != data){
        if(ptr->next == NULL){
            printf("Item not found\n");
            return;
        }

        prePtr = ptr;
        ptr = ptr->next;

    }

    prePtr->next = ptr->next;
}


int main(void) {
  int num,n;
  printf("--------LINKED LIST---------\n");

  printf("How many numbers you wanna insert? ");
  scanf("%d",&num);

  printf("Insert numbers into Linked List: \n");
  for(int i=0;i<num;i++){
    scanf("%d",&n);
    // insertSorted(n);
    insertFirst(n);
    // insertLast(n);

  }
  printf("Your Inserted Numbers:\n");
  printList(head);

  for(int i=0; i<num; i++){
        printf("\nEnter item to delete: ");
        scanf("%d", &n);
        deleteLL(n);

        printList(head);
    }
  return 0;
}


