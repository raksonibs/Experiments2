
public class App {
  public static void main(String[] args) {
    Controller controller = new Controller();
    Model model = new Model();
    View view = new View(controller, model);
    controller.setModel(model);
    controller.setView(view);
    view.setVisible(true);
  }
}
