//�õ��Ŀ��ļ�
#include <stdio.h>	//printf();scanf()
#include <stdlib.h> //exit()
#include <malloc.h>	//malloc()
#include <time.h>	//srand((unsigned)time(NULL));
//�������״̬����
#define TRUE	1
#define FALSE	0
#define OK		1
#define ERROR	0
#define INFEASIBLE	-1
#define OVERFLOW	-2
//Status�Ǻ��������ͣ���ֵ�Ǻ������״̬����
typedef int Status;
//#define ElemType int	//Ҳ�����ú궨��ȷ��ElemType����
typedef int ElemType;
//-----���Ա�ĵ�����洢�ṹ-----
typedef struct	LNode {		//�Զ�����������
    ElemType data;			//������
    struct LNode *next;	//ָ����
} LNode, *LinkList;
/*classic*/
void Increase(LinkList L);
void MoveMin(LinkList L);
Status Insert_LinkList(LinkList L, int x);
void Purge(LinkList L);
int BackLocate(LinkList L, int m);
void DeleteBetween(LinkList L, int mink, int maxk);


/*king*/
void Del_x_1(LinkList &L, ElemType x);
void Del_x_2(LinkList &L, ElemType x);
void Del_x_3(LinkList &L, ElemType x);
void Print_reverse_L(LinkList L);
LinkList Delete_Min(LinkList &L);
void Reverse_L_1(LinkList &L);
void Reverse_L_2(LinkList &L);


Status InitList_L(LinkList &L);
Status DestroyList_L(LinkList &L);
Status ClearList_L(LinkList &L);
Status ListEmpty_L(LinkList L);
int ListLength_L(LinkList L);
Status GetElem_L(LinkList L, int i, ElemType &e);
Status compare(ElemType listElem, ElemType e);
int LocateElem_L(LinkList L, ElemType e, Status (*pfn_compare)(ElemType, ElemType));
Status PriorElem_L(LinkList L, ElemType cur_e, ElemType &pre_e);
Status NextElem_Sq(LinkList L, ElemType cur_e, ElemType &next_e);
Status ListInsert_L(LinkList &L, int pos, ElemType e);
Status ListDelete_L(LinkList &L, int pos, ElemType &e);
Status visit(ElemType e);
Status ListTraverse_L(LinkList L, Status (*pfn_visit)(ElemType));
Status CreateList(LinkList &L);
void CreateList_L(LinkList &L, int n);
void CreateListTail(LinkList &L, int n);