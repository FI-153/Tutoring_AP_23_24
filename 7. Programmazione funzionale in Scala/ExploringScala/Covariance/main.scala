/** Akin to Java, scala is covariant on the return type but invariant in the
  * parameters
  */
sealed abstract class Shape {
  def getShape(): Shape;
}
case class Circle(r: Int) extends Shape {
  override def getShape(): Circle = this
}
case class Rectangle(b: Int, h: Int) extends Shape {
  override def getShape(): Rectangle = this
}

object covariance {
  def main(args: Array[String]) = {

    val c = Circle(3)
    val r = Rectangle(2, 3)

    println(c.getShape())
    println(r.getShape())
  }
}
