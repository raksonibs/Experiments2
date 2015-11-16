
public class Model {
  private Die die;
  public Model() {
    this.die = die;
  }
  
  public String getValue() {
    return String.valueOf(this.die.getValue());
  }
  
  public void roll() {
    this.die.roll();
  }
}
