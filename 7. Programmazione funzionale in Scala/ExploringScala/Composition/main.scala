object composition {

  def sqr(x: Int) = x * x
  def cube(x: Int) = x * x * x

  def squareOfTheCube(x: Int) = sqr(cube(x))
  def cubeOfTheSquare(x: Int) = cube(sqr(x))

  // Given two methods we can compese them together to get a composed method accpeting an Int
  def compose(f: Int => Int, g: Int => Int): Int => Int = x => f(g(x))

  def main(args: Array[String]) = {
    println(squareOfTheCube(3))
    println(cubeOfTheSquare(3))

    val comp = compose(sqr, cube)
    println(comp(3))

    // Using the composed method with a map reduces the code to type
    val l = List(1, 2, 3, 4)
    println(l.map(x => comp(x)))
    println(l.map(compose(sqr, cube)))
    println(l.map(sqr).map(cube))
  }
}
