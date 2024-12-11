import scala.math

object byNameByValue {

  def a(): Int = {
    println("Creo a")
    return 2
  }

  def b(): Int = {
    println("Creo b")
    return 4
  }

  /** Parameters are passed by value
    *
    * @param a
    * @param b
    */
  def opPBV(a: Int, b: Int): Int = a * (a + b)

  /** Parametrs are passed by name
    *
    * @param a
    * @param b
    */
  def opPBN(a: => Int, b: => Int): Int = a * (a + b)

  def timesTwoPBV(a: Int, b: Int): Int = a * 2

  def timesTwoPBN(a: => Int, b: => Int) = a * 2

  def main(args: Array[String]) = {
    println("-- PBV --")
    println(opPBV(a(), b()))
    println("-- PBN --")

    /*In the output we can see that a() was called twice, since its value is used two times and thus evaluated two times.
     *In this instance PBV was faster since it needed just one call for both parameters.
     */
    println(opPBN(a(), b()))

    println("-- PBV --")
    println(timesTwoPBV(a(), b()))

    println("-- PBN --")
    /*This time PBN was fasteer than PBV since we don't use b() in the method so it doesn't need to be evaluated.
     *PBV always evalutes the expressions passed as parameters regardles of their use.
     */
    println(timesTwoPBN(a(), b()))
  }
}
