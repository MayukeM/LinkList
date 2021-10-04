#include "head.h"

//判断带头结点的非空单链表是否递增有序
void Increase(LinkList L){
    LNode *p = L->next, *q;
    while(p->next != NULL){
        q = p->next;
        if(p->data <= q->data)
            p = q;
        else{
            printf("no！\n");
            return;
        }
    }
    printf("yes！\n");
}

//数据域值最小的结点移到链表的最前面
void MoveMin(LinkList L){
    LNode *q = L->next, *pre = L;
    LNode *p = q;
    while(p->next != NULL){
        if(p->next->data < q->data){
            pre = p;
            q = p->next;
        }
        p = p->next;
    }
    if(q != L->next){
        pre->next = q->next;
        q->next = L->next;
        L->next = q;
    }
}

//在递增的整数序列链表（带头结点）中插入一个新整数x，并保持该序列的有序性
Status Insert_LinkList(LinkList L, int x){
    LinkList s = (LinkList) malloc(sizeof (LNode));
    if(!s) return ERROR;
    s->data = x;
    LNode *q = L;
    LNode *p = L->next;
    while(p && p->data <= x){
        q = p;
        p = p->next;
    }
    s->next = p;
    q->next = s;
    return OK;
}

//删除有序单链表中值相同的多余结点
void Purge(LinkList L)
{
    LNode *p = L->next, *q;
    while(p->next != NULL)  //从前向后扫描链表
    {
        q = p->next;
        if(p->data == q->data)   //相邻元素比较，值相同则删除后一个结点
        {
            p->next = q->next;
            free(q);
        }
        else
            p = p->next;
    }
}


//查找倒数第m个结点
int BackLocate(LinkList L, int m){
    LNode *p , *q;
    p = q = L->next;
    int count = 0;
    while(q != NULL)    {
        count++;
        if(count > m)
            p = p->next;
        q = q->next;
    }
    if(m > count)	  //当m大于链表长度时，返回ERROR
        return ERROR;
    return p->data;
}


//有序链表的连续删除
void DeleteBetween(LinkList L, int mink, int maxk){
    LNode *p = L, *q, *u;
    while(p->next && p->next->data <= mink)
        p = p->next;   //p指向第一个大于mink的前驱结点
    if(p->next) {
        q = p->next;    //p不动，q指向操作对象
        while(q->data < maxk)   //依次删除p之后小于maxk的结点
        {
            u = q->next;          //u暂存后继结点的地址
            p->next = q->next;
            free(q);
            q = u;       //指针q后移
        }
    }
}
