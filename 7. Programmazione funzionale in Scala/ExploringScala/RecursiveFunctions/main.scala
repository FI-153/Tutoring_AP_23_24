object recursion {

  def factorial(n: Int): Int = {
    if (n == 1) 1
    else n * factorial(n - 1)
  }

  def factorial_TR(n: Int, a: Int): Int = {
    if (n == 1) a
    else factorial_TR(n - 1, a * n)
  }

  def main(args: Array[String]) = {

    println(factorial(5))
    println(factorial_TR(5, 1))

  }
}
