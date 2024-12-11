/** Duck typing can be implemented in Scala. Normally it doesn't use it
  */
import reflect.Selectable.reflectiveSelectable
object duckTyping {

  /** This method takes as an input whichever object a that is a subtype of A
    * based in its interface. In this instance we can consider subtypes of A all
    * those types which integrate a "speak()" method
    */
  def emitASound[A <: { def speak(): Unit }](a: A) = a.speak()

  class Dog() { def speak() = println("woof") }
  class Car() { def speak() = println("Brum Brum") }
  class Klingon() { def speak() = println("Heghlu'meH QaQ jajvam") }

  def main(args: Array[String]) = {
    emitASound(new Dog)
    emitASound(new Car)
    emitASound(new Klingon)
  }

}
