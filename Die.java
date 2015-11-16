import java.util.Random;

public class Die {
  private int value;
  private final int SIDES = 6;
  private Random rng;
  
  public Die() {
    rng = new Random(System.currentTimeMillis());
    value = 1;
  }
  
  public int getValue() {
    return value;
  }
  
  public void roll() {
    value = rng.nextInt(SIDES) + 1;
  }
}
