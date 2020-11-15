#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
extern int pop();
extern void push(int);
// extern int isEmpty();
extern void initHeap();
extern void addHeap(int);
extern int heapDelete();
extern int heapSize();
// extern void printHeap();
extern void printXMLHeap(int);

int main(int argc, char * argv[])
{

  int value;

  initHeap();
  while (scanf("%d\n", &value) != EOF) {
    fprintf(stderr, "READING INPUT: %d\n", value);
    if(value != 0){
      addHeap(value);
    }
  }
  printf("\n");

  printXMLHeap(1);

  printf("\n");

  int numOfElements = heapSize();
  int element;
  int i;

  //
  for(i = 0; i < numOfElements; i++){
    element = heapDelete();
    printf("%d\n", element);
    push(element);
  }

  printf("\n");

  //
  for(i = 0; i < numOfElements; i++){
    printf("%d\n", pop());
  }

  printf("\n");

  exit(0);
}
