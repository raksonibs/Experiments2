import java.util.ArrayList;
import java.util.Set;


public class SavingsAccount {
  private double balance;
  public ArrayList<Transaction> transactions;
  
  public SavingsAccount() {
    this.balance = 0.0;
    this.transactions = new ArrayList<Transaction>();
  }
  
  public double getBalance() {
    return this.balance;
  }
  
  public void post(Transaction t)
            throws java.lang.NullPointerException {
    
    if (t == null) {
      throw new NullPointerException("Wrong");
    } else {
      boolean alreadyIn = false;
      for (Transaction tt : this.getTransactions()) {
        System.out.println(tt.toString());
        if (tt.equals(t)) {
          alreadyIn = true;
        }
      }
      if (!alreadyIn) {
        double amount = t.getAmount();
        this.transactions.add(t);
        this.balance += amount;
      }
      
    }
    
    
  }
  
  public ArrayList<Transaction> getTransactions() {
    return this.transactions;
  }
  

}
