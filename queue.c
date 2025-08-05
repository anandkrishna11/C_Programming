#include <stdio.h>
#define max 5
int queue[max];
int front=-1;
int rear=-1;
void enqueue(int value){
    if (rear == (max-1)){
        printf("OverFlow ! Queue is Full.");
    }
    else{
        if(front== -1){
            front = 0 ;
        }
        rear=rear+1;
        queue[rear]=value;
        printf("Element added sucessfully!");
    }
}
void dequeue(){
    if (front == -1 || rear<front){
        printf("Underflow! Nothing to remove.");
    }
    if (front > rear) {
            front = -1;
            rear = -1;
    }
    else{
        front=front+1;
        printf("dequeue operation successfull!");
    }
}
void display(){
    if(front== -1 || rear<front){
        printf("No elements to display!");
    }
    else{
        for (int i=front;i<=rear;i++){
            printf("%d \n",queue[i]);
        }
    }
}
int main(){
    while(1){
        int choice,value;
        printf("1.enqueue \n 2.dequeue \n 3.display \n 4.exit");
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        if (choice==1){
            printf("\nEnter the value to be added to the queue:");
            scanf("%d",&value);
            enqueue(value);
        }
        else if(choice == 2){
            dequeue();
        }
        else if(choice==3){
            display();
        }
        else if(choice==4){
            printf("END!");
            break;
        }
        else{
            printf("Choose a valid option!");
        }
    }
    return 0;
}
