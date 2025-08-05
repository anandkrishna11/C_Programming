#include <stdio.h>
#define MAX 5
int deque[MAX];
int front = -1, rear = -1;

int isFull() {
    return ((front == 0 && rear == MAX - 1) || (front == rear + 1));
}
int isEmpty() {
    return front == -1;
}
void insertFront(int item) {
    if (isFull()) {
        printf("Deque is full!\n");
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else if (front == 0) {
        front = MAX - 1;
    } else {
        front--;
    }
    deque[front] = item;
}
void insertRear(int item) {
    if (isFull()) {
        printf("Deque is full!\n");
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else if (rear == MAX - 1) {
        rear = 0;
    } else {
        rear++;
    }
    deque[rear] = item;
}
void deleteFront() {
    if (isEmpty()) {
        printf("Deque is empty! Nothing to delete.\n");
        return;
    }
    printf("Deleted from front: %d\n", deque[front]);
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}
void deleteRear() {
    if (isEmpty()) {
        printf("Deque is empty! Nothing to delete.\n");
        return;
    }
    printf("Deleted from rear: %d\n", deque[rear]);
    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = MAX - 1;
    } else {
        rear--;
    }
}
void displayDeque() {
    if (isEmpty()) {
        printf("Deque is empty!\n");
        return;
    }
    printf("Deque contents: ");
    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}
int main() {
    int choice, value, direction;
    printf("Double Ended Queue (Deque) Operations\n");
    while (1) {
        printf("\nChoose operation:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                if (isFull()) {
                    printf("Deque is full!\n");
                    break;
                }
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Insert at 1.Front or 2.Rear? ");
                scanf("%d", &direction);
                if (direction == 1) {
                    insertFront(value);
                } else if (direction == 2) {
                    insertRear(value);
                } else {
                    printf("Invalid direction! Try again.\n");
                }
                break;
            case 2:
                if (isEmpty()) {
                    printf("Deque is empty! Nothing to delete.\n");
                    break;
                }
                printf("Delete from 1.Front or 2.Rear? ");
                scanf("%d", &direction);
                if (direction == 1) {
                    deleteFront();
                } else if (direction == 2) {
                    deleteRear();
                } else {
                    printf("Invalid direction! Try again.\n");
                }
                break;
            case 3:
                displayDeque();
                break;
            case 4:
                printf("END!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
