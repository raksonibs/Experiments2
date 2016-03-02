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
	private int size = 0;
	/**
	 * Returns the number of items in this collection.
	 * @return the number of items in this collection.
	 */
	public int size()
	{
		// COMPLETE THIS METHOD

		// Hint: size can be computed from capacity, front and rear.

		return size;   // replace this line with your code
	}


	/**
	 * Returns true if this collection is empty.
	 * @return true if this collection is empty.
	 */ 
	public boolean isEmpty()
	{
		if (size() == 0)
			return true;   // replace this line with your code
		else 
			return false;
	}


	/**
	 * Returns the first element of the deque
	 * 
	 */
	public int getFirst() throws EmptyDequeException
	{
		if (isEmpty())
			throw new EmptyDequeException("");
		// COMPLETE THIS METHOD     

		return A[front];   // replace this line with your code       
	}


	/**
	 * Returns the last element of the deque
	 * 
	 */
	public int getLast( ) throws EmptyDequeException
	{
		// COMPLETE THIS METHOD   
		int last = (rear - 1 + size) % size;
		return A[last];   // replace this line with your code         
	}


	/**
	 * Inserts e at the beginning (as the first element) of the deque
	 * 
	 */
	public void insertFirst( int e )
	{
		int avail = 0;
		if (size == 0) {
			A[front] = e;
			rear++;
			front++;
		}else if (size < capacity) {
			avail = (front - 1 + capacity) % capacity;
			A[avail] = e;
		} else {
			//System.out.println("Hi hello");
			int[] T = new int[capacity * 2];
			for (int i = 0; i < capacity; ++i)
				T[i] = A[i];
			A = T;
			capacity *= 2;
			A[capacity - 1] = e;
			//for (int i = 1; i < capacity; ++i) {
			//	T[i] = A[i-1];
			//}
			//A = T;
		}
		front = (front - 1 + capacity) % capacity;
		size++;

		// COMPLETE THIS METHOD   
	}


	/**
	 * Inserts e at the end (as the last element) of the deque
	 * 
	 */
	public void insertLast( int e )
	{
		int checker = 0;
		if (size == 0) {
			A[rear] = e;
			rear++;
		}else if (size < capacity) {
			int avail = (front + size) % capacity;
			A[avail] = e;
		} else {
			int[] T = new int[capacity * 2];
			for (int i = 0; i < capacity; ++i) {
				T[i] = A[i];
				//System.out.println(T[i] + " / " + A[i]);
			}
			A = T;
			A[capacity] = e;
			capacity *= 2;
			rear = front + size;
		}
		size++;
		rear = (front + size) % capacity;
			
		
		//System.out.println("size: " + sz + " / capacity: " + capacity);
		// COMPLETE THIS METHOD   
	}


	/**
	 * Removes and returns the first element of the deque
	 * 
	 */
	public int removeFirst( ) throws EmptyDequeException
	{
		int j = 0;
		if (isEmpty()) 
			return 0;
		if (size < capacity/4 && size > 8) {
			int[] T = new int[capacity / 2];
			for (int i = front; i != rear; ++i){
				T[j] = A[i];
				++j;
			}
			
			A = T;
			capacity /= 2;
			front = 0;
			rear = front + size;
		}
		int first = A[front];
		A[front] = 0;
		front = (front + 1) % capacity;
		size--;
		if (size == 0) 
			front = rear = 0;
		return first;   // replace this line with your code	
	}


	/**
	 * Removes and returns the last element of the deque
	 * 
	 */
	public int removeLast( ) throws EmptyDequeException
	{
		if (isEmpty())
			return 0;
		if (size < capacity/4 && size > 8) {
			int[] T = new int[capacity / 2];
			for (int i = (front + size); i > 0; --i)
				T[i] = A[i];
			A = T;
			capacity /= 2;
			rear = capacity - 1;
			front = 0;
			rear = front + size;
		}
		int lastIndex = (rear - 1 + size) % size;
		int last = A[lastIndex];
		A[lastIndex] = 0;
		size--;
		rear = (front + size) % capacity;
		if (size == 0) 
			front = rear =0;
		return last;
		// COMPLETE THIS METHOD		

	}

}  // end class


