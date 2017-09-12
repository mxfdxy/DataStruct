#include <stdio.h>
#include "SequenceList.h"

#define MAXSIZE = 100;

typedef int ElemType;
typedef int Status;
#define OK = 1;

typedef struct {
  ElemType *elem;
  int length;
} SqList;

Status initList(SqList *l);

Status initList(SqList *l) {
  l->elem = new ElemType[MAXSIZE];

  if (!l.elem) exit(OVERFLOW);

  l->length = 0;
  return OK;
}

int main() {

    SqList list;
    initList(&list);

}
