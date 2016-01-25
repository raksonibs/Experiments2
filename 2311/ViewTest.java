import static org.junit.Assert.*;

import java.math.BigInteger;

import org.junit.Before;
import org.junit.Test;

public class CalcViewTest {
  private CalcView c;

  @Before
  public void setUp() throws Exception {
    CalcController theController = new CalcController();
    c = new CalcView(theController);
  }

  @Test
  public void testClear() {
    c.setUserValue("3");
    BigInteger bi = BigInteger.valueOf(3);
    assertEquals(bi, c.getUserValue());
  }
  

}
