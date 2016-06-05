package assign1;
//all O(1) except ad and remove which is O(n)

public class LArrayList<E> implements List<E> {
    private E[] data;
    public static final int CAPACITY = 16;
    private int size = 0;
    protected Node head, tail;
    private SLinkedList<E> list = new SLinkedList<>(); // an empty list public LinkedQueue() { } // new queue relies on the initially empty list public int size() { return list.size(); }
    
    public LArrayList() {
      head = tail = null;
        size = 0;
    }
    
    public LArrayList(int capacity) {
      data = (E[]) new Object[capacity];
    }
    
    /**
     * Display the content of the deque
     *
     */
    public void printDeque( )
    {

  for ( Node p = head; p != null; p = p.getNext() )
      System.out.print( p.getElement() + " " );
  System.out.println();

    }
    
    public void add(int i, E e) {
      checkIndex(i, size + 1);
      list.addLast(e);
      
      
      size++;
    }
    
    public int size() {
        return size;
    }
    
    public boolean isEmpty() {
        return list.isEmpty();
    }
    
    public E get(int i) {
        checkIndex(i, size);
        return (E) list.get(i);
    }
    
    public E remove(int i) throws IndexOutOfBoundsException {
      checkIndex(i, size);
      E temp = (E) list.remove(i);
      return temp;
    }

  @Override
  public E set(int i, E e) throws IndexOutOfBoundsException {
    checkIndex(i, size);
    return (E) list.set(e, i);
  }
  
  protected void checkIndex(int i, int n) throws IndexOutOfBoundsException {
    if (i < 0 || i >= n) {
      throw new IndexOutOfBoundsException("illegal index: " + i);
    }
  }
}
