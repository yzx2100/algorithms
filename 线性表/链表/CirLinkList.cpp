#include <cstdio>

//定义循环单链表
#define ElemType int
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;

//初始化
bool InitList(LinkList &L){
    L = (LNode *) malloc(sizeof(LNode));
    if(L == NULL)
        return false;
    L->next = L;
    return true;
}

//判空
bool Empty(LinkList L){
    return (L->next == L);
}

//判断节点 *p 是否是循环单链表的尾节点
bool IsTail(LinkList L, LNode *p){
    return (p->next == L);
}