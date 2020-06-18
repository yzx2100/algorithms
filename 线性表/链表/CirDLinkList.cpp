#include <cstdio>

//定义循环双链表
#define ElemType int
typedef struct DNode{
    ElemType data;
    DNode *prior, *next;
}DNode, *DLinkList;

//初始化
bool InitDLinkList(DLinkList &L){
    L = (DNode *)malloc(sizeof(DNode));
    if(L == NULL)
        return false;
    L->prior = L;
    L->next = L;
    return true;
}

//判空
bool Empty(DLinkList L){
    return (L->next == L);
}

//判断节点 *p 是否是循环双链表的尾节点
bool IsTail(DLinkList L, DNode *p){
    return (p->next == L);
}

//在节点 *p 之后插入 *s 节点
bool InsertNextDNode(*p, *s){
    s->next = p->next;
    p->next->prior = s;
    s->prior = p;
    p->next = s;
    return true;
}

//删除 *p 节点之后的节点
bool DeleteNextDNode(DNode *p){
    DNode *q = p->next;
    p->next = q->next;
    q->next->prior = p;
    free(q);
    return true;
}