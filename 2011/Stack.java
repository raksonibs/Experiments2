package assign1;

import java.util.EmptyStackException;

public interface Stack {
public int size();
public boolean isEmpty();
public Object top()
throws EmptyStackException;
public void push(Object o);
public Object pop()
throws EmptyStackException;
}
