import java.util.Scanner;
2 /**
3 Class for a temperature (expressed in degrees Celsius). 4 */
5 public class Temperature
6{
7 private double degrees; //Celsius
￼8 public Temperature() 9{
Note that this class has a main method and both static and nonstatic methods.
10 11
12 13 14 15
16 17 18 19
20 21 22 23
24
25
26
27
28
29
30
31
32
33
34
35
36
degrees = 0; }
 public Temperature (double initialDegrees)
{
     degrees = initialDegrees;
}
 public void setDegrees (double newDegrees)
{
     degrees = newDegrees;
}
 public double getDegrees()
{
     return degrees;
}
public String toString()
{
    return (degrees + "C");
}
public boolean equals(Temperature otherTemperature)
{
     return (degrees == otherTemperature.degrees);
}
/**
 Returns number of Celsius degrees equal to
 degreesF Fahrenheit degrees.
*/
Static Methods and Static Variables 267 Display 5.3 Another Class with a main Added (part 2 of 2)
37 public static double toCelsius(double degreesF)
38 {
39
40 return 5*(degreesF - 32)/9;
￼41 }
42 public static void main(String[] args) class Temperature, this is equivalent to
43 {
44 double degreesF, degreesC;
45
46 Scanner keyboard = new Scanner(System.in);
47 System.out.println("Enter degrees Fahrenheit:");
48 degreesF = keyboard.nextDouble();
49
50 degreesC = toCelsius(degreesF); 51
52 Temperature temperatureObject = new Temperature(degreesC);
53 System.out.println("Equivalent Celsius temperature is"
Because this is in the definition of the Temperature.toCelsius(degreesF).
￼
54
55 }
56 }
