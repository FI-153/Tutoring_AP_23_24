object caseClass {

  case class Person(
      private var name: String,
      private val age: Int,
      private val socSecCode: String
  ) {}

  def main(args: Array[String]) = {
    var p = Person("A", 12, "12df")

    // A case class provides getters by default for each parameter both public and private
    println(p._1 + " " + p._2 + " " + p._3)

    // Moreover it provides equals() and hashCode() by default
    println(p.equals(3))
    println(p.equals(Person("A", 12, "12d")))
    println(p.equals(Person("A", 12, "12df")))

    println(p.hashCode())
    println(Person("A", 12, "12d").hashCode())
  }
}
