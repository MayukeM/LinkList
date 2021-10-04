#include <stdio.h>
#include <stdlib.h>

typedef int DataType;//Ԫ������Ϊ����
typedef struct Node
{
    DataType Data;
    struct Node* Next;
}Node,*LinkList;

void InitList(LinkList* PHead)
{
    if ((*PHead = (LinkList)malloc(sizeof(Node))) == NULL)
    {
        printf("�ڴ����ʧ��.\n");
        return;
    }
    (*PHead)->Next = NULL;
}

//β�巨����
void CreatFormTail(LinkList PHead)
{
    Node* s;
    Node* tail;
    DataType data;
    tail = PHead;

    printf("��������Ԫ�أ�������-1ʱֹͣ\n");
    scanf("%d", &data);
    while (data != -1)
    {
        s = (Node*)malloc(sizeof(Node));
        s->Data = data;
        s->Next = tail->Next;
        tail->Next = s;
        tail = s;   //tailʼ��ָ���β
        scanf("%d", &data);
    }
}

//��ӡ����Ԫ��
void PrintList(LinkList PHead)
{
    printf("��ӡ����Ԫ��\n");
    Node* p;
    p = PHead->Next;
    while (p)
    {
        printf("%6d", p->Data);
        p = p->Next;
    }
    printf("\n");
}//�ݹ��������
void printRevList(LinkList pHead){
    if (pHead->Next != NULL)
        printRevList(pHead->Next);

    //if(pHead!=NULL)
    printf("%6d", pHead->Data);


}

//��ͷ������������
void Reverse(LinkList pHead)
{

    //�����������Ϊ���Ա��ȿ���Ϊ0��1�����������Ϊ�գ�����������ֻ��һ���������Ҫ����
    if (pHead->Next == NULL || pHead->Next->Next == NULL)
    {
        return;
    }
    Node* p1 = pHead->Next;
    Node* pNext;
    //��ͷ���������Ͽ�������һ��������
    pHead->Next = NULL;
    //��p1!=NULLʱ����ȡ�����еĽ����뵽ͷ���֮��
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

    CreatFormTail(L); //��β�巨����
    PrintList(L);    //��ӡ
    //  R_Print(&L);//��β��ͷ��ӡ������


    //printRevList(L);

    printf("�����ǵݹ�ʵ���������:\n");
    printRevList(L->Next);//�ݹ�������������ע�����Ϊ��һ����Ԫ�صĽ��
    printf("\n");

    printf("����������......\n\n");
    //��������
    Reverse(L);
    //��ӡ���ú��������Ԫ��
    PrintList(L);
    system("pause");

    return 0;
}

/*
��һ��
void R_Print(LinkList* pHead)
{
  //  assert(pHead);
    printf("��β��ͷ����������ֵ:\n");
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