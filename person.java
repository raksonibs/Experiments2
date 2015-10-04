public class Person
{
  private String name;
  private int age;
  private String contactInfo;
  
  
  public Person() {}
  
  public Person(String namePassed, int agePassed, String contactInfoPassed) {
    if (agePassed < 0) {
       throw new IllegalArgumentException("Age cannot be negative");
    } else {
    this.name = namePassed;
    this.age = agePassed;
    this.contactInfo = contactInfoPassed;
    }
  }
  public int compareTo(Person other) {
    if (other.name == this.name && other.contactInfo == this.contactInfo && other.age == this.age) {
      return 0;
    } else {
      if (other.name.compareTo(this.name) > 0) {
        return -1;
      } else {
        return 1;
      }
    }
  }
  
  public String toString() {
    String val = this.name + ", age: " + this.age + ", contact: " + this.contactInfo;
    return val;
  }
  
  public boolean equals(Object obj) {
    return this == obj;
  }
  
  public String getName() {
    return this.name;
  }
  
  public int getAge() {
    return this.age;
  }
  
  public void setName(String name) {
    this.name = name;
  }
  
  
  
  // TODO: Write your code here.
  ;
    
}