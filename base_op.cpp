#include "head.h"
// �������������һ���յ����Ա�L��
Status InitList_L(LinkList &L) {
    L = (LinkList)malloc(sizeof(LNode));
    if(!L) {						//�洢����ʧ��
        printf("��ʼ��ʧ��");
        exit(OVERFLOW);			//exit(-1)�����쳣�˳�
    }
    L->next = NULL;				// �Ƚ���һ����ͷ���ĵ�������ʹͷ����ָ����ΪNULL
    return OK;
}// InitList_L

// ��ʼ���������Ա�L�Ѵ��ڡ�
// ����������������Ա�L��
Status DestroyList_L(LinkList &L) {
    free(L);						//�ͷ����Ա�ͷ���ָ����
    return OK;
}// DestroyList_L

// ��ʼ���������Ա�L�Ѵ��ڡ�
// �����������L����Ϊ�ձ�
Status ClearList_L(LinkList &L) {
    LinkList p = L->next, ptmp;	//pָ�����Ա�ͷ���
    while(p) {						//�ͷ�ÿ������ָ����
        ptmp = p->next;
        free(p);
        p = ptmp;
    }
    L->next = NULL;				//ͷ���ָ����Ϊ��
    return OK;
}// ClearList_L

// ��ʼ���������Ա�L�Ѵ��ڡ�
// �����������LΪ�ձ�����TRUE�����򷵻�FALSE
Status ListEmpty_L(LinkList L) {
    return L->next ? FALSE : TRUE;
}// ListEmpty_L

