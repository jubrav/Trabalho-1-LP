#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void inserirInicio(Node** head, int data) {
    Node* novo_no = (Node*)malloc(sizeof(Node));
    novo_no->data = data;
    novo_no->next = *head;
    *head = novo_no;
}

void imprimirLista(Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}
void insertionSort(Node** head) {
    Node* sorted = NULL;
    Node* current = *head;

    while (current != NULL) {
        Node* next = current->next;

        if (sorted == NULL || sorted->data >= current->data) {
            current->next = sorted;
            sorted = current;
        } else {
            Node* temp = sorted;
            while (temp->next != NULL && temp->next->data < current->data) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }
    *head = sorted;
}

/*int main() {
    Node* head = NULL;
    inserirInicio(&head, 4);
    inserirInicio(&head, 1);
    inserirInicio(&head, 3);
    inserirInicio(&head, 2);

    printf("Lista original: ");
    imprimirLista(head);

    insertionSort(&head);
    printf("Após Insertion Sort: ");
    imprimirLista(head);

    return 0;
}*/