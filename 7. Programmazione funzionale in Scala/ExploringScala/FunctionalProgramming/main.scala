/** Functional programming is a style of programming based on the composition of
  * pure functions and the immutability of data.
  *
  * We define a function as "pure" when it is referentially transparent (see
  * "ReferentialTrasparency") and it does not modify the state of the machine
  */
object functProgr {

  // A pure function
  def sum(a: Int, b: Int): Int = a + b

  var machineState = 1
  // An impure function. Notice the side effect of modifying a global variable
  def sum_sideEffect(a: Int, b: Int): Int = {
    machineState += 1
    a + b
  }

  /** What follows is a simple problem solved using the principles of functional
    * programming. Note that Scala is an impure functional programming language
    * as it integrates feature which does not belong to functinal programming,
    * such as objects and variables
    */

  class Player(private var name: String, private var score: Int) {
    def getName() = name
    def getScore() = score
  }

  def declareAsWinner(p: Player) = "The winner is " + p.getName()
  def findMaxScore(p1: Player, p2: Player) = {
    if (p1.getScore() >= p2.getScore()) p1
    else p2
  }
  def findWinner(p1: Player, p2: Player) = {
    declareAsWinner(findMaxScore(p1, p2))
  }

  def main(args: Array[String]) = {
    val players = List(
      Player("Sam", 10),
      Player("Luke", 3),
      Player("The Swede", 30),
      Player("Albert", 15)
    )

    // Using functional programming we can compose multiple functions and use methods such as "reduceLeft"
    println(declareAsWinner(players.reduceLeft(findMaxScore)))
  }
}
