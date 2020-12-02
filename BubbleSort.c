// Bubble sort in C
#include <stdio.h>
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

  for (int step = 0; step < size - 1; ++step) 
  {
    for (int i = 0; i < size - step - 1; ++i) 
    {
      // To sort in descending order, change">" to "<".
      if (data[i] > data[i + 1]) 
      {
        int temp = data[i];
        data[i] = data[i + 1];
        data[i + 1] = temp;
      }
    }
  }

  printf("Sorted Array in Ascending Order:\n");
  for (int i = 0; i < n; ++i) 
  {
    printf("%d  ", data[i]);
  }
}