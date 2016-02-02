public class WordAnalyzer {

   /**
    * Constructs an analyzer for a given word.
    * @param aWord the word to be analyzed 
    */
   public WordAnalyzer(String aWord) {
     word = aWord;
  }

  /**
  * Gets the first repeated character. A character is <i>repeated</i>
  * if it occurs at least twice in adjacent positions. For example,
  * 'l' is repeated in "hollow", but 'o' is not. 
  * @return the first repeated character, or 0 if none found
  */
  public char firstRepeatedCharacter() {
    char Result = 0;  // Not found

    for (int i = 0; Result == 0 && i < word.length(); i++) {
    char ch = word.charAt(i);
      if (ch == word.charAt(i + 1)) { Result = ch; }
    }
    return Result;
  }

  /**
   * Gets the first multiply occurring character. A character is <i>multiple</i>
   * if it occurs at least twice in the word, not necessarily in adjacent positions. 
   * For example, both 'o' and 'l' are multiple in "hollow", but 'h' is not. 
   * @return the first repeated character, or 0 if none found
   */
  public char firstMultipleCharacter() {
    char Result = 0;  // Not found

    for (int i = 0; Result == 0 && i < word.length(); i++) {
      char ch = word.charAt(i);
      if (find(ch, i) >= 0) { Result = ch; }
    }
    return Result;
  }

  private int find(char c, int pos) {
    int Result = -1;   // Not found
    for (int i = pos; Result == -1 && i < word.length(); i++) {
      if (word.charAt(i) == c)  { Result = i; }
    }
    return Result;
  }

  /**
   * Counts the groups of repeated characters. For example, "mississippi!!!" has 
   * four such groups: ss, ss, pp and !!!.
   * @return the number of repeated character groups 
   */
  public int repeatedCharacterGroupCount() {
    int Result = 0;
    for (int i = 1; i < word.length() - 1; i++) {
      if (word.charAt(i) == word.charAt(i + 1)) { // found a repetition
        if (word.charAt(i - 1) != word.charAt(i) || (i == 1 && word.charAt(i) == word.charAt(i+1)) )  { // start of a repetition
          Result++;
        }
      }
    }
    System.out.println(Result);
    return Result;
  }

  /**
   * A palindrome is a word that is spelled the same forwards and backwards.
   * Example: "radar" is a palindrome
   * 
   * @return true if the word is a palindrome.
   */
  public boolean palindrome() {
    boolean Result = true;  // Assume palindrome til proven false
    int front = 0;
    int back = word.length()-1;

    while (front <= back) {
      if (word.charAt(front) == word.charAt(back)) {
        front++; back--;
      }
    }
    return Result;
  }

  private String word;
}

