#include <cstdio>
#include <cstdlib>

//定义单链表
#define ElemType int
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;

//初始化（不带头结点）
bool InitList_NoHead(LinkList &L){
    L = NULL;
    return true;
}

//初始化（带头结点）
bool InitList(LinkList &L){
    L = (LNode *) malloc(sizeof(LNode));
    if(L == NULL)
        return false;
    L->next = NULL;
    return true;
}

//判空(不带头结点)
bool Empty_NoHead(LinkList L){
    return (L == NULL);
}

//判空（带头结点）
bool Empty(LinkList L){
    return (L->next == NULL);
}

//插入(带头结点)
bool ListInsert(LinkList &L, int i, ElemType e){
    if(i < 1)
        return false;
    LNode *p;
    int j = 0;
    p = L;
    while(p != NULL && j < i-1){
        p = p->next;
        j++;
    }
    if(p == NULL)
        return false;
    LNode *s = (LNode *) malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

//插入(不带头结点)
bool ListInsert_NoHead(LinkList &L, int i, ElemType e){
    if(i < 1)
        return false;
    if(i == 1){
        LNode *s = (LNode *) malloc(sizeof(LNode));
        s->data = e;
        s->next = L;
        L = s;
        return true;
    }
    LNode *p;
    int j = 1;
    p = L;
    while(p != NULL && j < i-1){
        p = p->next;
        j++;
    }
    LNode *s = (LNode *) malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

//后插操作
bool InsertNextNode(LNode *p, ElemType e){
    if(p == NULL)
        return false;
    LNode *s = (LNode *) malloc(sizeof(LNode));
    if(s == NULL)
        return false;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

//前插操作
bool InsertPriorNode(LNode *p, ElemType e){
    if(p == NULL)
        return false;
    LNode *s = (LNode *) malloc(sizeof(LNode));
    if(s == NULL)
        return false;
    s->next = p->next;
    p->next = s;
    s->data = p->data;
    p->data = e;
    return true;
}

//按位序删除
bool ListDelete(LinkList &L, int i, ElemType &e){
    if(i < 1)
        return false;
    LNode *p;
    int j = 0;
    p = L;
    while(p != NULL && j < i-1){
        p = p->next;
        j++;
    }
    if(p == NULL)
        return false;
    if(p->next == NULL)
        return false;
    LNode *q = p->next;
    e = q->data;
    p->next = q->next;
    free(q);
    return true;
}

//删除指定节点
bool DeleteNode(LNode *p){
    if(p == NULL)
        return false;
    LNode *q = p->next;
    p->data = q->data;
    p->next = q->next;
    free(q);
    return true;
}

//按位查找
LNode * GetElem(LinkList L, int i){
    if(i < 1)
        return NULL;
    LNode *p;
    int j = 0;
    p = L;
    while(p != NULL && j < i){
        p = p->next;
        j++;
    }
    return p;
}

//按值查找
LNode * LocateElem(LinkList L, ElemType e){
    LNode *p = L->next;
    while(p != NULL && p->data != e){
        p = p->next;
    }
    return p;
}

//求表长
int GetLength(LinkList L){
    int length = 0;
    LNode *p = L;
    while(p->next != NULL){
        p = p->next;
        length++;
    }
    return length;
}

//尾插法建立单链表
LinkList List_TailInsert(LinkList &L){
    ElemType x;
    L = (LinkList)malloc(sizeof(LNode));
    LNode *s, *r = L;
    scanf("%d", &x);
    while(x != 9999){
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
    r->next = NULL;
    return L;
}

//头插法建立单链表
LinkList List_HeadInsert(LinkList &L){
    ElemType x;
    LNode *s;
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    scanf("%d", &x);
    while(x != 9999){
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d", &x);
    }
    return L;
}

//打印链表
void PrintList(LinkList L){
    LNode *p = L->next;
    while(p != NULL){
        printf("%d  ", p->data);
        p = p->next;
    }
    printf("\n");
}

//测试基本操作
void test1(){
    LinkList L;
    bool InitList(LinkList &L);
    LNode * GetElem(LinkList L, int i);
    bool ListInsert(LinkList &L, int i, ElemType e);
    bool ListDelete(LinkList &L, int i, ElemType &e);
    int GetLength(LinkList L);
    void PrintList(LinkList L);

    InitList(L);
    for(int i = 0; i < 9; i++){
        ListInsert(L, i, i*2);
    }
    PrintList(L);
    int e;
    ListDelete(L, 1, e);
    printf("删除%d\n", e);
    PrintList(L);
    LNode *q = GetElem(L, 3);
    printf("第三位是%d\n", q->data);
    int len = GetLength(L);
    printf("表长：%d\n", len);
}

//测试尾插法
void test2(){
    LinkList L;
    LinkList List_TailInsert(LinkList &L);

    List_TailInsert(L);
    PrintList(L);
}

//测试头插法
void test3(){
    LinkList L;
    LinkList List_HeadInsert(LinkList &L);

    List_HeadInsert(L);
    PrintList(L);
}

int main(void){
//    void test1();
//    test1();
//    void test2();
//    test2();
    void test3();
    test3();
    return 0;
}
