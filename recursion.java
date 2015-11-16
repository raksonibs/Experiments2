
public class PrintItToo {
  
  public static void main(String[] args) {
    int num = Fib(6);
    System.out.println(num);
  }
  
  public static void printItToo(String s, int n) {
    if (n == 0 ) {
      return;
    } else {
      System.out.print(s);
      printItToo(s, n-1);
    }
  }
  
  public static int Fib(int num) {
    if (num == 0) {
      return num;
    } else if (num == 1) {
      return num;
    } else {
      return Fib(num-1) + Fib(num-2);
    }
  }
  
  public static int countZeros(long num) {
    if ( num != 0 && num < 10) {
      return 0;
    } else if ( num == 0) {
      return 1;
    } else {
      boolean zero = (num % 10L == 0);
      final long m = num/10L;
      if (zero) {
        return 1 + countZeros(m);
      } else {
        return countZeros(m);
      }
    }
  }
  
  public static double powerOf10(int n) {
    if (n == 0) {
      return 1.0;
    } else if (n> 0) {
      return 10 * powerOf10(n-1);
    } else {
      return 1.0/ powerOf10(-n);
    }
  }
  
  public static boolean isPallindrome(String s) {
    if (s.length() < 2) {
      return true;
    } else {
    int first = 0;
    int last = s.length() -1;
    return (s.charAt(first) == s.charAt(last) && isPallindrome(s.substring(first+1, last)));
    }
  }
  
  public static void move(int n, String from, String to, String using) {
    if (n == 1) {
      System.out.println("move dirk from" + from + "to " + to);
      
    } else {
      move(n-1, from, using, to);
      move(1, from, to, using);
      move(n-1, using, to, from);
    }
  }
}
