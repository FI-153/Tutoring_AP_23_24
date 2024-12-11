object basics {
  def main(args: Array[String]) = {

    var p = new Person("Federico", 23)
    p.setAge(24)

    p.married = true
    println(p.getMerried())

    p.theResultOfTheSecretStuff()
  }
}

//It is not necessary to create a file for each class.
//The class Person has the main definition embedded in the "class" definition

/** Creates a Person with 2 fields
  *
  * @param name
  * @param age
  */
class Person(
    val name: String,
    private var age: Int
) {

  // Internal attribute, public by default
  var married: Boolean = false

  // Auxiliry constructor
  def this(name: String, age: Int, married: Boolean) = {
    this(name, age)
    this.married = married;
  }

  // Method, public by default
  def setAge(newAge: Int) = {
    println("Changing age to: " + newAge)
    age = newAge
  }

  def getMerried(): Boolean = married

  // This internal method is private, so is not part of the interface. It can therfore be moved to a companion object
  // private def doSomeSecretStuff(): Integer = 0;

  // The companion class can access its companion objectc's private methods and attributes
  def theResultOfTheSecretStuff() = println(Person.doSomeSecretStuff())
}

/** Companion object of Person. The "object" acts lile a singleton to overcome
  * the abascence of static fields in Scala
  */
object Person {
  private def doSomeSecretStuff(): Integer = 0
}
