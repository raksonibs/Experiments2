package assign1;

public interface Queue {
public int size();
public boolean isEmpty();
public Object front()
throws EmptyQueueException;
public void enqueue(Object o);
public Object dequeue()
throws EmptyQueueException;
}
