#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef int Status;
typedef int ElemType;
typedef struct {
  ElemType *elem;
  int length;
  int listSize;
} SequenceList;

void InitList(SequenceList *L);

void DestroyList(SequenceList *L);

void ClearList(SequenceList *L);

Status ListEmpty(SequenceList L);

int ListLength(SequenceList L);

Status GetElem(SequenceList L, int i, ElemType *e);

int LocateElem(SequenceList L, ElemType e);

Status PriorElem(SequenceList L, ElemType cur_e, ElemType *pre_e);

Status NextElem(SequenceList L, ElemType cur_e, ElemType *next_e);

Status ListInsert(SequenceList *L, int i, ElemType e);

Status ListDelete(SequenceList *L, int i, ElemType *e);

// Status ListTraverse(SequenceList L, visit());

void MergeList(SequenceList La, SequenceList Lb, SequenceList *Lc);
