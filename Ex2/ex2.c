/******************************************************************************
 * File: ex2.c
 * * Copyright 2026 Son Tung
 * All Rights Reserved.
 *
 * Author: Son Tung
 * Date: March 22, 2026
 *
 * Description: Chuong trinh thao tac voi Cay nhi phan tim kiem (BST)
 * bao gom cac chuc nang:
 * - Cap phat node moi (talloc)
 * - Them node vao cay (addnode)
 * - Duyet cay theo thu tu Pre-order
 * - Duyet cay theo thu tu In-order (hien thi danh sach da sap xep)
 * - Xoa toan bo cay (deltree) va dem so node da xoa
 *
 *****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct tnode {
    int data;
    struct tnode* left;
    struct tnode* right;
};

// Khai bao cac ham
struct tnode* talloc(int data);
struct tnode* addnode(struct tnode* root, int data);
void preorder(struct tnode* root);
void inorder(struct tnode* root);
int deltree(struct tnode* root);

/******************************************************************************
 * Function: main
 * Description:
 * Ham chinh de test cac chuc nang cua Cay nhi phan tim kiem.
 * Thuc hien chen cac phan tu: 3, 1, 0, 2, 8, 6, 5, 9.
 * Parameters:
 * None
 * Return:
 * 0 neu chuong trinh chay thanh cong.
 *****************************************************************************/
int main() {
    struct tnode* root = NULL;
    int elements[] = {3, 1, 0, 2, 8, 6, 5, 9};
    int n = sizeof(elements) / sizeof(elements[0]);

    printf("--- CHEN CAC PHAN TU VAO CAY ---\n");
    printf("Thu tu chen: 3, 1, 0, 2, 8, 6, 5, 9\n");
    for (int i = 0; i < n; i++) {
        root = addnode(root, elements[i]);
    }

    printf("\n--- DUYET CAY THEO PRE-ORDER TRAVERSAL ---\n");
    preorder(root);
    printf("\n");

    printf("\n--- DUYET CAY THEO IN-ORDER TRAVERSAL (Sorted) ---\n");
    inorder(root);
    printf("\n");

    printf("\n--- XOA TOAN BO CAY (POST-ORDER) ---\n");
    int deletedNodes = deltree(root);
    printf("Tong so node da giai phong: %d\n", deletedNodes);
    root = NULL;

    return 0;
}

/******************************************************************************
 * Function: talloc
 * Description:
 * Cap phat bo nho cho mot node moi voi gia tri data cho truoc.
 * Parameters:
 * int data: Gia tri can luu vao node moi
 * Return:
 * struct tnode*: Con tro den node moi duoc cap phat
 *****************************************************************************/
struct tnode* talloc(int data) {
    struct tnode* newNode = (struct tnode*)malloc(sizeof(struct tnode));
    if (newNode != NULL) {
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}

/******************************************************************************
 * Function: addnode
 * Description:
 * Them mot node vao Cay nhi phan tim kiem (BST).
 * Parameters:
 * struct tnode* root: Con tro den goc cua cay
 * int data: Gia tri can chen
 * Return:
 * struct tnode*: Con tro den goc cua cay sau khi chen
 *****************************************************************************/
struct tnode* addnode(struct tnode* root, int data) {
    if (root == NULL) {
        return talloc(data);
    }
    if (data < root->data) {
        root->left = addnode(root->left, data);
    } else if (data > root->data) {
        root->right = addnode(root->right, data);
    }
    return root;
}

/******************************************************************************
 * Function: preorder
 * Description:
 * Duyet va hien thi cac phan tu theo thu tu Pre-order.
 * Parameters:
 * struct tnode* root: Con tro den goc cua cay
 * Return:
 * None
 *****************************************************************************/
void preorder(struct tnode* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

/******************************************************************************
 * Function: inorder
 * Description:
 * Duyet va hien thi cac phan tu theo thu tu In-order (Sorted).
 * Parameters:
 * struct tnode* root: Con tro den goc cua cay
 * Return:
 * None
 *****************************************************************************/
void inorder(struct tnode* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

/******************************************************************************
 * Function: deltree
 * Description:
 * Giai phong toan bo bo nho cua cay bang cach duyet Post-order.
 * Parameters:
 * struct tnode* root: Con tro den goc cua cay
 * Return:
 * int: Tong so node da duoc xoa
 *****************************************************************************/
int deltree(struct tnode* root) {
    if (root == NULL) {
        return 0;
    }
    int count = deltree(root->left) + deltree(root->right);
    free(root);
    return count + 1;
}
