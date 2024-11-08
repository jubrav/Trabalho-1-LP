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
Node* particionar(Node* head, Node* end, Node** novoHead, Node** novoEnd) {
    Node* pivot = end;
    Node* anterior = NULL, *cur = head, *tail = pivot;

    while (cur != pivot) {
        if (cur->data < pivot->data) {
            if (*novoHead == NULL) *novoHead = cur;
            anterior = cur;
            cur = cur->next;
        } else {
            if (anterior) anterior->next = cur->next;
            Node* temp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = temp;
        }
    }
    if (*novoHead == NULL) *novoHead = pivot;
    *novoEnd = tail;
    return pivot;
}

Node* quickSortRecur(Node* head, Node* end) {
    if (!head || head == end) return head;

    Node *novoHead = NULL, *novoEnd = NULL;
    Node* pivot = particionar(head, end, &novoHead, &novoEnd);

    if (novoHead != pivot) {
        Node* temp = novoHead;
        while (temp->next != pivot) temp = temp->next;
        temp->next = NULL;

        novoHead = quickSortRecur(novoHead, temp);

        temp = novoHead;
        while (temp->next != NULL) temp = temp->next;
        temp->next = pivot;
    }

    pivot->next = quickSortRecur(pivot->next, novoEnd);
    return novoHead;
}

void quickSort(Node** head) {
    *head = quickSortRecur(*head, *head);
}

/*int main() {
    Node* head = NULL;
    inserirInicio(&head, 4);
    inserirInicio(&head, 1);
    inserirInicio(&head, 3);
    inserirInicio(&head, 2);

    printf("Lista original: ");
    imprimirLista(head);

    quickSort(&head);
    printf("Após Quick Sort: ");
    imprimirLista(head);

    return 0;
}*/