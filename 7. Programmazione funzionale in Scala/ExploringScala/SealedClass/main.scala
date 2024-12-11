/** Defining a class or trait as sealed is used to limit its extension by other
  * classes. Declaring it as final doesn't allow for any other class or trait to
  * extend it whilst making it public allows everyone everywhere to do it
  *
  * A sealed class or trait can be freely extended but only within the same
  * source file.
  */

sealed abstract class SealedShape
case class MyCircle(r: Int) extends SealedShape
case class MyRectangle(b: Int, h: Int) extends SealedShape

def area(s: SealedShape): Double | Int = {
  s match {
    case MyCircle(r)       => 3.14 * r * r
    case MyRectangle(b, h) => b * h
  }
}

object sealedClass {
  def main(args: Array[String]) = {

    println(area(MyCircle(3)))
    println(area(MyRectangle(3, 4)))

  }
}
