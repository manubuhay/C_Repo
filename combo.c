 
 
#include <stdlib.h> 
#include <stdio.h>
 
 
#define uint32 unsigned int
 
typedef int (*CMPFUN)(int, int);

 
void HelperHeapSort(int This[], CMPFUN fun_ptr, uint32 first, uint32 the_len)
{
  /* heap sort */

  uint32 half;
  uint32 parent;

  if (the_len <= 1)
    return;

  half = the_len >> 1;
  for (parent = half; parent >= 1; --parent)
  {
    int temp;
    int level = 0;
    uint32 child;

    child = parent;
    /* bottom-up downheap */

    /* leaf-search for largest child path */
    while (child <= half)
    {
      ++level;
      child += child;
      if ((child < the_len) &&
          ((*fun_ptr)(This[first + child], This[first + child - 1]) > 0))
        ++child;
    }
    /* bottom-up-search for rotation point */
    temp = This[first + parent - 1];
    for (;;)
    {
      if (parent == child)
        break;
      if ((*fun_ptr)(temp, This[first + child - 1]) <= 0)
        break;
      child >>= 1;
      --level;
    }
    /* rotate nodes from parent to rotation point */
    for (;level > 0; --level)
    {
      This[first + (child >> level) - 1] =
        This[first + (child >> (level - 1)) - 1];
    }
    This[first + child - 1] = temp;
  }

  --the_len;
  do
  {
    int temp;
    int level = 0;
    uint32 child;

    /* move max element to back of array */
    temp = This[first + the_len];
    This[first + the_len] = This[first];
    This[first] = temp;

    child = parent = 1;
    half = the_len >> 1;

    /* bottom-up downheap */

    /* leaf-search for largest child path */
    while (child <= half)
    {
      ++level;
      child += child;
      if ((child < the_len) &&
          ((*fun_ptr)(This[first + child], This[first + child - 1]) > 0))
        ++child;
    }
    /* bottom-up-search for rotation point */
    for (;;)
    {
      if (parent == child)
        break;
      if ((*fun_ptr)(temp, This[first + child - 1]) <= 0)
        break;
      child >>= 1;
      --level;
    }
    /* rotate nodes from parent to rotation point */
    for (;level > 0; --level)
    {
      This[first + (child >> level) - 1] =
        This[first + (child >> (level - 1)) - 1];
    }
    This[first + child - 1] = temp;
  } while (--the_len >= 1);
}

 
#define INSERTION_SORT_BOUND 16 /* boundary point to use insertion sort */
 
/* explain function
 * Description:
 *   fixarray::Qsort() is an internal subroutine that implements quick sort.
 *
 * Return Value: none
 */
void Qsort(int This[], CMPFUN fun_ptr, uint32 first, uint32 last)
{
  uint32 stack_pointer = 0;
  int first_stack[32];
  int last_stack[32];

  for (;;)
  {
    if (last - first <= INSERTION_SORT_BOUND)
    {
      /* for small sort, use insertion sort */
      uint32 indx;
      int prev_val = This[first];
      int cur_val;

      for (indx = first + 1; indx <= last; ++indx)
      {
        cur_val = This[indx];
        if ((*fun_ptr)(prev_val, cur_val) > 0)
        {
          uint32 indx2;
          /* out of order */
          This[indx] = prev_val;

          for (indx2 = indx - 1; indx2 > first; --indx2)
          {
            int temp_val = This[indx2 - 1];
            if ((*fun_ptr)(temp_val, cur_val) > 0)
            {
              This[indx2] = temp_val;
            }
            else
              break;
          }
          This[indx2] = cur_val;
        }
        else
        {
          /* in order, advance to next element */
          prev_val = cur_val;
        }
      }
    }
    else
    {
      int pivot;
 
      /* try quick sort */
      {
	int temp;
	uint32 med = (first + last) >> 1;
        /* Choose pivot from first, last, and median position. */
        /* Sort the three elements. */
        temp = This[first];
        if ((*fun_ptr)(temp, This[last]) > 0)
        {
          This[first] = This[last]; This[last] = temp;
        }
        temp = This[med];
        if ((*fun_ptr)(This[first], temp) > 0)
        {
          This[med] = This[first]; This[first] = temp;
        }
        temp = This[last];
        if ((*fun_ptr)(This[med], temp) > 0)
        {
          This[last] = This[med]; This[med] = temp;
        }
        pivot = This[med];
      }
      {
        uint32 up;
        {
          uint32 down;
          /* First and last element will be loop stopper. */
          /* Split array into two partitions. */
          down = first;
          up = last;
          for (;;)
	  {
	    do
	    {
	      ++down;
	    } while ((*fun_ptr)(pivot, This[down]) > 0);
 
	    do
	    {
              --up;
            } while ((*fun_ptr)(This[up], pivot) > 0);
 
	    if (up > down)
	    {
	      int temp;
              /* interchange L[down] and L[up] */
              temp = This[down]; This[down]= This[up]; This[up] = temp;
	    }
	    else
	      break;
	  }
	}
        {
          uint32 len1; /* length of first segment */
          uint32 len2; /* length of second segment */
          len1 = up - first + 1;
          len2 = last - up;
          if (len1 >= len2)
          {
            if ((len1 >> 5) > len2)
            {
              /* badly balanced partitions, heap sort first segment */
              HelperHeapSort(This, fun_ptr, first, len1);
            }
            else
            {
              first_stack[stack_pointer] = first; /* stack first segment */
              last_stack[stack_pointer++] = up;
            } 
            first = up + 1;
            /*  tail recursion elimination of
             *  Qsort(This,fun_ptr,up + 1,last)
             */
          }
          else
          {
            if ((len2 >> 5) > len1)
            {
              /* badly balanced partitions, heap sort second segment */
              HelperHeapSort(This, fun_ptr, up + 1, len2);
            }
            else
            {
              first_stack[stack_pointer] = up + 1; /* stack second segment */
              last_stack[stack_pointer++] = last;
            }
            last = up;
            /* tail recursion elimination of
             * Qsort(This,fun_ptr,first,up)
             */
          }
        }
        continue;
      }
      /* end of quick sort */
    }
    if (stack_pointer > 0)
    {
      /* Sort segment from stack. */
      first = first_stack[--stack_pointer];
      last = last_stack[stack_pointer];
    }
    else
      break;
  } /* end for */
}
 
 
void ArraySort(int This[], CMPFUN fun_ptr, uint32 the_len)
{
  Qsort(This, fun_ptr, 0, the_len - 1);
}
 
#define ARRAY_SIZE 250000
 
int my_array[ARRAY_SIZE];
 
void fill_array()
{
  int indx;
 
  for (indx=0; indx < ARRAY_SIZE; ++indx)
  {
    my_array[indx] = rand();
  }
}
 
int cmpfun(int a, int b)
{
  if (a > b)
    return 1;
  else if (a < b)
    return -1;
  else
    return 0;
}
 
int main()
{
  int indx;
 
  fill_array();
 
  ArraySort(my_array, cmpfun, ARRAY_SIZE);

  for (indx=1; indx < ARRAY_SIZE; ++indx)
  {
    if (my_array[indx - 1] > my_array[indx])
    {
      printf("bad sort\n");
      return(1);
    }
  }
 
  return(0);
}
 
 
