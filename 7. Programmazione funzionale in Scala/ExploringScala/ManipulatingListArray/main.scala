object listManipulation {

  def invertList(l: List[Any], i: Int, lOut: List[Any]): List[Any] = {
    if (i < 0) lOut
    else invertList(l, i - 1, lOut :+ l.apply(i))
  }

  def main(args: Array[String]) = {

    var array = Array(1, 2, 3)
    var list = List(1, 2, 3)

    // We can access a specific value at a specific index using apply()
    println(array.apply(0))
    println(list.apply(0))

    // We can return a version of the collection that has been modified by appending an element in head or tail
    (array :+ 4).foreach(print)
    println()
    (0 +: array).foreach(print)
    println()
    println(list :+ 4)
    println(0 +: list)

    // The previous code does not modify the collections. These one do
    array :+= 4
    array +:= 0
    array.foreach(print)

    println()
    list :+= 4
    list +:= 0
    println(list)

    // Here they are applied to a function
    println(invertList(list, list.size - 1, List()))

  }
}
