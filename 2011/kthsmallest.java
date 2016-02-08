package symm;

/***********************************
* CSE2011 - Assignment 2
* File name: kthsmallest.java
* Author: Last name, first name
* Email: Your email address
* CSE number: Your cse number
************************************/


public class kthsmallest {

public static final int MaxSize = 500;

/*
 * Return the value of the kth smallest element of array A.
 * n is the number of elements A contains, and k <= n.
 * The running time of your algorithm must be O(n).
 *
 */

public static int find_kth_smallest( int[] A, int n, int k )
{
  int[] B = A; //make a copy of the array;
  return find_kth_smallest_rec(B, n, k); //call helper method
}  

public static int find_kth_smallest_rec( int[] A, int n, int k )
{
  
  int mid = (n-1)/2; //calculate a midpoint
  int pivot = A[mid]; //make the pivot
  int tempA = A[0]; //make a temp variable to let me switch the pivot and the first variable in the array
  
  A[0] = pivot; //swap
  A[mid] = tempA;
  
  int[] high_p = new int[MaxSize]; //make two temporary arrays
  int[] low_p = new int[MaxSize];
  int hc = 0, lc = 0; //counters to record the size of the arrays
//  i am sorting the whole array am I not here?
  
  for (int i = 1; i < n; i++)
  {
    if (A[i] < pivot) // sorting into large and small arrays
    {
      low_p[lc] = A[i];
      lc++;
    }
    else if (A[i] > pivot)
    {
      high_p[hc] = A[i];
      hc++;
    }   
  }
  
  if (k <= lc) // k should be in the left side
    return find_kth_smallest_rec(low_p, lc , k);
  else if (k > n - hc) //k is in the right side
    return find_kth_smallest_rec(high_p, hc  , k - (n - hc));
  
  return pivot; //k is the pivot
}

} // end class




