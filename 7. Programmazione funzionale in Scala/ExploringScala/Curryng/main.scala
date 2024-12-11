import scala.math

/** Currying means taking a method that takes in nultiple value or a tuple of
  * them and turning it into a series of concatenated functions that returns the
  * same result with only 1 input per method.
  */
object currying {

  def sum(x: Int, y: Int, z: Int): Int = x + y + z
  def sumCurred(x: Int): Int => (Int => Int) = y => (z => x + y + z)

  def concatenate(a: List[Int], b: List[Int], c: List[Int]) = a ::: b ::: c
  def concatenateCurred(a: List[Int]): List[Int] => (List[Int] => List[Int]) =
    b => (c => a ::: b ::: c)

  def squareRootOfCubeOfSum(a: Int, b: Int): Double =
    Math.sqrt(Math.pow((a + b), 3))

  def squareRootOfCubeOfSumCurred(a: Int): Int => Double = b =>
    (Math.sqrt(Math.pow((a + b), 3)))

  /** Attention: These customized ifs are "strict" meaning both the thenPart and
    * elsePart are evaluated once the method is called (For more information see
    * "byNamebyValue"). This is not what a real if does! Since each part is
    * evaluated only when the corresponding condition is met
    */
  def myIf(cond: Boolean, thenPart: Int, elsePart: Int) =
    if (cond) thenPart else elsePart

  def myIfCurring(cond: Boolean): Int => (Int => Int) = {
    thenPart => (elsePart => if (cond) thenPart else elsePart)
  }

  /** Now these ifs are "non-strict" since the thenPart and the elsePart are
    * passed by name
    */
  def myIf_nonStrict(cond: Boolean, thenPart: => Int, elsePart: => Int) =
    if (cond) thenPart else elsePart

  def myIfCurring_nonStrict(cond: Boolean): (=> Int) => ((=> Int) => Int) = {
    thenPart => (elsePart => if (cond) thenPart else elsePart)
  }

  def myInt(x: Int): Int = {
    println("Evaluated: " + x)
    x
  }

  def main(args: Array[String]) = {
    println(sum(2, 4, 6))
    println(sumCurred(2)(4)(6))

    println()

    println(concatenate(List(1, 2, 3), List(4, 5), List(6, 7, 8, 9)))
    println(concatenateCurred(List(1, 2, 3))(List(4, 5))(List(6, 7, 8, 9)))

    println()

    println(squareRootOfCubeOfSum(2, 5))
    println(squareRootOfCubeOfSumCurred(2)(5))

    println()

    println(myIf((1 < 2), myInt(10), myInt(20)))
    println(myIf((2 < 2), myInt(10), myInt(20)))
    println(myIfCurring(1 < 2)(myInt(10))(myInt(20)))
    println(myIfCurring(3 < 2)(myInt(10))(myInt(20)))

    println()

    println(myIf_nonStrict((1 < 2), myInt(10), myInt(20)))
    println(myIf_nonStrict((2 < 2), myInt(10), myInt(20)))
    println(myIfCurring_nonStrict(1 < 2)(myInt(10))(myInt(20)))
    println(myIfCurring_nonStrict(3 < 2)(myInt(10))(myInt(20)))

  }
}
