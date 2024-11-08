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
void bubbleSort(Node* head) {
    Node* ptr;
    int trocou;

    if (head == NULL) return;

    do {
        trocou = 0;
        ptr = head;

        while (ptr->next != NULL) {
            if (ptr->data > ptr->next->data) {
                int temp = ptr->data;
                ptr->data = ptr->next->data;
                ptr->next->data = temp;
                trocou = 1;
            }
            ptr = ptr->next;
        }
    } while (trocou);
}

/*int main() {
    Node* head = NULL;
    inserirInicio(&head, 4);
    inserirInicio(&head, 1);
    inserirInicio(&head, 3);
    inserirInicio(&head, 2);

    printf("Lista original: ");
    imprimirLista(head);

    bubbleSort(head);
    printf("Após Bubble Sort: ");
    imprimirLista(head);

    return 0;
}*/