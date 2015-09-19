import java.util.Scanner;

public class DateTest {
  private int date;
  
  public void setDate(int dateR) {
    date = dateR;
  }
  
  public void outputDate() {
    String value = "";
    String out = Integer.toString(date);
    System.out.println(out);
  }
}



public class DateDemo {
  public static void main(String[] args) {
    DateTest dateD = new DateTest();
    int date = 12;
    
    dateD.setDate(date);
    
    dateD.outputDate();
    
  }
}
