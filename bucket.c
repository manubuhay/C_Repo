#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
#include <codecogs/array/sort/bucketsort.h>



void bucketSort(int array[], int n) {
   int i, j;
   int count[n];
   for(i=0; i < n; i++) {
     count[i] = 0;
   }
 
   for(i=0; i < n; i++) {
     (count[array[i]])++;
   }
 
  for(i=0,j=0; i < n; i++) {
   for(; count[i]>0; (count[i])--) {
     array[j++] = i;
    }
   }

}


int main() 
{
int array[] = {1,31,14,61,4,12,9,11,21,19};
int n = 10;
int i;

for (i = 0;i < n;i++) {
printf("%d ", array[i]);
}
printf("\n");


bucketSort(array, n);

for (i = 0;i < n;i++) {
printf("%d ", array[i]);
}
printf("\n");


   return 0;
}
