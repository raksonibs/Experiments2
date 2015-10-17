import java.util.Date;

public class Transaction implements Comparable<Transaction> {
  private Date date;
  private double amount;
  private String details;
  
  public Transaction( Date date, String details, double amount) {
    this.date = date;
    this.details = details;
    this.amount = amount;
  }
  
  public Date getDate() {
    return this.date;
  }
  
  public String getDetails() {
    return this.details;
  }
  
  public double getAmount() {
    return this.amount;
  }

  @Override
  public int compareTo(Transaction arg) {
    if (this.date == arg.date && this.amount == arg.amount && this.details == arg.details) {
      return 0;
    } else {
      if (this.date.compareTo(arg.date) < 0) {
        return -1;
      } else {
        return 1;
      }
    }
  }
  
  public boolean equals(Object obj) {
    if (obj != null && this.getClass() ==
        obj.getClass()) {
      Transaction trans = (Transaction) obj;
      System.out.println("over here");
      return Double.compare(this.amount, trans.amount) == 0 && trans.details.equals(this.details) && trans.date.equals(this.date);
    } else {
      System.out.println("over there");
      return false;
    }
  }
  
  public String toString() {
    return this.details + " " + this.amount;
  }
}
