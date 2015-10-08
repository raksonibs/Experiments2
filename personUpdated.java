/**
 * The class encapsulates a contact person in an addressbook
 * @author oskarniburski
 *  The class encapsulates a contact person in an addressbook
 */

public class Person
{
  private String name;
  private int age;
  private String contactInfo;
  
  public Person(String namePassed, int agePassed, String contactInfoPassed) throws IllegalArgumentException {
    if (agePassed < 0) {
      throw new IllegalArgumentException("Too ageless");
    } else {
      setName(namePassed);
      setAge(agePassed);
      setContactInfo(contactInfoPassed);
    }
  }
  
  public String getName() {
    /**
     * 
     * Sets this person's name
     * 
     * @param name the name to set
     */
    return this.name;
  }
  
  public int getAge() {
    return this.age;
  }
  
  public String getContactInfo() {
    return this.contactInfo;
  }
  
  public void setName(String name) {
    this.name = name;
  }
  
  public void setAge(int age) throws IllegalArgumentException {
    /**
     * 
     * Sets this perosn'a age
     * 
     * @param age ageguy
     * @throws <code>IllegalArgumentException</code> if age <0
     */
    if (age < 0) {
      
    } else {
      this.age = age;
    }
  }
  
  public String toString() {
      String val = getName() + ", age: " + getAge() + ", contact: " + getContactInfo();
      return val;
    }
  
  public void setContactInfo(String contactInfo) {
    this.contactInfo = contactInfo;
  }

  public int compareTo(Person other) {
    // TODO Auto-generated method stub
    if (other.name.compareTo(this.name) > 0) {
      return -1;
    } else {
      if (other.equals(this)) {
        return 0;
      } else {
        return 1;
      }
    }
  }
  
  public boolean equals(Object object) {
    boolean equal;
    
    if (object != null && this.getClass() == object.getClass()) {
      Person other = (Person) object;
      equal = (this.age == other.age && this.contactInfo == other.contactInfo && this.name == other.name);
    } else {
      equal = false;
    }
    
    return equal;
  }
    
}