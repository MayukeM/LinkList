#include "head.h"

int main(){
    //1.����
    LinkList L;
    //2.��ʼ��
    InitList_L(L);
    //3.����������
    CreateListTail(L, 5);
//    Print_reverse_L(L->next);
    DeleteBetween(L, 1, 4);
    //4.���
    ListTraverse_L(L, visit);
    return 0;
}