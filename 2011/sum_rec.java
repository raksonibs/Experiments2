package symm;

import java.util.Arrays;

/***********************************
* CSE2011 - Assignment 2
* File name: sum.java
* Author: Last name, first name
* Email: Your email address
* CSE number: Your cse number
************************************/


public class sum {


/*
 * EXHAUSTIVE ALGORITHM
 * Returns true if array A contains two elements whose sum is k.
 * Returns false otherwise.
 * n is the number of elements A contains.
 *
 * The running time of your algorithm is O( n^2 ).
 * You may add a brief explanation here if you wish.
 */

public static boolean sum_exh( int[] A, int n, int k )
{
  boolean truth = false;
  
  for (int i = 0; i < n; i++) {
    for (int j=0; j<n;j++) {
      if (i != j) {
        if (A[i] + A[j] == k) {
          return true;
        }
      }
    }
  }
  
  return truth;

}  // end sum_exh





/*
 * RECURSIVE ALGORITHM
 * Returns true if array A contains two elements whose sum is k.
 * Returns false otherwise.
 * n is the number of elements A contains.
 *
 * The running time of your algorithm is O(  ).
 * You may add a brief explanation here if you wish.
 */

public static boolean sum_rec( int[] A, int n, int k )
{
  
  int sum = A[0] + A[n-1];
  if (sum == k) {
    return true;
  }

  if (n <= 2 && sum != k) {
    return false;
  }
  
  
  if (sum > k) {
    int[] B = Arrays.copyOfRange(A, 0, n-1);
    return sum_rec(B, B.length, k);
  } else {
    int[] B = Arrays.copyOfRange(A, 1, n);
    return sum_rec(B, B.length, k);
  }

}  // end sum_rec


} // end class

