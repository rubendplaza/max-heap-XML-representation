/**
 *  The functions in this module implement a Heapdata structure
 *  of integers.
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

//static int MAX_SIZE = 1000;
static int size = 0;
static int heap[1000];

static unsigned int depth = 0;

//Sets the max integer at the 0th position, makes the implementation simpler if indexing from 1
void initHeap(){
  heap[0] = INT_MAX;
}

/**
 * heapSize() returns the number of items in the Heap.
 *
 */
int heapSize()
{
  return size;
}

//Postion of parent
int parent(int position){
  return (position / 2);
}

//Returns left child
int leftChild(int position){
  return (2 * position);
}

//Returns right child
int rightChild(int position){
  return ((2 * position) + 1);
}

//Checks if we are dealing with a leaf
bool isALeaf(int position){
  if(heap[leftChild(position)] == 0 && heap[rightChild(position)] == 0){
    return true;
  }
  return false;
}

//Check if we are dealing with a leaf
bool isLeaf(int position){ 
  if (position >= (heapSize() / 2) && position <= heapSize()) { 
    return true; 
      } 
        return false; 
    } 

//Swaps two values, changing their indexes
void swap(int positionOne, int positionTwo){
  int temp;
  temp = heap[positionOne];
  heap[positionOne] = heap[positionTwo];
  heap[positionTwo] = temp;
}

void maxHeapify(int position){
  //printf("Max heapifying: %d\n", heap[position]);
  if(isALeaf(position)){
    //printf("Is leaf: %d\n", heap[position]);
    return;
  }
  if(heap[position] < heap[leftChild(position)] || 
     heap[position] < heap[rightChild(position)]){

       if(heap[leftChild(position)] > heap[rightChild(position)]){
         //printf("Swapping %d and %d\n", heap[position], heap[leftChild(position)]);
         swap(position, leftChild(position));
         maxHeapify(leftChild(position));
       }
       else{
         //printf("Swapping %d and %d\n", heap[position], heap[rightChild(position)]);
         swap(position, rightChild(position));
         maxHeapify(rightChild(position));
       }
  }
}

/**
 *  addHeap(thing2add) adds the "thing2add" to the Heap.
 *
 */
void addHeap(int thing2add){
  heap[++size] = thing2add;
  int currentPosition = size;
  while(heap[currentPosition] > heap[parent(currentPosition)]){
    swap(currentPosition, parent(currentPosition));
    currentPosition = parent(currentPosition);
  }
}

/**
 * heapDelete() removes the biggest integer in the heap and returns it.
 *
 */
int heapDelete(){
  int root = 1;
  int removed = heap[root];
  heap[root] = heap[size--];
  heap[size+1] = 0;
  maxHeapify(root);
  return removed;
}

// void printHeap(){
//   int i;
//   for(i = 1; i <= size / 2; i++){
//     if(heap[i] != 0)
//       printf("Parent: %d ", heap[i]);
//     if(heap[2*i] != 0)
//       printf("Left Child: %d ", heap[2*i]);
//     if(heap[(2*i)+1] != 0)
//       printf("Right Child: %d\n", heap[(2*i)+1]);
//   }
// }

static void showRecursionDepth(){
  int i;
  for(i = 0; i < depth; i++){
    printf("    ");
  }
}

//Call this function w/ position 1
void printXMLHeap(int position){

  if(heap[1] == 0){
    return;
  }

  showRecursionDepth();
  depth++;
  if(isALeaf(position)){
    printf("<node id=\"%d\">\n", heap[position]);
    depth--;
    showRecursionDepth();
    printf("</node>\n");
    
  }
  else{
    printf("<node id=\"%d\">\n", heap[position]);
    if(heap[2*position] != 0){
      printXMLHeap(2*position);
    }
    if(heap[(2*position)+1] != 0){
      printXMLHeap((2*position)+1);
    }
    depth--;
    showRecursionDepth();
    printf("</node>\n");
    
  }
}


