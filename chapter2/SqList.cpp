#include <cstdio>
//#include <cstdlib>
//#include <iostream>
//using namespace std;

//定义
#define MaxSize 10
typedef struct{
    int data[MaxSize];
    int length;
}SqList;

//初始化
void InitList(SqList &L){
    for(int i = 0; i < MaxSize; i++)
        L.data[i] = 0;
    L.length = 0;
}

//插入
//i 是位序
bool ListInsert(SqList &L, int i, int e){
    if(i < 1 || i > L.length+1)
        return false;
    if(L.length >= MaxSize)
        return false;
    for(int j = L.length; j >= i; j--)
        L.data[j] = L.data[j-1];
    L.data[i-1] = e;
    L.length++;
    return true;
}

//删除
//i 是位序
bool ListDelete(SqList &L, int i, int &e){
    if(i < 1 || i > L.length)
        return false;
    e = L.data[i-1];
    for(int j = i; j < L.length; j++)
        L.data[j-1] = L.data[j];
    L.length--;
    return true;
}

//按位查找
//i 是位序
int GetElem(SqList L, int i){
    return L.data[i-1];
}

//按值查找
int LocateElem(SqList L, int e){
    for(int i = 0; i < L.length; i++){
        if(L.data[i] == e){
            return i+1;         //成功找到，返回位序
        }
    }
    return 0;                   //未找到，返回0
}

//打印链表
void PrintList(SqList L){
    for(int i = 0; i < L.length; i++)
        printf("%d ", L.data[i]);
    printf("\n");
}

int main(void){
    //声明一个list结构
    SqList L;

    //声明初始化函数
    void InitList(SqList &L);
    //声明插入函数
    bool ListInsert(SqList &L, int i, int e);
    //声明删除函数
    bool ListDelete(SqList &L, int i, int &e);
    //声明打印函数
    void PrintList(SqList L);
    //声明按位查找函数
    int GetElem(SqList L, int i);
    //声明按值查找函数
    int LocateElem(SqList L, int e);

    //初始化list
    InitList(L);

    //插入一些数据
    for(int i = 1; i < 9; i++){
        ListInsert(L, i, i*2);
        printf("在第%d位插入了%d\n", i, i*2);
    }

    PrintList(L);

    //删除一个数据，并用 e 把删除的值带出来
    int e = -1;
    ListDelete(L, 8, e);

    printf("删除了%d\n", e);
    PrintList(L);

    int elem = GetElem(L, 3);
    printf("第3位是%d\n", elem);

    int position = LocateElem(L, 2);
    printf("2是在第%d位\n", position);

    return 0;
}