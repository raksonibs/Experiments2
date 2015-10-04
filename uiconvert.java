/** This utility class facilitates conversion from metric units to
 *  imperial units.
 */
public class UnitConverter
{
  /** Represents the number of centimetres in an inch. */
  public static final double CM_PER_INCH = 2.54;
  /** Represents the number of kg in pounds. */
  public static final double KG_PER_POUND = 2.20462;
  /** Represents the 1 c per f. */
  public static final double C_PER_F = 33.8;
  
  // Include additional constants here as needed.
  // Use the one above as a guide.
  ;
  
  
  // This line prevents clients from instantiating the class.
  private UnitConverter() {}
  
  
  /** Converts the passed value in centimetres to the corresponding
   *  length in inches.
   *  
   *  @param cm A length in centimetres.
   *  @return The passed length in inches.
   */
  public static double cmToInches(double cm)
  {
    double result = cm / CM_PER_INCH;
    return result;
  }
  
  
  /** Converts the passed value in kg to the corresponding
   *  pounds.
   *  
   *  @param kg Wieght bitch.
   *  @return other bitch.
   */
  public static double kgToPounds(double kg)
  {
    // Your code goes here.
    double result = kg * KG_PER_POUND;
    return result;
  }
  
  
  /** Converts the passed value in kg to the corresponding
   *  pounds.
   *  
   *  @param c more stuff
   *  @return christ
   */
  public static double cToFahrenheit(double c)
  {
    double result = c * C_PER_F;
    return result;
  }
}