#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;

void addNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    if (head == NULL) {
        head = newNode;
        head->next = head;
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}

void modifyNode(int oldData, int newData) {
    Node* temp = head;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    do {
        if (temp->data == oldData) {
            temp->data = newData;
            printf("Data modified successfully.\n");
            return;
        }
        temp = temp->next;
    } while (temp != head);
    printf("Data not found.\n");
}

void deleteNode(int data) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node *temp = head, *prev;
    if (temp->data == data) {
        if (temp->next == head) {
            head = NULL;
            free(temp);
            printf("Node deleted successfully.\n");
            return;
        } else {
            Node* last = head;
            while (last->next != head) {
                last = last->next;
            }
            head = temp->next;
            last->next = head;
            free(temp);
            printf("Node deleted successfully.\n");
            return;
        }
    }
    while (temp->next != head && temp->next->data != data) {
        temp = temp->next;
    }
    if (temp->next == head) {
        printf("Data not found.\n");
    } else {
        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        free(toDelete);
        printf("Node deleted successfully.\n");
    }
}

void displayList() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    int choice, data, newData;
    while (1) {
        printf("1 to add data\n2 to modify data\n3 to display data\n4 to delete data\n5 to exit\n enter: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data to add: ");
                scanf("%d", &data);
                addNode(data);
                break;
            case 2:
                printf("Enter old data to modify: ");
                scanf("%d", &data);
                printf("Enter new data: ");
                scanf("%d", &newData);
                modifyNode(data, newData);
                break;
            case 3:
                displayList();
                break;
            case 4:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                deleteNode(data);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
