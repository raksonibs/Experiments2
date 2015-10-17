
public class TakeANumber {
  public static final TakeANumber INSTANCE = new TakeANumber();
  private int number;
  
  private TakeANumber() {
    this.number = 0;
  }
  
  public int takeTicket() {
    this.number += 1;
    return number;
  }
  
  public static TakeANumber getInstance() {
    return TakeANumber.INSTANCE;
  }

}
