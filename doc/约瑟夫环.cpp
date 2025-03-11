#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;         
    int password;      
    struct Node* next; 
} Node;

Node* create_circular_linked_list(int n, int passwords[]) {
    Node* head = NULL;
    Node* prev = NULL;

    for (int i = 0; i < n; i++) {
        Node* new_node = (Node*)malloc(sizeof(Node));
        new_node->value = i + 1;
        new_node->password = passwords[i];
        new_node->next = NULL;

        if (head == NULL) {
            head = new_node;
        } else {
            prev->next = new_node;
        }
        prev = new_node;
    }

    if (prev != NULL) {
        prev->next = head;
    }

    return head;
}

void josephus(int n, int passwords[], int m) {
    Node* head = create_circular_linked_list(n, passwords);
    Node* current = head;
    Node* prev = NULL;

    printf("出列顺序: ");

    while (current->next != current) {
       		for (int i = 1; i < m; i++) {
       		    prev = current;
       		    current = current->next;
       		}
       		
       		printf("%d ", current->value);
       		
       		m = current->password;
       		
       		prev->next = current->next;
       		Node* temp = current;
       		current = current->next;
       		free(temp);
    }

    printf("%d\n", current->value);
    free(current); 
}

int main() {
    int n = 7;
    int passwords[] = {3, 1, 7, 2, 4, 8, 4};
    int m = 20;

    josephus(n, passwords, m);

    return 0;
}