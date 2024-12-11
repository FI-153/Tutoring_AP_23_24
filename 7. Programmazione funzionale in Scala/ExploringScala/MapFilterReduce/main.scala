import scala.math
object mapFilterReduce {

  def main(args: Array[String]) = {

    val l = List(-2, -1, 0, 1, 2, 3, 4)

    // Apply the same function to all the members of the list
    println(l.map(x => x + 1))

    // Similarly to map() we can take a function an use all the elements of the collection, one by one, as input
    l.foreach(print(_)); println()

    // Returns only those elements which satisfies the predicate
    println(l.filter(_ < 0))

    // Similarly we can assess if a predicate holds for all elements, he we check if they are all even
    println(l.forall(_ % 2 == 0))

    // Apply a function to reduce the list to a single number, here it is the sum of the elements
    println(l.reduce((a, b) => a + b))
    // Here it is the maximum
    println(l.reduce(((a, b) => a max b)))

    // Simlarly we can use reduceLeft(), staring from the leftest most element, or reduceRight()
    // Normally, reduce() operates in parallel
    println(l.reduceLeft((a, b) => a + b))
    println(l.reduceRight((a, b) => a + b))

    // Is there at least a number satisfyng the predicate?
    println(l.exists(x => x % 2 == 0))

    // Enumerate the elements in the list untill a certain predicate is met
    println(l.takeWhile(x => x <= 0))

    // Partition the list in two groups adhering to the predicate and not
    println(l.partition(x => x < 0))

    /* These higher order functions can be combined together.
     * Here we compute the sum of squared values
     */
    println(l.map(x => Math.pow(x, 2)).reduce((a, b) => a + b))

    /*
     * And here only the sum of squared values that are positive in the list
     */
    println(l.filter(_ > 0).map(x => Math.pow(x, 2)).reduce((a, b) => a + b))

    /*
     * Now we make all the elements even before repeating example 3
     */
    println(l.filter(_ % 2 == 0).forall(_ % 2 == 0))

  }
}
