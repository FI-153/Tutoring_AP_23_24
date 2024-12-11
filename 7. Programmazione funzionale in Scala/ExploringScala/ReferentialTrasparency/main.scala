/** When an expressione can be substituted with its computed value during the
  * program's lifecycle then it's referentially trasparent.
  */
object refTransparency {

  // This method is referentially transparent
  def sum(x: Int, y: Int) = x + y

  /** This method is not referentially transparent since we print the result of
    * the computation on the console
    */
  def chattySum(x: Int, y: Int): Int = {
    val sum = x + y
    println("The result is " + sum)
    sum
  }

  /** A method to tell the time is not referentially transparent since its
    * evaluation changes over time
    */
  def whatTimeIsIt(): Long = System.currentTimeMillis()

  def main(args: Array[String]) = {

    val five = sum(2, 3)
    val ten = five + five // Swapping out sum(2,3) for its evaluation
    val ten_v2 = sum(2, 3) + sum(2, 3)
    val ten_v3 = 5 + sum(2, 3)
    val ten_v4 = 10

    val six = chattySum(3, 3)
    val six_v2 = six // It doesn't print the result as we wanted

    val currentTime = whatTimeIsIt()
    Thread.sleep(10)
    println(
      currentTime == System.currentTimeMillis()
    ) // False, since some time (10ms) has passed between the evaluation of the method and this println()

  }
}
