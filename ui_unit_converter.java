import java.io.PrintStream;
import java.util.Scanner;

/** This class serves as the user interface for the UnitConverter
 *  class.
 */
public class UnitConverterUI
{
  public static void main(String[] args)
  {
    PrintStream out = System.out;
    Scanner in = new Scanner(System.in);
    
    out.println("Conversion codes:");
    out.println(" 1: cm -> inches");
    out.println(" 2: kg -> pounds");
    out.println(" 3: \u00B0C -> \u00B0F");
    out.print("Enter the value to convert: ");
    double value = in.nextDouble();
    out.print("Enter the conversion code:  ");
    int code = in.nextInt();
    
    double result;
    
    result = 0;
    
    if (code == 1) {
      result = UnitConverter.cmToInches(value);
    } else if (code == 2) {
      result = UnitConverter.kgToPounds(value);
    } else if (code == 3) {
      result = UnitConverter.cToFahrenheit(value);
    } else {
      out.println("Screwed up idiot");
    }
    // Your code to convert the values goes here.
    
    out.printf("The converted value is %.3f.\n", result);
  }
}