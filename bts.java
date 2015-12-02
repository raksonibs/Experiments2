package array;

import java.io.PrintStream;
import java.util.Scanner;


/**
 * This class encapsulates a binary search tree.
 * @author Steven Castellucci, 2015
 */
public class BinarySearchTree<E extends Comparable<? super E>>
              // Ensure the parameterized type can be sorted.
{
  private Node<E> root;
  
  
  /**
   * Initializes an empty binary search tree.
   */
  public BinarySearchTree()
  {
    root = null;
  }
  
  
  
  /**
   * Adds the passed value to the tree.
   * @param value the value to add to the tree
   */
  public void add(E value)
  {
    root = addNode(root, value);
  }
  
  // Solves 'add' recursively.
  private Node<E> addNode(Node<E> root, E value)
  {
    Node<E> result = null;
    if (root == null) // Base case, add node here.
    {
      result = new Node<E>(value, null, null);
    }
    else if (root.data.compareTo(value) > 0) // Recursive case, go left.
    {
      root.leftSubTree = addNode(root.leftSubTree, value);
      result = root;
    }
    else // Recursive case, go right.
    {
      root.rightSubTree = addNode(root.rightSubTree, value);
      result = root;
    }
    return result;
  }
  
  public void add(E value) {
    Node<E> result = null;
    if (root == null) {
      result = new Node(value, null. null);
    } else if(value.compareTo(root.data) > 0) {
      root.rightSubtree = addNode(root.rightSubTree, value);
      result = root;
    } else {
      root.leftSubTree = addNode(root.leftSubTree, value);
      result = root;
    }
    
    return result;
  }
  
  
  /**
   * Removes the passed value from the tree. The tree is not changed
   * if it does not contain the passed value.
   * @param value the value to remove from the tree.
   */
  public void remove(E value)
  {
    root = removeNode(root, value);
  }
  
  private Node<E> removeNode(Node<E> root, E value) {
    Node<E> result = null;
    if (root != null && root.data.compareTo(value) == 0) {
      if (root.leftSubTree == null) {
        result = root.rightSubTree;
      } else if (root.rightSubTree == null) {
        result = root.leftSubTree;
      } else {
        root.data = largestValue(root.leftSubTree);
        root.leftSubTree = removeLargestNode(root.leftSubTree);
      }
      
    } else if (root.data.compareTo(value) > 0) {
      root.leftSubTree = removeNode(root.leftSubTree, value);
      result = root;
    } else {
      root.rightSubTree = removeNode(root.rightSubTree, value);
      result = root;
    }
    
    return result;
  }
  
  // Solves 'remove' recursively.
  private Node<E> removeNode(Node<E> root, E value)
  {
    Node<E> result = null;
    if (root != null && root.data.compareTo(value) == 0)
      // Base case, remove this node.
    {
      if (root.leftSubTree == null) // Case 1 or 2 (i.e., 0 or 1 child)
      {
        result = root.rightSubTree; // null if Case 1, not null if Case 2
      }
      else if (root.rightSubTree == null) // Case 2 (i.e., 1 child on left)
      {
        result = root.leftSubTree;
      }
      else // Case 3 (i.e., 2 children)
      {
        root.data = largestValue(root.leftSubTree);
        root.leftSubTree = removeLargestNode(root.leftSubTree);
      }
    }
    else if (root.data.compareTo(value) > 0) // Recursive case, go left.
    {
      root.leftSubTree = removeNode(root.leftSubTree, value);
      result = root;
    }
    else // Recursive case, go right.
    {
      root.rightSubTree = removeNode(root.rightSubTree, value);
      result = root;
    }
    return result;
  }
  
  // Returns the largest value in the subtree rooted at 'root'.
//  private E largestValue(Node<E> root)
//  {
//    E result = null;
//    if (root.rightSubTree == null) // Base case, this node has largest.
//    {
//      result = root.data;
//    }
//    else // Recursive case, keep going right.
//    {
//      result = largestValue(root.rightSubTree);
//    }
//    return result;
//  }
  
  private E largestValue(Node<E> root) {
    E result = null;
    if (root.rightSubTree == null) {
      result = root.data;
    } else {
      result = largestValue(root.rightSubTree);
    }
    
    return result;
  }
  
  private E smallestValue(Node<E> root) {
    E result = null;
    if (root.leftSubTree == null) {
      result = root.data;
    } else {
      result = smallestValue(root.leftSubTree);
    }
    
    return result;
  }
  
  
  public boolean contains(E x) {
    return contains(x, root);
  }
  
  public boolean contains(E x, Node<E> root) {
    if (root == null) {
      return false;
    }
    
    int compared = x.compareTo(root.data);
    
    if (compared > 0) {
      return contains(x, root.leftSubTree);
    } else if (compared < 0) {
      return contains(x, root.rightSubTree);
    } else {
      return true;
    }
  }
  
  public int size() {
    return size(root);
  }
  private int size(Node<E> root) {
    if (root.leftSubTree == null && root.rightSubTree == null) {
    return 0;
  } else {
    return size(root.leftSubTree) + size(root.rightSubTree) + 1;
  }
  }
  
  
  private boolean contains(E x) {
    return contains( x, root );
  }
  
  private boolean contains(E x, Node<E> root) {
    if (root == null) {
      return false;
    } 
    
    int compareResult = x.compareTo(root.data);
//    if smaller
    if (compareResult < 0) {
      return contains(x, root.leftSubTree);
    } else if (compareResult > 0) {
      return contains(x, root.rightSubTree);
    } else {
      return true;
    }
  }
  
  // Removes the node with the largest value in the subtree rooted at 'root'.
  private Node<E> removeLargestNode(Node<E> root)
  {
    Node<E> result = null;
    if (root.rightSubTree == null) // Case 1 or 2 (i.e., 0 or 1 child)
    {
      result = root.leftSubTree; // null if Case 1, not null if Case 2
    }
    else
    {
      root.rightSubTree = removeLargestNode(root.rightSubTree);
      result = root;
    }
    return root;
  }
  
  
  
  public String toString()
  {
    StringBuffer sb = new StringBuffer();
    infixPrint(root, sb);
    return sb.toString().trim();
  }
  
  // Prints the elements in infix order.
  private void infixPrint(Node<E> root, StringBuffer sb)
  {
    if (root != null)
    {
      infixPrint(root.leftSubTree, sb);
      sb.append(root.data + " ");
      infixPrint(root.rightSubTree, sb);
    }
  }
  
  
  
  public static void main(String[] args)
  {
    Scanner input = new Scanner(System.in);
    PrintStream output = System.out;
    BinarySearchTree<Integer> bst = new BinarySearchTree<Integer>();
    
    output.println("Enter a list of non-negative integers. Enter -1 to end.");
    for (int i = input.nextInt(); i != -1; i = input.nextInt())
    {
      bst.add(i);
    }
    
    output.println("\nIn sorted order:");
    output.println(bst.toString() + "\n");
    output.println("\nContains 5 should be true:");
    output.println(bst.contains(5));
    output.println("\nContains 7 should be false:");
    output.println(bst.contains(7));
    output.println("\nsize should be 8:");
    output.println(bst.size());
    output.println("\nsmallest 1:");
//    output.println(bst.smallestVal(5));
  }
  
  
  /*
   * This static nested class encapsulates a node in the tree.
   */
  private static class Node<E>
  {
    private E data;
    private Node<E> leftSubTree;
    private Node<E> rightSubTree;
    
    public Node(E data, Node<E> leftSubTree, Node<E> rightSubTree)
    {
      this.data = data;
      this.leftSubTree = leftSubTree;
      this.rightSubTree = rightSubTree;
    }
  }
}