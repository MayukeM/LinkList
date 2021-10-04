#include "head.h"
// 操作结果：构造一个空的线性表L。
Status InitList_L(LinkList &L) {
    L = (LinkList)malloc(sizeof(LNode));
    if(!L) {						//存储分配失败
        printf("初始化失败");
        exit(OVERFLOW);			//exit(-1)程序异常退出
    }
    L->next = NULL;				// 先建立一个带头结点的单链表，并使头结点的指针域为NULL
    return OK;
}// InitList_L

// 初始条件：线性表L已存在。
// 操作结果：销毁线性表L。
Status DestroyList_L(LinkList &L) {
    free(L);						//释放线性表头结点指针域
    return OK;
}// DestroyList_L

// 初始条件：线性表L已存在。
// 操作结果：将L重置为空表。
Status ClearList_L(LinkList &L) {
    LinkList p = L->next, ptmp;	//p指向线性表头结点
    while(p) {						//释放每个结点的指针域
        ptmp = p->next;
        free(p);
        p = ptmp;
    }
    L->next = NULL;				//头结点指针域为空
    return OK;
}// ClearList_L

// 初始条件：线性表L已存在。
// 操作结果：若L为空表，返回TRUE，否则返回FALSE
Status ListEmpty_L(LinkList L) {
    return L->next ? FALSE : TRUE;
}// ListEmpty_L

// 初始条件：线性表L已存在。
// 操作结果：返回L中数据元素个数。
int ListLength_L(LinkList L) {
    int nElem = 0;
    LinkList p = L->next;			//p指向第一个结点
    while(p) {
        nElem ++;
        p = p->next;
    }
    return nElem;
}// ListLength

//    int nElem = 0;
//    LinkList p;
//    for(p=L->next; p!=NULL; p=p->next){
//        nElem++;
//    }

// 初始条件：线性表L已存在，1≤i≤ListLength(L) 。
// 操作结果：用e返回L中第i个数据元素的值。
Status GetElem_L(LinkList L, int i, ElemType &e) {
    LinkList p = L->next;			//初始化，p指向第一个结点
    int j = 1;						//j为计数器
    while ( p && j<i ) {			//顺指针向后查找，直到p指向第i个元素或p为空
        p = p->next;
        ++ j;
    }
    if ( !p || j>i )
        return ERROR;				//第i个元素不存在
    e = p->data;					//取第i个元素
    return OK;
}// GetElem_L 算法2.8

// 初始条件：线性表L已存在，compare()是数据元素判定函数。
// 操作结果：返回L中第1个与e满足compare()的数据元素的位序，若这样的数据元素不存在，则返回值为0。
Status compare(ElemType listElem, ElemType e) {
    return listElem == e ? TRUE : FALSE;
}// Compare
int LocateElem_L(LinkList L, ElemType e, Status (*pfn_compare)(ElemType, ElemType)) {
    int pos = 1;
    LinkList p = L->next;			//p指向链表第1个元素
    while(p && !(*pfn_compare)(p->data, e)) {
        ++pos;
        p = p->next;				//指针后移	p->next = NULL时 意味着找到表尾元素了
    }
    if(pos<=ListLength_L(L))		//pos的值在线性表中，返回元素的位序
        return pos;
    else
        return 0;
}// LocateElem_L

// 初始条件：线性表L已存在。
// 操作结果：若cur_e是L的数据元素，且不是第一个，则用pre_e返回它的前驱，否则操作失败，pre_e无定义。
Status PriorElem_L(LinkList L, ElemType cur_e, ElemType &pre_e) {
    int i = LocateElem_L(L, cur_e, compare);
    if(i==0 || i==1) return ERROR;
    GetElem_L(L, i-1, pre_e);
    return OK;
}// PriorElem_L

// 初始条件：线性表L已存在。
// 操作结果：若cur_e是L的数据元素，且不是最后一个，则用next_e返回它的后继，否则操作失败，pre_e无定义。
Status NextElem_Sq(LinkList L, ElemType cur_e, ElemType &next_e) {
    int i = LocateElem_L(L, cur_e, compare);
    if(i==0 || i==ListLength_L(L)) return ERROR;
    GetElem_L(L, i+1, next_e);
    return OK;
}// NextElem_Sq

