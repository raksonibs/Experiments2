import java.util.Scanner;

public class Bill {
  private static double fee;
  private static double price;
  private static int numProd;
  
  public static void getInput() {
//    grab items, caculate cost, put bill
    Scanner input = new Scanner(System.in);
    
    System.out.println("INput the price, and then the numProd");
    
    price = input.nextDouble();
    
    numProd = input.nextInt();
    
  }
//  make private so can be accessed
  private double putPrice(double pricePlaced, int numProducts) {
    fee = pricePlaced * numProducts;
    return fee;
  }
  
  public void updateFee() {
    putPrice(price, numProd);
  }
  
  public static void outputPrice() {
    System.out.println("Your price is " + fee);
  }
}



public class BillTest {
  public static void main(String[] args) {
    Bill bill = new Bill();
    bill.getInput();
    
    bill.updateFee();
    
    bill.outputPrice();
  }
}
