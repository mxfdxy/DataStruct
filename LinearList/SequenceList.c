#include "SqList.h"

Status InitList(SqList &L) {

  L->elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
  if (!L->elem) exit(OVERFLOW);
  L->length = 0;
  L->listSize = LIST_INIT_SIZE;
  return OK;

}

void DestroyList(SequenceList *L) {

  free(L->elem);
  L->elem = NULL;
  L->length = 0;
  L->listSize = 0;

}

void ClearList(SequenceList *L) {

  L->length = 0;

}

Status ListEmpty(SequenceList L) {

  if (L.length == 0) return TRUE;
  return FALSE;

}

int ListLength(SequenceList L) {

  return L.length;

}

Status GetElem(SequenceList L, int i, ElemType *e) {

  if (i < 1 || i > L.length) return ERROR;
  *e = L.elem[i-1];
  return OK;

}

int LocateElem(SequenceList L, ElemType e) {
  for (int i = 0; i < L.length; i++) {
    if (e == L.elem[i]) return i;
  }
  return OVERFLOW;
}

Status PriorElem(SequenceList L, ElemType cur_e, ElemType *pre_e) {

  for (int i = 1; i < L.length; i++) {
    if (cur_e == L.elem[i]) {
      *pre_e = L.elem[i-1];
      return OK;
    }
  }
  return ERROR;

}

Status NextElem(SequenceList L, ElemType cur_e, ElemType *next_e) {

  for (size_t i = 0; i < L.length-1; i++) {
    if (cur_e == L.elem[i]) {
      *next_e = L.elem[i+1];
      return OK;
    }
  }
  return ERROR;

}

Status ListInsert(SequenceList *L, int i, ElemType e) {

  if (i < 1 || i > L->length) return ERROR;
  for (int j = L->length; j >= i-1; j--) L->elem[j+1] = L->elem[j];
  L->elem[i-1] = e;
  L->length++;
  return OK;

}

Status ListDelete(SequenceList *L, int i, ElemType *e) {

  if (i < 1 || i > L->length) return ERROR;
  *e = L->elem[i-1];
  for (int j = i; j < L->length; j++) L->elem[j-1] = L->elem[j];
  L->length--;
  return OK;

}

// Status ListTraverse(SequenceList L, visit());

void MergeList(SequenceList La, SequenceList Lb, SequenceList *Lc) {

  Lc->listSize = La.length + Lb.length;
  Lc->elem = (ElemType *)malloc(Lc->listSize * sizeof(ElemType));
  for (int i = 0; i < La.length; i++) Lc->elem[i] = La.elem[i];
  for (int i = 0; i < Lb.length; i++) Lc->elem[i+La.length] = Lb.elem[i];

}




int main() {
  return 0;
}
