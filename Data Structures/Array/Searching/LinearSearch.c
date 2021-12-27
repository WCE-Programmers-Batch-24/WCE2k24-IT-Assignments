/* Code For Linear Search*/

#include <stdio.h>
int main()
{
  int array[100], search, i, n;

  printf("Enter number of elements in array\n");
  scanf("%d", &n);

  printf("Enter %d integer(s)\n", n); //Taking the inputs.

  for (i = 0; i < n; i++)
    scanf("%d", &array[i]);

  printf("Enter a number to search\n");
  scanf("%d", &search);
/* In Linear search, We just Compare the required element with
   each element in the array */
  for (i = 0; i < n; i++)
  {
    if (array[i] == search)    /* If required element is found */
    {
      printf("%d is present at location %d.\n", search, i);
      break;
    }
  }
  if (i == n)
    printf("Element not found.\n");

  return 0;
}
