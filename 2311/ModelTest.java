import static org.junit.Assert.*;

import java.math.BigInteger;

import org.junit.Test;
import org.junit.Before;

public class CalcModelTest {
  private CalcModel c;
  
  @Before
  public void setUp() throws Exception {
    c = new CalcModel();
  }

  @Test
  public void testClear() {
    assertEquals(BigInteger.ZERO, c.getCalcValue());
  }
  
  @Test
  public void testSum() {
    c.sum(BigInteger.TEN);
    BigInteger bi = BigInteger.valueOf(10);
    assertEquals(bi, c.getCalcValue());
  }
  
  @Test
  public void testSubtract() {
    c.subtract(BigInteger.TEN);
    BigInteger bi = BigInteger.valueOf(-10);
    assertEquals(bi, c.getCalcValue());
  }
  
  @Test
  public void testMultiply() {
    c.multiply(BigInteger.TEN);
    assertEquals(BigInteger.ZERO, c.getCalcValue());
    c.sum(BigInteger.TEN);
    c.multiply(BigInteger.TEN);
    BigInteger bi = BigInteger.valueOf(100);
    assertEquals(bi, c.getCalcValue());
  }
  
  @Test
  public void testDivide() {
    c.divide(BigInteger.TEN);
    assertEquals(BigInteger.ZERO, c.getCalcValue());
    c.sum(BigInteger.TEN);
    c.multiply(BigInteger.ONE);
    BigInteger bi = BigInteger.valueOf(10);
    assertEquals(bi, c.getCalcValue());
  }

}
