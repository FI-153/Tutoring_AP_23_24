object listConcat {

  def main(args: Array[String]) = {
    val a = List(1, 2, 3)
    val b = List(4, 5, 6)

    // The "::" operator returns a new list made up of the elements of the second list appended to the first list
    val la_b = a :: b
    println(la_b)

    // The ":::" operator instead returna a list of the concatenation of the elements of the second to the first
    val ab = a ::: b
    println(ab)

    // An alternative to the idiomatic expression ":::" is using "++", this is a common operator amongst all the other collections
    val ab2 = a ++ b
    println(ab2)
  }
}
