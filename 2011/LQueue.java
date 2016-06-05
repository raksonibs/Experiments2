package assign1;

public class LQueue<E> implements Queue<E> {
  public static final int INIT_CAPACITY = 8;  // initial array capacity
  protected int capacity;  // current capacity of the array
  protected int front;     // index of the front element
  protected int rear;      // index of the rear element
  private E[] A;      // array deque
  private int size = 0;
  
  private SLinkedList<E> list = new SLinkedList<>(); // an empty list public LinkedQueue() { } // new queue relies on the initially empty list public int size() { return list.size(); }
  public boolean isEmpty() { return list.isEmpty(); }

  public E first() { return list.first(); }
  public E dequeue() { return list.removeFirst(); }
  
  @Override
  public int size() {
    // TODO Auto-generated method stub
    return list.size();
  }
  @Override
  public Object front() throws EmptyQueueException {
    // TODO Auto-generated method stub
    if (list.isEmpty()) {
      throw new EmptyQueueException("Empty exception");
    }
    
    return list.first();
  }
  @Override
  public void enqueue(Object o) {
    // TODO Auto-generated method stub
     list.addLast((E) o);
    
  }
}