// ��ʼ���������Ա�L�Ѵ��ڡ�
// �������������L������Ԫ�ظ�����
int ListLength_L(LinkList L) {
    int nElem = 0;
    LinkList p = L->next;			//pָ���һ�����
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

// ��ʼ���������Ա�L�Ѵ��ڣ�1��i��ListLength(L) ��
// �����������e����L�е�i������Ԫ�ص�ֵ��
Status GetElem_L(LinkList L, int i, ElemType &e) {
    LinkList p = L->next;			//��ʼ����pָ���һ�����
    int j = 1;						//jΪ������
    while ( p && j<i ) {			//˳ָ�������ң�ֱ��pָ���i��Ԫ�ػ�pΪ��
        p = p->next;
        ++ j;
    }
    if ( !p || j>i )
        return ERROR;				//��i��Ԫ�ز�����
    e = p->data;					//ȡ��i��Ԫ��
    return OK;
}// GetElem_L �㷨2.8

// ��ʼ���������Ա�L�Ѵ��ڣ�compare()������Ԫ���ж�������
// �������������L�е�1����e����compare()������Ԫ�ص�λ��������������Ԫ�ز����ڣ��򷵻�ֵΪ0��
Status compare(ElemType listElem, ElemType e) {
    return listElem == e ? TRUE : FALSE;
}// Compare
int LocateElem_L(LinkList L, ElemType e, Status (*pfn_compare)(ElemType, ElemType)) {
    int pos = 1;
    LinkList p = L->next;			//pָ�������1��Ԫ��
    while(p && !(*pfn_compare)(p->data, e)) {
        ++pos;
        p = p->next;				//ָ�����	p->next = NULLʱ ��ζ���ҵ���βԪ����
    }
    if(pos<=ListLength_L(L))		//pos��ֵ�����Ա��У�����Ԫ�ص�λ��
        return pos;
    else
        return 0;
}// LocateElem_L

// ��ʼ���������Ա�L�Ѵ��ڡ�
// �����������cur_e��L������Ԫ�أ��Ҳ��ǵ�һ��������pre_e��������ǰ�����������ʧ�ܣ�pre_e�޶��塣
Status PriorElem_L(LinkList L, ElemType cur_e, ElemType &pre_e) {
    int i = LocateElem_L(L, cur_e, compare);
    if(i==0 || i==1) return ERROR;
    GetElem_L(L, i-1, pre_e);
    return OK;
}// PriorElem_L

// ��ʼ���������Ա�L�Ѵ��ڡ�
// �����������cur_e��L������Ԫ�أ��Ҳ������һ��������next_e�������ĺ�̣��������ʧ�ܣ�pre_e�޶��塣
Status NextElem_Sq(LinkList L, ElemType cur_e, ElemType &next_e) {
    int i = LocateElem_L(L, cur_e, compare);
    if(i==0 || i==ListLength_L(L)) return ERROR;
    GetElem_L(L, i+1, next_e);
    return OK;
}// NextElem_Sq

// ��ʼ���������Ա�L�Ѵ��ڣ�1��pos��ListLength(L)+1��
// �����������L�е�pos��λ��֮ǰ�����µ�Ԫ��e��L�ĳ��ȼ�1��
Status ListInsert_L(LinkList &L, int pos, ElemType e) {
    LinkList p = L;				//����һ���ṹ��ָ�����p��ָ�����Ա���ʼλ�ã�ͷ��㣩L��
    int j = 0;
    while (p && j<pos-1) {			//Ѱ�ҵ�i-1����㣬����pָ����ǰ����
        p = p->next;				//p�ǿգ���j<i-1��˵��ָ��λ�����Ա���
        ++j;
    }
    if (!p || j>pos-1)				//����λ���Ƿ�Ϸ�����i�������ڣ������λ���ڱ��ڣ�
        return ERROR;
    LinkList s = (LinkList) malloc(sizeof(LNode));// �����½��
    s->data = e;					// �������Ԫ��ֵ���� �����ɽ���������
    s->next = p->next;				// �����ɽ���ָ���� ָ����һ����� ���������i-1��ָ���i��Ԫ�ص�ָ����p->next�������½���ָ����s->next��
    p->next = s;					// ���i-1��ָ���� ָ�������ɵĽ�㣨����ָ�������ɽ���ָ��s��������i-1��Ԫ�ص�ָ����p->next��
    printf("�����Ԫ�أ�%d, �����λ�ã�%d\n", e, pos);
    return OK;
}// ListInsert_L �㷨2.9

// ��ʼ���������Ա�L�Ѵ����ҷǿգ�1��pos��ListLength(L)��
// ���������ɾ��L�ĵ�pos������Ԫ�أ�����e������ֵ,L�ĳ��ȼ�1��
Status ListDelete_L(LinkList &L, int pos, ElemType &e) {
    LinkList p = L;				//����һ���ṹ��ָ�����p��ָ�����Ա���ʼλ�ã�ͷ��㣩L��
    int j = 0;
    while (p->next && j<pos-1) {	//Ѱ�ҵ�i����㣬����pָ����ǰ����
        p = p->next;
        ++j;
    }
    if (!(p->next) || j>pos-1)		// ɾ��λ���Ƿ�Ϸ��������ڣ�ɾ����λ���ڱ��ڣ�
        return ERROR;
    LinkList q = p->next;			//ʹqָ��i-1��㣨�����i-1��ָ����i��ָ���򣬸���ָ�����q)
    p->next = q->next;				//�������i��ָ����i+1��ָ���򣬸������i-1��ָ����
    e = q->data;					//Ҫɾ�����������򣬸���e
    free(q);						//�ͷ�ָ�����q
    printf("ɾ����Ԫ�أ�%d, ɾ����λ�ã�%d\n", e, pos);
    return OK;
}// ListDelete_L �㷨2.10

// ��ʼ���������Ա�L�Ѵ��ڡ�
// ������������ζ�L��ÿ������Ԫ�ص��ú���visit()��һ��vistit()ʧ�ܣ��ղ���ʧ�ܡ�
Status visit(ElemType e) {
    printf("%d ",e);
    return OK;
}
Status ListTraverse_L(LinkList L, Status (*pfn_visit)(ElemType)) {
    LinkList p = L->next;			//ָ������ָ��ͷ���
    if(!p)	{
        printf("���Ա�δ��ʼ����\n");
        return ERROR;
    }
    while(p) {
        visit(p->data);
        p = p->next;
    }
    printf("\n");
    return OK;
}// ListTraverse

// ���������,����10���������ͷ�巨����
Status CreateList(LinkList &L) {
    srand((unsigned)time(NULL));
    //��������
    L = (LinkList)malloc(sizeof(LNode));
    if(!L) {						//�洢����ʧ��
        printf("��ʼ��ʧ��");
        exit(OVERFLOW);			//exit(-1)�����쳣�˳�
    }
    for (int i=0; i<10; i++) {	// �����½��
        LinkList p = (LinkList)malloc(sizeof(LNode));
        //scanf("%d", &p->data);	//����Ԫ��ֵ ���������ɽ���������
        p->data = rand()%100;
        p->next = L->next;			//���뵽��ͷ
        L->next = p;
        printf("%d ", p->data);	// �鿴�Ƿ�������µ�Ԫ��
    }
    return OK;
}// ��������

// ��λ������(�������)n��Ԫ�ص�ֵ����������ͷ���ĵ������Ա�L��ͷ�巨����
void CreateList_L(LinkList &L, int n) {
    srand((unsigned)time(NULL));	//��ʼ�����������
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;				//�Ƚ���һ����ͷ���ĵ�����
    for (int i=n; i>0; --i) {
        LinkList p = (LinkList)malloc(sizeof(LNode));//�����½��
        //scanf("%d", &p->data);	//����Ԫ��ֵ
        //�������100���ڵ�����
        p->data = rand()%100;		//�����ɵ�Ԫ��ֵ���������ɽ���������
        //���뵽��ͷ
        p->next = L->next;         //ʹ�½���ָ����ָ����һ�����ɵĽ�㣨����һ�����ɽ���ָ���򸳸��½���ָ����
        L->next = p;               //ͷ����ָ����ָ�������ɵĽ�㣨��ָ���½���ָ��p����ͷ����ָ����
    }
}// CreateList_L �㷨2.11

// ˳λ������(�������)n��Ԫ�ص�ֵ����������ͷ���ĵ������Ա�L��β�巨����
void CreateListTail(LinkList &L, int n) {
    InitList_L(L);
    LinkList p, r = L;
    printf("������%d��Ԫ�أ�", n);
    for (int i=0 ; i<n ; ++i) {
        p = (LinkList)malloc(sizeof(LNode)) ;
        //scanf("%d", &p->data) ;	//����Ԫ��ֵ
        scanf("%d", &p->data);	//����Ԫ��ֵ ���������ɽ���������
        //���뵽��β
        r->next = p;
        r = p;				//��һ����ָ����ָ�������ɵĽ�㣨�������ɽ���ָ���򸳸���һ����ָ���ָ����
    }
    r->next = NULL;
}