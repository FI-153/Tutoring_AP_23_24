object valEncapsulation {

  def fun1(): Int => Int = {
    val y = 1
    def add(x: Int) = x + y

    add
  }

  def fun2(x: Int) = {
    val y = 2
    val f = fun1()

    println(f(x))
  }

  // The given y is encapsulated in the returned method
  def fun1_alt(y: Int): Int => Int = x => x + y
  def fun2_alt(x: Int, y: Int) = {
    val f = fun1_alt(y)
    println(f(x))
  }

  def main(args: Array[String]) = {

    /** The printed value is 10+1 and not 10+2. This happens because Scala sort
      * of "encapsulate" the value of y when the method add(x) is defioned in
      * fun1(). Redefining y before the call doesn't change its value.
      */
    fun2(10)

    /** The alternative allowing us to modify the value of y is to pass it in as
      * a parameter when defining the sum function. Encapsulation still happens
      * but this time it can be guided by the client
      */
    fun2_alt(10, 2)
  }
}
