package array;

import java.io.PrintStream;
import java.util.Scanner;
import java.util.Stack;
import java.util.regex.*;


public class que
{
  private static final String OPEN = "([{";
  private static final String CLOSE = ")]}";
  private static Stack<Character> precedenceOps;

  public static void main(String[] args)
  {
    PrintStream output = System.out;
    output.println("Enter expression:");
    Scanner input = new Scanner(System.in);
    String expression = input.nextLine();
    input.close();
    
//    String pattern = "[\[\]]";
//    
//    Pattern r = Pattern.compile(pattern);
//    
//    Matcher m;
    
    // Your code goes here.
    
    Stack stack = new Stack();
    
    String final = "";
    
    for (int i = 0; i<expression.length(); i++) {
      String s = expression.substring(i, i+1);
//      m = r.matcher(s);
//      System.out.println(s);
      if (OPEN.contains(s)) {
        System.out.println("match FRONT");
        stack.push(s);
//        push onto stack
      } else if (CLOSE.contains(s)) {
        String topVal = stack.pop();
        if (expression.indexOf(ch));
//        [a+b*(c-d])
        
      }
    }
    
  }
}
