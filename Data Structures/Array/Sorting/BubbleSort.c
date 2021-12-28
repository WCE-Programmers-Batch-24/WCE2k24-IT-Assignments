/* Bubble sort code */
#include <stdio.h>

int main()
{
  int array[100], n, i, j, swap;

  printf("Enter number of elements\n"); 
  scanf("%d", &n);

  printf("Enter %d integers\n", n); //taking the inputs

  for (i = 0; i < n; i++)
    scanf("%d", &array[i]);
/* In Bubble Sort, We just compare Elements one after the other
   and swap them, if needed */
  for (i = 0 ; i < n - 1; i++)
  {
    for (j = 0 ; j < n - i - 1; j++)
    {
      if (array[j] > array[j+1]) /* For decreasing order use '<' instead of '>' */
      {
        swap       = array[j];
        array[j]   = array[j+1];
        array[j+1] = swap;
      }
    }
  }

  printf("Sorted list in ascending order:\n");

  for (i = 0; i < n; i++)
     printf("%d\n", array[i]); // Printing the sorted array.

  return 0;
}
