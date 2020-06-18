#include <cstdio>

//定义双链表
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
    L->prior = NULL;
    L->next = NULL;
    return true;
}

//判空
bool Empty(DLinkList L){
    return (L->next == NULL);
}

//在节点 *p 之后插入 *s 节点
bool InsertNextDNode(*p, *s){
    if(p == NULL || s === NULL)
        return false;
    s->next = p->next;
    if(p->next != NULL)
        p->next->prior = s;
    s->prior = p;
    p->next = s;
    return true;
}

//删除 *p 节点之后的节点
bool DeleteNextDNode(DNode *p){
    if(p == NULL)
        return false;
    DNode *q = p->next;
    if(q == NULL)
        return false;
    p->next = q->next;
    if(q->next != NULL)
        q->next->prior = p;
    free(q);
    return true;
}

//销毁链表
void DestoryList(DLinkList L){
    if(L->next != NULL)
        DeleteNextDNode(L);
    free(L);
    L = NULL;
}

//打印链表
void PrintList(DLiskList L){
    DNode *p = L->next;
    while(p != NULL)
        printf(p->data);
        p = p->next;
}

void test1(){
}

int main(void){

    return 0;
}