#include <cstdio>
#include <cstdlib>

//定义
#define InitSize 10
#define Element int
typedef struct{
    Element *data;
    int MaxSize;
    int length;
}SeqList;

//初始化
void InitList(SeqList &L){
    L.data = (Element *)malloc(InitSize * sizeof(Element));
    L.length = 0;
    L.MaxSize = InitSize;
}

//增加动态数组的长度
void IncreaseSize(SeqList &L, int len){
    int *p = L.data;
    L.data = (Element *)malloc((L.MaxSize+len) * sizeof(Element));
    for(int i = 0; i < L.length; i++){
        L.data[i] = p[i];
    }
    L.MaxSize += len;
    free(p);
}

//插入
//i 是位序
bool ListInsert(SeqList &L, int i, Element e){
    if(i < 1 || i > L.length+1)
        return false;
    if(L.length >= L.MaxSize)
        return false;
    for(int j = L.length; j >= i; j--)
        L.data[j] = L.data[j-1];
    L.data[i-1] = e;
    L.length++;
    return true;
}

//删除
//i 是位序
bool ListDelete(SeqList &L, int i, Element &e){
    if(i < 1 || i > L.length+1)
        return false;
    e = L.data[i-1];
    for(int j = i; j < L.length; j++)
        L.data[j-1] = L.data[j];
    L.length--;
    return true;
}

//按位查找
Element GetElem(SeqList L, int i){
    return L.data[i-1];
}

//按值查找
int LocateElem(SeqList L, Element e){
    for(int i = 0; i < L.length; i++)
        if(L.data[i] == e)
            return i+1;          //成功找到，返回位序
    return 0;                    //未找到，返回0
}

//打印list
void PrintList(SeqList L){
    if(L.length == 0){
        printf("List is empty.");
    }else{
        for(int i = 0; i < L.length; i++)
            printf("%d  ", L.data[i]);
    }
}

int main(){
    //声明一个list结构
    SeqList L;

    //声明所需函数
    void InitList(SeqList &L);
    void IncreaseSize(SeqList &L, int len);
    bool ListInsert(SeqList &L, int i, Element e);
    bool ListDelete(SeqList &L, int i, Element &e);
    Element GetElem(SeqList L, int i);
    int LocateElem(SeqList L, Element e);
    void PrintList(SeqList L);

    //初始化
    InitList(L);

    //插入一些数据
    for(int i = 1; i < 9; i++){
        ListInsert(L, i, i*2);
        printf("在第%d位插入了%d\n", i, i*2);
    }

    PrintList(L);

    //删除数据
    Element e = -1;
    ListDelete(L, 3, e);
    printf("删除了%d\n", e);

    PrintList(L);

    return 0;
}





