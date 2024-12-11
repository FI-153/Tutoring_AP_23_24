object lazyVal {

  def main(args: Array[String]) = {

    lazy val a = { println("Created 'a'"); 10 }

    println("Doing stuff...")

    // Up to this point "a" has not been created, notice how 'Doing stuff...' is printed first.
    // Once the value has been created we can use it
    println(a)

    // Here "a" has already been created and so we just get its value
    println(a)

    // There is no such thing as a "lazy var"
    // lazy var = 0;

  }
}
