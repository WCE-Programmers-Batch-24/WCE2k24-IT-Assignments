/* Binary Search using Iteration */

/* Major Condition : Array must be sorted for Binary Search */

#include <stdio.h>
int main()
{
  int c, first, last, middle, n, search, array[100];

  printf("Enter number of elements\n"); 
  scanf("%d", &n);

  printf("Enter %d integers\n", n);

  for (c = 0; c < n; c++)  // Taking the input
    scanf("%d", &array[c]);

  printf("Enter value to find\n");
  scanf("%d", &search);
/* In Binary Search, We split the array in two subarrays,
   if target is less than the mid, we traverse the left subarray
   if target is greater than mid, we traverse the right subarray 
   and do the same procedure */
  first = 0;
  last = n - 1;
  middle = (first+last)/2;

  while (first <= last) {
    if (array[middle] < search)
      first = middle + 1;
    else if (array[middle] == search) {
      printf("%d found at location %d.\n", search, middle+1);
      break;
    }
    else
      last = middle - 1;

    middle = (first + last)/2;
  }
  if (first > last)
    printf("Not found! %d isn't present in the list.\n", search);

  return 0;
}
