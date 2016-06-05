package assign1;

public class AQueue<E> {
  public static final int INIT_CAPACITY = 8;  // initial array capacity
  protected int capacity;  // current capacity of the array
  protected int front;     // index of the front element
  protected int rear;      // index of the rear element
  private E[] A;      // array deque
  private int size = 0;
  
  public AQueue()      // constructor method
  {
    this(INIT_CAPACITY);
    capacity = INIT_CAPACITY;
    front = rear = 0;
  }
  
  public AQueue(int initCapacity) {
    A = (E[]) new Object[capacity];
  }

  public void printDeque( )
  {
    for ( int i = front; i != rear; i = (i+1) % capacity )
      System.out.print( A[i] + " " );
    System.out.println();
  }
  
  public int size() {
    return size;
  }
  
  public boolean isEmpty() {
    if (size() == 0) {
      return true;
    }  
    
    return false;
  }
  
  public Object front()
  throws EmptyQueueException {
    if (isEmpty()) {
      throw new EmptyQueueException("Queue is empty.");
    }

    return A[front];
  }
  
  public void enqueue(Object e) throws FullQueueException {
    if (size == A.length) throw new FullQueueException("Queue is full");
    int avail = (front + size) % A.length; // use modular arithmetic
    A[avail] = (E) e;
    size++;
  }
  
  public Object dequeue()
  throws EmptyQueueException {
    if (isEmpty()) return null;
    E answer = A[front];
    A[front] = null;
    front = (front + 1) % A.length;
    size--;
    return answer;
  }
}
