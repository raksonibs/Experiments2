package symm;

import java.util.Arrays;

/***********************************
* CSE2011 - Assignment 2 
* File name: symm.java
* Author: Last name, first name
* Email: Your email address
* CSE number: Your cse number
************************************/

public class symm
{


/* 
 * Returns true if array A is symmetric.
 * Returns false otherwise.
 * n is the number of elements A contains.
 *
 * The running time of your algorithm is O( nlogn  ).
 * You may add a brief explanation here if you wish.
 */

public static boolean symmetric( int[] A, int n )
{
  
  if ( n <= 1 ) {
    return true;
  }
  if (A[0] == A[n-1]) {
    int[] B = Arrays.copyOfRange(A, 1, n-1);
    return symmetric(B, B.length);
  } else {
    return false;
  }

}  // end symmetric


}  // end class
