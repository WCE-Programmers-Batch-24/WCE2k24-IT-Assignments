/* C Program to Implement Binary Search using recursion */


/* Major Condition : Array must be sorted for Binary Search */

/* In Binary Search, We split the array in two subarrays,
   if target is less than the mid, we traverse the left subarray
   if target is greater than mid, we traverse the right subarray 
   and do the same procedure */
/* Algorithm :
Step 1 : Find the middle element of array. using ,
middle = initial_value + end_value / 2 ;
Step 2 : If middle = element, return ‘element found’ and index.
Step 3 : if middle > element, call the function with end_value = middle - 1 .
Step 4 : if middle < element, call the function with start_value = middle + 1 .
Step 5 : exit.
*/

#include <stdio.h>
int recursiveBinarySearch(int array[], int start_index, int end_index, int element){
   if (end_index >= start_index){
      int middle = start_index + (end_index - start_index )/2;
      if (array[middle] == element)
         return middle;
      if (array[middle] > element)
         return recursiveBinarySearch(array, start_index, middle-1, element);
      return recursiveBinarySearch(array, middle+1, end_index, element);
   }
   return -1;
}
int main(void){
   int array[] = {1, 4, 7, 9, 16, 56, 70};
   int n = 7;
   int element;
   printf("Enter the element to be searched :\n");
   scanf("%d",&element);
   int found_index = recursiveBinarySearch(array, 0, n-1, element);
   if(found_index == -1 ) {
      printf("Element not found in the array ");
   }
   else {
      printf("Element found at index : %d",found_index);
   }
   return 0;
}
