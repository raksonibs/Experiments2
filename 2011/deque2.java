
/***********************************
* EECS2011 - Assignment 3
* File name: AnotherListDeque.java
* Author: Last name, first name
* Email: Your email address
* CSE number: Your cse number
************************************/


public class AnotherListDeque 
{

   protected DNode head, tail;  // head and tail contain actual data (int)

   protected int size;    // number of elements

   public AnotherListDeque()     // constructor: initialize an empty deque
   {
       head = tail = null;
       size = 0;
   }


    /**
     * Display the content of the deque
     *
     */
    public void printDeque( )
    {

	for ( DNode p = head; p != null; p = p.getNext() )
	    System.out.print( p.getElement() + " " );
	System.out.println();

    }


   // ***************************************
   // DO NOT MODIFY THE CODE ABOVE THIS LINE.
   // ADD YOUR CODE BELOW THIS LINE.
   //
   // ***************************************

   /**
     * Returns the number of items in this collection.
     * @return the number of items in this collection.
     */
    public int size( )
    {
        // COMPLETE THIS METHOD

      return size;   // replace this line with your code
    }


    /**
     * Returns true if this collection is empty.
     * @return true if this collection is empty.
     */ 
    public boolean isEmpty( )
    {
    	// COMPLETE THIS METHOD

      return (size == 0);   // replace this line with your code
    }


    /**
     * Returns the first element of the deque
     * 
     */
    public int getFirst( ) throws EmptyDequeException
    {
    	// COMPLETE THIS METHOD
    	
    	if (isEmpty()) {
    		throw new EmptyDequeException("List is empty");
    	}
    	
    	

      return head.getElement();   // replace this line with your code       
    }


    /**
     * Returns the last element of the deque
     * 
     */
    public int getLast( ) throws EmptyDequeException
    {
    	if (isEmpty()) {
    		throw new EmptyDequeException("List is empty");
    	}
    	
    	

      return tail.getElement();   // replace this line with your code   
    }


    /**
     * Inserts e at the beginning (as the first element) of the deque
     * 
     */
    public void insertFirst( int e )
    {
    	// COMPLETE THIS METHOD  
    	
    	if (size == 0) {
    		// head and tail equal one another
    		DNode newHead = new DNode(e, null, null);
    		head = newHead;
    		tail = newHead;
    	} else if (size == 1) {
    		DNode newHead = new DNode(e, null, null);
    		DNode oldHead = head;
    		head = newHead;
    		head.setNext(oldHead);
    		tail = oldHead;
    		tail.setPrev(head);
    	} else {
    		DNode newHead = new DNode(e, null, null);
    		DNode oldHead = head;
    		oldHead.setPrev(newHead);
    		head = newHead;
    		head.setNext(oldHead);
    	}
    	
    	size++;
    }


    /**
     * Inserts e at the end (as the last element) of the deque
     * 
     */
    public void insertLast( int e )
    {
    	if (size == 0) {
    		// head and tail equal one another
    		DNode newTail = new DNode(e, null, null);
    		head = newTail;
    		tail = newTail;
    	} else if (size == 1) {
    		DNode newTail = new DNode(e, null, null);
    		DNode oldTail = head;
    		head = oldTail;
    		head.setNext(newTail);
    		tail = newTail;
    		tail.setPrev(head);
    	} else {
    		DNode newTail = new DNode(e, null, null);
    		DNode oldTail = tail;
    		oldTail.setNext(newTail);
    		tail = newTail;
    		tail.setPrev(oldTail);
    	}
    	
    	size++; 
    }


    /**
     * Removes and returns the first element of the deque
     * 
     */
    public int removeFirst( ) throws EmptyDequeException
    {
    	if (isEmpty()) {
    		throw new EmptyDequeException("List is empty");
    	}
    	
    	DNode oldHead = head;
    	DNode newHead = head.getNext(); 
    	oldHead.setNext(null);
    	oldHead.setPrev(null);
    	head = newHead;		
    	size--;
    	
    	return oldHead.getElement();
    }


    /**
     * Removes and returns the last element of the deque
     * 
     */
    public int removeLast( ) throws EmptyDequeException
    {
    	if (isEmpty()) {
    		throw new EmptyDequeException("List is empty");
    	}
    	
    	DNode oldTail = tail;
    	DNode newTail = tail.getPrev(); 
    	oldTail.setNext(null);
    	oldTail.setPrev(null);
    	tail = newTail;		
    	size--;
    	
    	return oldTail.getElement();
    }


} // end class

