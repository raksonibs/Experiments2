import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Controller implements ActionListener {
  private View view;
  private Model model;
  public static final String ROLL = "ROLL";
  
  public Controller() {
    
  }
  
  public void setModel(Model model) {
    this.model = model;
  }
  
  public void setView(View view) {
    this.view = view;
  }
  
  
  public void actionPerformed(ActionEvent event) {
    String action = event.getActionCommand();
    if (action.equals(ROLL)) {
      model.roll();
      String value = this.model.getValue();
      
      this.view.setRoll(value);
    }
  }

}
