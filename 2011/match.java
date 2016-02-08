package symm;

/***********************************
* CSE2011 - Assignment 2
* File name: match.java
* Author: Last name, first name
* Email: Your email address
* CSE number: Your cse number
************************************/


public class match {

/*
 * EXHAUSTIVE ALGORITHM
 * Returns index i if array A contains an element A[i] such that A[i] = i.
 * If there exist many of such elements, return the index of any one of them.
 * Returns -1 if there exists no element A[i] such that A[i] == i.
 * n is the number of elements A contains.
 *
 * The running time of your algorithm is O( n ).
 * You may add a brief explanation here if you wish.
 */


public static int match_exh( int[] A, int n ) 
{

   // COMPLETE THIS METHOD.

   // You may define local variables inside this method.

   // You may add your own methods/subroutines to this file.
  
  int found = -1;
  
  for (int i =0; i < n; i++) {
    if (A[i] == i) {
      return i;
    }
  }
  
  return found;


} // end match_exh




/*
 * DIVIDE-AND-CONQUER ALGORITHM
 * Returns index i if array A contains an element A[i] such that A[i] = i.
 * If there exist many of such elements, return the index of any one of them.
 * Returns -1 if there exists no element A[i] such that A[i] == i.
 * n is the number of elements A contains.
 *
 * The running time of your algorithm is O( nlogn ).
 * You may add a brief explanation here if you wish.
 */

public static int match_dac( int[] A, int n )
{

   // COMPLETE THIS METHOD.

   // You may define local variables inside this method.

   // You may add your own methods/subroutines to this file.
  return modified_binary(A, 0, n-1);


}  // end match_dac

public static int modified_binary(int[] A, int left, int right) {
  if (left < right) {
    int centre = (left + right) / 2;
    
    if (A[centre] > centre) {
      return modified_binary(A, left, centre);
    } else if (A[centre] < centre) {
      return modified_binary(A, centre+1, right);
    } else {
      return centre;
    }
  } else if (left == right) {
    if (left == A[right]) {
      return left;
    }
  }
  
  return -1;
}


} // end class

