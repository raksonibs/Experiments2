package linkedlist;

public class LinkedList {
  private int size;
  private Node head;
  
  public LinkedList() {
    this.size = 0;
    this.head = null;
  }
  
  private static class Node {
    private char data;
    private Node next;
    
    public Node(char c) {
      this.data = c;
      this.next = null;
//      always initilizes the next node to be null
    }
    
  }
  
  public void add(char c) {
    if (this.size == 0) {
//      adds to beginning
      this.head = new Node(c);
    } else {
//      adds to end
      LinkedList.add(c, this.head);
    }
    this.size++;
  }
  
  private static void add(char c, Node node) {
    if (node.next == null) {
//      if last one
      node.next = new Node(c);
//      when create a new node, it adds another null reference to the end
    } else {
      LinkedList.add(c, node.next);
    }
  }
  
  public char get(int index) {
    if (index < 0 || index >= this.size) {
      throw new IndexOutOfBoundsException("Out of bounds");
    }
    
    return LinkedList.get(index, this.head);
  }
  
  public static char get(int index, Node node) {
    if (index == 0 ) {
      return node.data;
    }
    
    return LinkedList.get(index - 1, node.next);
  }
  
  public void set(int index, char c) {
    if (index < 0 || index >= this.size) {
      throw new IndexOutOfBoundsException("adsad");
    }
    LinkedList.set(index, c, this.head);
  }
  
  public static void set(int index, char c, Node node) {
    if (index == 0) {
      node.data = c;
      return;
    }
    
    LinkedList.set(index -1, c, node.next);
  }
  
  public String toString() {
    if (this.size == 0) {
      return "[]";
    }
    
    return "[" + LinkedList.toString(this.head);
  }
  
  private static String toString(Node n) {
    if (n.next == null) {
      return n.data + "]";
    }
    String s = n.data +", ";
    return s + LinkedList.toString(n.next);
  }
  
  public boolean contains(char c) {
    if (this.size == 0) {
      return false;
    }
    
    return LinkedList.contains(c, this.head);
  }
  
  private static boolean contains(char c, Node node) {
    if (node.data == c) {
      return true;
    } 
    
    if (node.next == null) {
      return false;
    }
    
    return LinkedList.contains(c,  node.next);
  }
  
  public int indexOf(char c) {
    if (this.size == 0) {
      return -1;
    }
    
    return LinkedList.indexOf(c, this.head);
  }
  
  public static int indexOf(char c, Node node) {
    if (node.next == null) {
      return -1;
    }
    
    if (node.data == c) {
      return 0;
    }
    
    int i = LinkedList.indexOf(c, node.next);
    
    if (i == -1) {
      return -1;
    } else {
      return 1 + i;
    }
  }
  
  public void addFirst(char c) {
    Node newNode = new Node(c);
    newNode.next = this.head;
    this.head = newNode;
    this.size++;
  }
  
  public static void add(int index, char c, Node prev) {
    if (index == 0) {
      Node newNode = new Node(c);
      newNode.next = prev.next;
      prev.next = newNode;
      return;
    }
    
    LinkedList.add(index -1, c, prev.next);
  }
  
  public void add(int index, char c) {
//    NTD: nunderstands this?
    if (index == 0) {
      this.addFirst(c);
    } else {
      LinkedList.add(index -1, c, this.head);
      this.size++;
    }
  }
  
  public char removeFirst() {
    if (this.size == 0) {
      
    }
    Node curr = this.head;
    this.head = curr.next;
    curr.next = null;
    this.size--;
    return curr.data;
  }
  
  public static char remove(int index, Node prev, Node curr) {
    if (index == 0) {
      prev.next = curr.next;
      curr.next = null;
      return curr.data;
    }
//    I don't really understand if the index is just zero? I guess if the index is 8 and we count eight times until zero, which is basically what we are doing, we then remove
    
    return LinkedList.remove(index -1, curr, curr.next);
  }
  
  public char remove(int index) {
    if (index == 0) {
      return this.removeFirst();
    } else {
      char result = LinkedList.remove(index - 1, this.head, this.head.next);
//      why do I have to decrease the size reach time. Oh, because they will all be removed and delinked? I think so!
      this.size--;
      return result;
    }
  }
  
  
  
  
}
