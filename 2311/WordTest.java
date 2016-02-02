import static org.junit.Assert.*;

import java.math.BigInteger;

import org.junit.Test;
import org.junit.Before;

public class WordAnalyzerTest {
	private WordAnalyzer c;
	private WordAnalyzer d;
	private WordAnalyzer e;
	private WordAnalyzer f;
	
	@Before
	public void setUp() throws Exception {
		c = new WordAnalyzer("mississippi!!!");
		d = new WordAnalyzer("misssssssss");
		e = new WordAnalyzer("mi");
		f = new WordAnalyzer("dddddmissss");
	}

	@Test
	public void testClear() {
		assertEquals(4, c.repeatedCharacterGroupCount());
		assertEquals(1, d.repeatedCharacterGroupCount());
		assertEquals(0, e.repeatedCharacterGroupCount());
		assertEquals(2, f.repeatedCharacterGroupCount());
	}

}

