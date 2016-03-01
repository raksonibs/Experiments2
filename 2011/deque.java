package deque;

/***********************************
* EECS2011 - Assignment 3
* File name: ListDeque.java
* Author: Last name, first name
* Email: Your email address
* CSE number: Your cse number
************************************/


public class ListDeque 
{

   protected DNode header, trailer;  // dummy nodes

   protected int size;    // number of elements

   public ListDeque()     // constructor: initialize an empty deque
   {
      header = new DNode( 0, null, null );
      trailer = new DNode( 0, null, null );
      header.setNext(trailer);  // make header point to trailer
      trailer.setPrev(header);  // make trailer point to header
      size = 0;
   }


    /**
     * Display the content of the deque
     *
     */
    public void printDeque( )
    {
	for ( DNode p = header.getNext(); p != trailer; p = p.getNext() )
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
      

      return size;   // replace this line with your code
    }


    /**
     * Returns true if this collection is empty.
     * @return true if this collection is empty.
     */ 
    public boolean isEmpty( )
    {
    	return (size == 0);
    }


    /**
     * Returns the first element of the deque
     * 
     */
    public int getFirst( ) throws EmptyDequeException
    {
    	

    	if (isEmpty()) {
    		throw new EmptyDequeException("List is empty");
    	}
     
     return header.getNext().getElement();
    		 
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
        
        return trailer.getPrev().getElement();       
    }


    /**
     * Inserts e at the beginning (as the first element) of the deque
     * 
     */
    public void insertFirst( int e )
    {   
    	DNode oldFirst = header.getNext();
    	DNode newFirst = new DNode(e, null, null);
    	newFirst.setNext(oldFirst);
    	newFirst.setPrev(header);
    	header.setNext(newFirst);
    	oldFirst.setPrev(newFirst);
       size++;
    }


    /**
     * Inserts e at the end (as the last element) of the deque
     * 
     */
    public void insertLast( int e )
    {
    	DNode oldLast = trailer.getPrev();
    	DNode newLast = new DNode(e, null, null);
    	newLast.setPrev(oldLast);
    	newLast.setNext(trailer);
    	trailer.setPrev(newLast);
    	oldLast.setNext(newLast);
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
    	
    	DNode oldheader = header.getNext();
    	
    	DNode newheader = oldheader.getNext();
    	
    	header.setNext(newheader);
    	newheader.setPrev(header);
    	
    	oldheader.setNext(null);
    	oldheader.setPrev(null);
    	size--;

      return oldheader.getElement();   // replace this line with your code	
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
    	
    	DNode oldtrailer = trailer.getPrev();
    	
    	DNode newtrailer = oldtrailer.getPrev();
    	
    	trailer.setPrev(newtrailer);
    	newtrailer.setNext(trailer);
    	
    	oldtrailer.setNext(null);
    	oldtrailer.setPrev(null);

    	size--;

      return oldtrailer.getElement();
    }


} // end class
