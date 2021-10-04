#include "head.h"

//1
void Del_x_1(LinkList &L, ElemType x) {
    LNode *p;
    if (L == NULL) return;
    if (L->data == x) {
        p = L;
        L = L->next;
        free(p);
        Del_x_1(L, x);
    } else
        Del_x_1(L->next, x);
}

//2.1
void Del_x_2(LinkList &L, ElemType x) {
    LNode *p = L->next, *pre = L, *q;
    while (p != NULL) {
        if (p->data == x) {
            q = p;
            p = p->next;
            pre->next = p;
            free(q);
        } else {
            pre = p;
            p = p->next;
        }
    }
}


void R_Print(LinkList L) {
    if (L->next != NULL) {
        R_Print(L->next);
    }
    printf("%d ", L->data);
}

//3
//1 2 3
void Print_reverse_L(LinkList L) {
    if (L->next != NULL) {//1
//        Print_reverse_L(L->next);
        if (L->next->next != NULL) {//2
//            Print_reverse_L(L->next->next);
            if (L->next->next->next != NULL){//3
//                Print_reverse_L(L->next->next->next);
                if(L->next->next->next->next != NULL){
                    Print_reverse_L(L->next->next->next->next);
                }
                if(L->next->next->next != NULL)
                    printf("%d ", L->next->next->next->data);//输出3
            }
            if (L->next->next != NULL)
                printf("%d ", L->next->next->data);//输出2
        }
        if (L->next != NULL)
            printf("%d ", L->next->data);//输出1
    }
    if (L != NULL)
        printf("%d ", L->data);//输出data
}

//4
LinkList Delete_Min(LinkList &L) {
    LNode *pre = L, *p = pre->next;
    LNode *minpre = pre, *minp = p;
    while (p != NULL) {
        if (p->data < minp->data) {
            minp = p;
            minpre = pre;
        }
        pre = p;
        p = p->next;
    }
    minpre->next = minp->next;
    free(minp);
    return L;
}


//5
void Reverse_L_1(LinkList &L) {
    LNode *p, *r;
    p = L->next;
    L->next = NULL;
    while (p != NULL) {
        r = p->next;
        p->next = L->next;
        L->next = p;
        p = r;
    }
}
