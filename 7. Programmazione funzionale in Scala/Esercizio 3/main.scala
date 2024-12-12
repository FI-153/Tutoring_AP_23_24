object Esercizio3 {
  def main(args: Array[String]): Unit = {

    // Punto a)
    def raddoppia(a: Int): Int = a * 2

    // Punto b)
    // Implementazione imperativa
    def somma(f: Int => Int): (Int, Int) => Int = { (a: Int, b: Int) =>
      {
        val range = b - a
        var res = 0
        for (i <- a + 1 to a + range - 1) {
          res += f(i)
        }

        res
      }
    }
    println(somma(raddoppia)(2, 6))

    // Implementazione funzionale
    def sommaFunzionale(f: Int => Int): (Int, Int) => Int = {
      (a: Int, b: Int) =>
        List
          .range(a + 1, b)
          .map(f)
          .reduce(_ + _)
    }
    println(sommaFunzionale(raddoppia)(2, 6))

    // Punto c)
    val raddoppiaESomma = somma(raddoppia)

    // Punto d)
    println(raddoppiaESomma(4, 6))

    // Punto e)
    val listInteri = List(1, 2, 3, 4)
    val listInteriDoubled = listInteri.map(raddoppia)
    println(s"$listInteri -> $listInteriDoubled")

    // Punto f)
    println(listInteriDoubled.reduce(_ + _))
  }
}
