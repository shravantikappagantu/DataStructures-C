// Bubble sort in C

#include <stdio.h>

void bubbleSort(int array[], int size) 
{
  for (int step = 0; step < size - 1; ++step) 
  {
    for (int i = 0; i < size - step - 1; ++i) 
    {
      // To sort in descending order, change">" to "<".
      if (array[i] > array[i + 1]) 
      {
        int temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
      }
    }
  }
}

// function to print the array
void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

int main() 
{
  int n;
  printf("enter size of the array");
  scanf("%d",&n);
  int data[n];
  for (int i = 0; i < n; ++i) 
  {
    scanf("%d  ", &data[i]);
  }
  bubbleSort(data, n);
  printf("Sorted Array in Ascending Order:\n");
  printArray(data, n);
}