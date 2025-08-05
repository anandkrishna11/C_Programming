#include <stdio.h>
#define max 5

int front = -1;
int rear = -1;
int cque[max];

void encque(int value) {
    if ((rear + 1) % max == front) {
        printf("OverFlow!\n");
        return;
    }

    if (front == -1) { 
        front = 0;
        rear = 0;
    } else {
        rear = (rear + 1) % max;
    }

    cque[rear] = value;
    printf("Inserted %d\n", value);
}

void decque() {
    if (front == -1) { 
        printf("UnderFlow\n");
        return;
    }

    int data = cque[front];
    if (front == rear) { 
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % max;
    }

    printf("Deleted %d\n", data);
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", cque[i]);
        if (i == rear)
            break;
        i = (i + 1) % max;
    }
    printf("\n");
}

int main() {
	while(1){
    		int choice,value;
    		printf("1.Insert \n 2.Delete \n3.display \n4.exit");
    		printf("Enter your choice:\n");
    		scanf("%d",&choice);
    		if (choice==1){
    			printf("Enter the element to add:");
    			scanf("%d",&value);
    			encque(value);
    		}
    		else if(choice==2){
    			decque();
    		}
    		else if(choice==3){
    			display();
    		}
    		else if(choice==4){
    			printf("END");
    			break;
    		}
    		else{
    			printf("Not a valid choice!");
    		}
    }
}

