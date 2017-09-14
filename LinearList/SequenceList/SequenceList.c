#include "SequenceList.h"

void InitList(SequenceList *L) {

  L->elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
  if (!L->elem) exit(OVERFLOW);
  L->length = 0;
  L->listSize = LIST_INIT_SIZE;

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

  if (i < 0 || i >= L.length) return NONE;
  *e = L.elem[i];
  return OK;

}

int LocateElem(SequenceList L, ElemType e, Status (*compare) (ElemType, ElemType)) {
  for (int i = 0; i < L.length; i++) {
    if ((*compare)(e, L.elem[i])) return i;
  }
  return NONE;
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

  if (i < 0 || i > L->length) return ERROR;
  if (L->length >= L->listSize) {
    ElemType *newElem = (ElemType *)realloc(L->elem, (L->length + LISTINCREMENT) * sizeof(ElemType));
    if (!newElem) exit(OVERFLOW);
    L->elem = newElem;
    L->listSize += LISTINCREMENT;
  }

  for (int j = L->length; j > i; j--) L->elem[j] = L->elem[j-1];

  L->elem[i] = e;
  L->length++;
  return OK;

}

Status ListDelete(SequenceList *L, int i, ElemType *e) {

  if (i < 0 || i >= L->length) return ERROR;
  *e = L->elem[i];
  for (int j = i; j < L->length-1; j++) L->elem[j] = L->elem[j+1];
  L->length--;
  return OK;

}

void MergeList(SequenceList La, SequenceList Lb, SequenceList *Lc) {

  Lc->listSize = La.length + Lb.length;
  Lc->elem = (ElemType *)malloc(Lc->listSize * sizeof(ElemType));
  int i = 0, j = 0;
  while (i < La.length && j < Lb.length) {
    if (La.elem[i] < Lb.elem[j]) {
      Lc->elem[Lc->length++] = La.elem[i++];
    }else {
      Lc->elem[Lc->length++] = Lb.elem[j++];
    }
  }

  while (j < Lb.length) Lc->elem[Lc->length++] = Lb.elem[j++];
  while (i < La.length) Lc->elem[Lc->length++] = La.elem[i++];

}

void ListTraverse(SequenceList L, void (*visit) (ElemType)) {

  for (int i = 0; i < L.length; i++) {
    (*visit)(L.elem[i]);
  }

}

void print(ElemType e) {

  printf("%d\n", e);

}

void ListUnion(SequenceList *La, SequenceList Lb) {

  int laLen = ListLength(*La);
  int lbLen = ListLength(Lb);
  for (int i = 0; i < lbLen; i++) {
    ElemType elem;
    GetElem(Lb, i, &elem);
    if (LocateElem(*La, elem, (*equal)) == NONE) ListInsert(La, laLen++, elem);
  }

}

Status equal(ElemType e1, ElemType e2) {
  return e1 == e2 ? TRUE : FALSE;
}


int main() {

  SequenceList La, Lb, Lc;

  InitList(&La);

  for (int i = 0; i <= 100; i++) {
    ListInsert(&La, i, i);
  }

  return 0;
}
