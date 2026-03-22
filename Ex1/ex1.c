/******************************************************************************
 * File: assignment4.a
 * * Copyright 2026 Son Tung
 * All Rights Reserved.
 *
 * Author: Son Tung
 * Date: March 22, 2026
 *
 * Description: Chuong trinh thao tac co ban voi Singly Linked List
 * bao gom cac chuc nang:
 * - Hien thi danh sach
 * - Them node vao cuoi
 * - Tim kiem node
 * - Xoa node
 * - Giai phong bo nho
 *
 *****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

// Khai bao cac ham
void display(struct node* head);
struct node* addback(struct node* head, int data);
struct node* find(struct node* head, int data);
struct node* delnode(struct node* head, struct node* pelement);
void freelist(struct node* head);


/******************************************************************************
 * Function: main
 * Description:
 * Ham chinh de test cac chuc nang cua danh sach lien ket.
 * Parameters:
 * None
 * Return:
 * 0 neu chuong trinh chay thanh cong.
 *****************************************************************************/
int main() {
    struct node* head = NULL;

    printf("--- TEST ADD BACK ---\n");
    head = addback(head, 10);
    head = addback(head, 20);
    head = addback(head, 30);
    head = addback(head, 40);
    display(head);

    printf("\n--- TEST FIND ---\n");
    int searchVal = 30;
    struct node* target = find(head, searchVal);
    if (target != NULL) {
        printf("Tim thay phan tu %d tai dia chi %p\n", searchVal, (void*)target);
    } else {
        printf("Khong tim thay phan tu %d\n", searchVal);
    }

    printf("\n--- TEST DELETE NODE (Xoa o giua) ---\n");
    head = delnode(head, target); // Xoa node co gia tri 30
    display(head);

    printf("\n--- TEST DELETE NODE (Xoa Head) ---\n");
    struct node* headNode = find(head, 10);
    head = delnode(head, headNode); // Xoa node co gia tri 10
    display(head);

    printf("\n--- TEST FREE LIST ---\n");
    freelist(head);
    head = NULL; // Tot nhat la set head ve NULL sau khi free

    return 0;
}


/******************************************************************************
 * Function: display
 * Description:
 * In toan bo cac phan tu trong danh sach lien ket ra man hinh.
 * Parameters:
 * struct node* head: Con tro den node dau tien cua danh sach
 * Return:
 * None
 *****************************************************************************/
void display(struct node* head) {
    struct node* current = head;
    printf("Danh sach: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}


/******************************************************************************
 * Function: addback
 * Description:
 * Them mot node moi vao cuoi danh sach lien ket.
 * Parameters:
 * struct node* head: Con tro den node dau tien cua danh sach
 * int data: Gia tri can them vao node moi
 * Return:
 * struct node*: Con tro den node dau danh sach sau khi them
 *****************************************************************************/
struct node* addback(struct node* head, int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    struct node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}


/******************************************************************************
 * Function: find
 * Description:
 * Tim kiem mot phan tu trong danh sach dua tren gia tri data.
 * Parameters:
 * struct node* head: Con tro den node dau tien cua danh sach
 * int data: Gia tri can tim kiem
 * Return:
 * struct node*: Con tro den node chua gia tri tim duoc, hoac NULL neu khong thay
 *****************************************************************************/
struct node* find(struct node* head, int data) {
    struct node* current = head;
    while (current != NULL) {
        if (current->data == data) return current;
        current = current->next;
    }
    return NULL;
}


/******************************************************************************
 * Function: delnode
 * Description:
 * Xoa mot node cu the khoi danh sach lien ket.
 * Parameters:
 * struct node* head: Con tro den node dau tien cua danh sach
 * struct node* pelement: Con tro den node can xoa
 * Return:
 * struct node*: Con tro den node dau danh sach sau khi da xoa
 *****************************************************************************/
struct node* delnode(struct node* head, struct node* pelement) {
    if (head == NULL || pelement == NULL) return head;

    if (head == pelement) {
        struct node* newHead = head->next;
        free(head);
        return newHead;
    }

    struct node* current = head;
    while (current != NULL && current->next != pelement) {
        current = current->next;
    }

    if (current != NULL) {
        current->next = pelement->next;
        free(pelement);
    }
    return head;
}


/******************************************************************************
 * Function: freelist
 * Description:
 * Giai phong toan bo bo nho da cap phat cho cac node trong danh sach.
 * Parameters:
 * struct node* head: Con tro den node dau tien cua danh sach
 * Return:
 * None
 *****************************************************************************/
void freelist(struct node* head) {
    struct node* current = head;
    struct node* nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    printf("Da giai phong toan bo danh sach.\n");
}
