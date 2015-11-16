import java.awt.GridLayout;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;

public class View extends JFrame {
  private JLabel rollValue;
  private JButton rollButton; 
  
  public View(Controller controller, Model model) {
    super("View");
    this.rollValue = new JLabel(model.getValue());
    
    this.rollButton = new JButton("Roll");
    
    this.rollButton.addActionListener(controller);
    this.rollButton.setActionCommand(Controller.ROLL);
    
    this.setLayout(new GridLayout(2,1));
    this.add(rollValue);
    this.add(rollButton);
    this.pack();
    
    this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
  }
  
  public void setRoll(String value){
    this.rollValue.setText(value);
  }
}
