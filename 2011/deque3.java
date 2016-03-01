/***********************************
* EECS2011 - Assignment 3
* File name: ArrayDeque.java
* Author: Last name, first name
* Email: Your email address
* CSE number: Your cse number
************************************/


public class ArrayDeque
{
   public static final int INIT_CAPACITY = 8;	// initial array capacity
   protected int capacity;  // current capacity of the array
   protected int front;     // index of the front element
   protected int rear;      // index of the rear element
   protected int[] A;	    // array deque

   public ArrayDeque( )      // constructor method
   {
      A = new int[ INIT_CAPACITY ];
      capacity = INIT_CAPACITY;
      front = rear = 0;
   }


    /**
     * Display the content of the deque
     * 
     */
    public void printDeque( )
    {
      for ( int i = front; i != rear; i = (i+1) % capacity )
	System.out.print( A[i] + " " );
      System.out.println();
    }


    /**
     * Display the content of the whole array
     *
     */
    public void printArray( )
    {
	for ( int i = 0; i < capacity; i++ )
	   System.out.print( A[i] + " " );
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
    	 return (capacity - front + rear) % capacity;
    }


    /**
     * Returns true if this collection is empty.
     * @return true if this collection is empty.
     */ 
    public boolean isEmpty( )
    {
    	return  front == rear;
    }


    /**
     * Returns the first element of the deque
     * 
     */
    public int getFirst() throws EmptyDequeException
    {
    	if (isEmpty()) {
            throw new EmptyDequeException("Deque is empty.");
        }
    	
        return A[front % capacity];      
    }


    /**
     * Returns the last element of the deque
     * 
     */
    public int getLast( ) throws EmptyDequeException
    {
    	if (isEmpty()) {
            throw new EmptyDequeException("Deque is empty.");
        }
    	
        return A[ (rear - 1) % capacity];        
    }


    /**
     * Inserts e at the beginning (as the first element) of the deque. Extend y two
     * 
     */
    public void insertFirst( int e )
    {
    	if (capacity < INIT_CAPACITY) {
    		capacity = INIT_CAPACITY;
    	}
    	//capcity or cacpity - 1?
        if(size() == capacity - 1){
        	capacity= capacity*2;
        }
        
        int[] B = new int[capacity];
        
        for(int i = 0; i < size(); i++){
            B[i] = A[i];
        }
        
        A = B;
        
        for(int i = size(); i >= front; i--){
            A[i+1] = A[i];
        }
        
        rear++;
        A[front] = e;
        front = front % capacity;
    }


    /**
     * Inserts e at the end (as the last element) of the deque
     * 
     */
    public void insertLast( int e )
    {
    	if (capacity < INIT_CAPACITY) {
    		capacity = INIT_CAPACITY;
    	}
    	
    	if(size() == capacity - 1) {
            capacity= capacity*2;
       }

       int[] B = new int[capacity];
       
       for(int i = 0; i < size(); i++) {
           B[i] = A[i];
       }

       A = B;

       A[rear] = e;
       
       rear = (rear + 1) % capacity;
    }


    /**
     * Removes and returns the first element of the deque
     * 
     */
    public int removeFirst( ) throws EmptyDequeException
    {
    	
        if(isEmpty()){
            throw new EmptyDequeException("Deque is empty.");
        }
        
        else if(capacity >= 8){
        	 
            if(size() < capacity/4 && size() > 8){
                capacity /= 2;
                int[] B = new int[capacity];
                int counter=0;
                for(int i = front; i < front+size(); i++){
                    B[counter] = A[i%(capacity*2)];
                    counter++;
                }

                A = B;
                front = 0;
                rear = size() - 1;
            }
        }
        
        int result = A[front];
        
        A[front] = 0;
        front = (front+1)%capacity;

        return result;
    }


    /**
     * Removes and returns the last element of the deque
     * 
     */
    public int removeLast( ) throws EmptyDequeException
    {
    	 if(isEmpty()){
    	        throw new EmptyDequeException("Deque is empty.");
    	    }
    	    else if(capacity >= 8){
    	        if(size() < capacity/4 && size() > 8){
    	            int[] B = new int[capacity/2];
    	            for(int i = 0; i < capacity/2; i++){
    	                B[i] = A[i];
    	            }
    	            A = B;
    	        }
    	    }
    	    int temp = A[rear - 1];
    	    A[rear] = 0;
    	    rear = (rear - 1) % capacity;
    	    return temp;
    }

}  // end class

