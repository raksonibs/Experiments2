import java.util.Date;

public final class Transaction implements Comparable<Transaction>{
  private double amount;
  private Date date;
  private String details;
  
  public Transaction(Date date, String details, double amount) {
    this.date = new Date(date.getTime());
    this.details = details;
    this.amount = amount;
  }
  
  @Override
  public int compareTo(Transaction arg0) {
    // TODO Auto-generated method stub
    return 0;
  }
  
}
