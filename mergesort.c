#include <stdio.h>
#include <stdlib.h>
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
Node* merge(Node* a, Node* b) {
    if (a == NULL) return b;
    if (b == NULL) return a;

    Node* result;
    if (a->data < b->data) {
        result = a;
        result->next = merge(a->next, b);
    } else {
        result = b;
        result->next = merge(a, b->next);
    }
    return result;
}

void dividir(Node* head, Node** front, Node** back) {
    Node* rapido = head->next;
    Node* lento = head;

    while (rapido != NULL) {
        rapido = rapido->next;
        if (rapido != NULL) {
            lento = lento->next;
            rapido = rapido->next;
        }
    }
    *front = head;
    *back = lento->next;
    lento->next = NULL;
}

void mergeSort(Node** head) {
    if (*head == NULL || (*head)->next == NULL) return;

    Node* a;
    Node* b;
    dividir(*head, &a, &b);

    mergeSort(&a);
    mergeSort(&b);

    *head = merge(a, b);
}

/*int main() {
    Node* head = NULL;
    inserirInicio(&head, 4);
    inserirInicio(&head, 1);
    inserirInicio(&head, 3);
    inserirInicio(&head, 2);

    printf("Lista original: ");
    imprimirLista(head);

    mergeSort(&head);
    printf("Após Merge Sort: ");
    imprimirLista(head);

    return 0;
}*/