// 初始条件：线性表L已存在，1≤pos≤ListLength(L)+1。
// 操作结果：在L中第pos个位置之前插入新的元素e，L的长度加1。
Status ListInsert_L(LinkList &L, int pos, ElemType e) {
    LinkList p = L;				//定义一个结构体指针变量p，指向线性表起始位置（头结点）L。
    int j = 0;
    while (p && j<pos-1) {			//寻找第i-1个结点，并令p指向其前趋。
        p = p->next;				//p非空，且j<i-1，说明指针位于线性表内
        ++j;
    }
    if (!p || j>pos-1)				//插入位置是否合法（第i个结点存在，插入的位置在表内）
        return ERROR;
    LinkList s = (LinkList) malloc(sizeof(LNode));// 生成新结点
    s->data = e;					// 将插入的元素值赋给 新生成结点的数据域
    s->next = p->next;				// 新生成结点的指针域 指向下一个结点 （即将结点i-1中指向第i个元素的指针域p->next，赋给新结点的指针域s->next）
    p->next = s;					// 结点i-1的指针域 指向新生成的结点（即将指向新生成结点的指针s，赋给第i-1个元素的指针域p->next）
    printf("插入的元素：%d, 插入的位置：%d\n", e, pos);
    return OK;
}// ListInsert_L 算法2.9

// 初始条件：线性表L已存在且非空，1≤pos≤ListLength(L)。
// 操作结果：删除L的第pos个数据元素，并用e返回其值,L的长度减1。
Status ListDelete_L(LinkList &L, int pos, ElemType &e) {
    LinkList p = L;				//定义一个结构体指针变量p，指向线性表起始位置（头结点）L。
    int j = 0;
    while (p->next && j<pos-1) {	//寻找第i个结点，并令p指向其前趋。
        p = p->next;
        ++j;
    }
    if (!(p->next) || j>pos-1)		// 删除位置是否合法（结点存在，删除的位置在表内）
        return ERROR;
    LinkList q = p->next;			//使q指向i-1结点（将结点i-1中指向结点i的指针域，赋给指针变量q)
    p->next = q->next;				//（将结点i中指向结点i+1的指针域，赋给结点i-1的指针域
    e = q->data;					//要删除结点的数据域，赋给e
    free(q);						//释放指针变量q
    printf("删除的元素：%d, 删除的位置：%d\n", e, pos);
    return OK;
}// ListDelete_L 算法2.10

// 初始条件：线性表L已存在。
// 操作结果：依次对L的每个数据元素调用函数visit()。一旦vistit()失败，刚操作失败。
Status visit(ElemType e) {
    printf("%d ",e);
    return OK;
}
Status ListTraverse_L(LinkList L, Status (*pfn_visit)(ElemType)) {
    LinkList p = L->next;			//指针重新指向头结点
    if(!p)	{
        printf("线性表未初始化。\n");
        return ERROR;
    }
    while(p) {
        visit(p->data);
        p = p->next;
    }
    printf("\n");
    return OK;
}// ListTraverse

// 创建随机表,包含10个随机数（头插法）。
Status CreateList(LinkList &L) {
    srand((unsigned)time(NULL));
    //生成链表
    L = (LinkList)malloc(sizeof(LNode));
    if(!L) {						//存储分配失败
        printf("初始化失败");
        exit(OVERFLOW);			//exit(-1)程序异常退出
    }
    for (int i=0; i<10; i++) {	// 生成新结点
        LinkList p = (LinkList)malloc(sizeof(LNode));
        //scanf("%d", &p->data);	//输入元素值 赋给新生成结点的数据域
        p->data = rand()%100;
        p->next = L->next;			//插入到表头
        L->next = p;
        printf("%d ", p->data);	// 查看是否插入了新的元素
    }
    return OK;
}// 个人整合

// 逆位序输入(随机产生)n个元素的值，建立带表头结点的单链线性表L（头插法）。
void CreateList_L(LinkList &L, int n) {
    srand((unsigned)time(NULL));	//初始化随机数种子
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;				//先建立一个带头结点的单链表
    for (int i=n; i>0; --i) {
        LinkList p = (LinkList)malloc(sizeof(LNode));//生成新结点
        //scanf("%d", &p->data);	//输入元素值
        //随机生成100以内的数字
        p->data = rand()%100;		//将生成的元素值赋给新生成结点的数据域
        //插入到表头
        p->next = L->next;         //使新结点的指针域指向上一次生成的结点（将上一次生成结点的指针域赋给新结点的指针域）
        L->next = p;               //头结点的指针域指向新生成的结点（将指向新结点的指针p赋给头结点的指针域）
    }
}// CreateList_L 算法2.11

// 顺位序输入(随机产生)n个元素的值，建立带表头结点的单链线性表L（尾插法）。
void CreateListTail(LinkList &L, int n) {
    InitList_L(L);
    LinkList p, r = L;
    printf("请输入%d个元素：", n);
    for (int i=0 ; i<n ; ++i) {
        p = (LinkList)malloc(sizeof(LNode)) ;
        //scanf("%d", &p->data) ;	//输入元素值
        scanf("%d", &p->data);	//输入元素值 赋给新生成结点的数据域
        //插入到表尾
        r->next = p;
        r = p;				//上一结点的指针域指向新生成的结点（将新生成结点的指针域赋给上一结点的指针的指针域）
    }
    r->next = NULL;
}