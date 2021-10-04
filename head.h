//用到的库文件
#include <stdio.h>	//printf();scanf()
#include <stdlib.h> //exit()
#include <malloc.h>	//malloc()
#include <time.h>	//srand((unsigned)time(NULL));
//函数结果状态代码
#define TRUE	1
#define FALSE	0
#define OK		1
#define ERROR	0
#define INFEASIBLE	-1
#define OVERFLOW	-2
//Status是函数的类型，其值是函数结果状态代码
typedef int Status;
//#define ElemType int	//也可以用宏定义确定ElemType类型
typedef int ElemType;
//-----线性表的单链表存储结构-----
typedef struct	LNode {		//自定义数据类型
    ElemType data;			//数据域
    struct LNode *next;	//指针域
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