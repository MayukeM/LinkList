#include <stdio.h>
#include <stdlib.h>

typedef int DataType;//元素类型为整型
typedef struct Node
{
    DataType Data;
    struct Node* Next;
}Node,*LinkList;

void InitList(LinkList* PHead)
{
    if ((*PHead = (LinkList)malloc(sizeof(Node))) == NULL)
    {
        printf("内存分配失败.\n");
        return;
    }
    (*PHead)->Next = NULL;
}

//尾插法建表
void CreatFormTail(LinkList PHead)
{
    Node* s;
    Node* tail;
    DataType data;
    tail = PHead;

    printf("依次输入元素，当输入-1时停止\n");
    scanf("%d", &data);
    while (data != -1)
    {
        s = (Node*)malloc(sizeof(Node));
        s->Data = data;
        s->Next = tail->Next;
        tail->Next = s;
        tail = s;   //tail始终指向表尾
        scanf("%d", &data);
    }
}

//打印表中元素
void PrintList(LinkList PHead)
{
    printf("打印表中元素\n");
    Node* p;
    p = PHead->Next;
    while (p)
    {
        printf("%6d", p->Data);
        p = p->Next;
    }
    printf("\n");
}//递归逆序输出
void printRevList(LinkList pHead){
    if (pHead->Next != NULL)
        printRevList(pHead->Next);

    //if(pHead!=NULL)
    printf("%6d", pHead->Data);


}

//带头结点的链表逆置
void Reverse(LinkList pHead)
{

    //以下两种情况为线性表长度可能为0或1，即如果链表为空，或者链表中只有一个结点则不需要逆置
    if (pHead->Next == NULL || pHead->Next->Next == NULL)
    {
        return;
    }
    Node* p1 = pHead->Next;
    Node* pNext;
    //将头结点与链表断开，构成一个空链表
    pHead->Next = NULL;
    //当p1!=NULL时依次取链表中的结点插入到头结点之后
    while (p1)
    {
        pNext = p1->Next;
        p1->Next = pHead->Next;
        pHead->Next = p1;
        p1 = pNext;
    }
}

int main2()
{
    LinkList L;
    InitList(&L);

    CreatFormTail(L); //用尾插法建表
    PrintList(L);    //打印
    //  R_Print(&L);//从尾到头打印单链表


    //printRevList(L);

    printf("下面是递归实现逆序输出:\n");
    printRevList(L->Next);//递归调用逆序输出；注意入口为第一个带元素的结点
    printf("\n");

    printf("链表逆置中......\n\n");
    //链表逆置
    Reverse(L);
    //打印逆置后的链表中元素
    PrintList(L);
    system("pause");

    return 0;
}

/*
另一种
void R_Print(LinkList* pHead)
{
  //  assert(pHead);
    printf("从尾到头反向输出结点值:\n");
    Node* p1 = (*pHead)->Next;
    Node* Tail = NULL;
    while (p1!= Tail)
    {
        while (p1->Next != Tail)
        {
            p1 = p1->Next;
        }
        printf("%6d", p1->Data);
        Tail = p1;
        p1 = (*pHead)->Next;
    }
    printf("\n");
}
*/