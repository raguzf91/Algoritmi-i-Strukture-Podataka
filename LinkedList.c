#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

//Dupli pokazivač se koristi da bi promjenili vrijednost glave liste
void append(struct Node** head, int newData) {
    //Alociramo memoriju za novi i zadnji čvor
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head;

    newNode->data = newData;
    newNode->next = NULL;

    //provjeravamo je li lista prazna
    //U slučaju da je, novi čvor postaje glava liste
    if(*head == NULL) {
        *head = newNode;
        return;
    } else {
        //Pronalazimo posljednji čvor liste
        while(last->next != NULL) {
            last = last->next;
        }
        //Kada smo na kraju liste, postavljamo pokazivač na newNode
        last->next = newNode;
    }

}

void printList(struct Node* node) {
    while(node != NULL) {
        printf("%d", node->data);
    }
}


void delete(struct Node** head) {
    //Ako je lista prazna, ništa ne brišemo
    if(*head == NULL) {
        return NULL;
    //Ako lista sadrži samo jedan čvor, brišemo head čvor
    } elif((*head)->next == NULL) {
        free(*head);
        *head->next = NULL;
        return NULL;
    } else {
        struct Node* temp = *head;
        struct Node* prev = NULL;

        while(temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }
        free(temp);
        prev->next = NULL;
    }
}

int mean(struct Node* head) {
    int sum = 0;
    int count = 0;

    struct Node* current = head;

    while(current != NULL) {
        sum = sum + current->data;
        count++;
        current = current->next;
    }
    return (float)sum / count;
}

//Funkcija za umetanje elementa na određeni indeks
void insert(struct Node** head, int index, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = NULL;

    if(index == 0) {
        newNode->next = *head;
        *head = newNode;
        return;
    } 

    struct Node* current = *head;
    int i = 0;

    while(current != NULL && i <= index -1) {
        current = current->next;
        i++;
    }
    
    newNode->next = current->next;
    current->next = newNode;
}

//Metoda za spajanje dvije povezane liste
int combineLists(struct Node** head1, struct Node** head2);
int main() {
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;

    append(&head1, 2);
    append(&head1, 4);
    append(&head1, 6);
    append(&head1, 8);
    append(&head2, 3);
    append(&head2, 7);
    append(&head2, 2);
    append(&head2, 10);
    append(&head2, 12);
}

