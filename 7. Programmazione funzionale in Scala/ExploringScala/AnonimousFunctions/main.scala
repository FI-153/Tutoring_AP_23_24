object anonimousFuncts {

  def identity(x: Int): Int = x
  def sqr(x: Int) = x * x
  def cube(x: Int) = x * x * x

  // Defined like this we're saying that the method can accept a function defined on Int and
  // returning Int, menaning a function that only takes in an Int and only returns an Int
  def somma(f: Int => Int, a: Int, b: Int): Int = {
    if (a == b) f(a)
    else f(a) + somma(f, a + 1, b)
  }

  def main(args: Array[String]) = {

    // The sum of numbers between 1 and 10: 1/2n(n+1)
    println(somma(identity, 1, 10))

    // The sum of numbers betweeen 1 and 10, all squared
    println(somma(sqr, 1, 10))

    // The sum of numbers between 1 and 10, all cubed
    println(somma(cube, 1, 10))

    // The same things could be obtained w/o the need to define the methods outside the call
    println(somma(x => x, 1, 10))
    println(somma(x => x * x, 1, 10))
    println(somma(x => x * x * x, 1, 10))

  }
}
