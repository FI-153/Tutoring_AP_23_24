object matchEitherOption {

  def errorMsg(errorCode: Int): String = {
    errorCode match {
      case 0 => "Error '0'"
      case 1 => "Error '1'"
      case _ => "Undefined"
    }
  }

  def division(a: Float, b: Float): Either[String, Float] = {
    b match {
      case 0 => Left("Cannot divide by 0")
      case _ => Right(a / b)
    }
  }

  def division_option(a: Float, b: Float): Option[Float] = {
    if (b != 0) Some(a / b)
    else None
  }

  def main(args: Array[String]) = {

    /*
     * By matching the input value we can customize the behavior
     */
    println(errorMsg(0))
    println(errorMsg(2))

    /*
     * Using Either we can return either a value of one type or a value of another type.
     * By convention the Left side is dedicated to errors whilst the Right one to actual results.
     * We always have to match te result to address the output
     */
    division(2, 3) match {
      case Left(l)  => println(l)
      case Right(r) => println(r)
    }

    division(2, 0) match {
      case Left(l)  => println(l)
      case Right(r) => println(r)
    }

    /*
     * Another way to return an error is to use the Opion return type.
     * When the computation fails or cannot be done we return None, otherwhise Some(resultOfComputation)
     */
    println(division_option(3, 2))
    println(division_option(3, 0))
  }
}
