#include "head.h"

int main(){
    //1.声明
    LinkList L;
    //2.初始化
    InitList_L(L);
    //3.建立单链表
    CreateListTail(L, 5);
//    Print_reverse_L(L->next);
    DeleteBetween(L, 1, 4);
    //4.输出
    ListTraverse_L(L, visit);
    return 0;
}