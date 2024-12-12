object Esercizio1 {
  def main(args: Array[String]): Unit = {

    val a = 3
    val b = 4

    // Punto a)
    def mult6(a: Int): Int = a * 6
    println(s"$a * 6 = ${mult6(a)}")

    def mult(a: Int, b: Int) = a * b
    println(s"$a * $b = ${mult(a, b)}")
    def multC(a: Int): Int => Int = b => a * b

    // Punto b)
    /** @param f
      *   funzione che accetta 1 intero e restituisce 1 intero
      * @param g
      *   funzione che accetta 2 interi e resituisce 1 intero
      * @return
      *   g(f(x),f(y)) dove x e y sono interi
      */
    def magic(f: Int => Int, g: (Int, Int) => Int): (Int, Int) => Int = {
      (x: Int, y: Int) => g(f(x), f(y))
    }
    val multBy6ThenTogether = magic(mult6, mult);
    val res = multBy6ThenTogether(a, b)
    println(s"($a * 6) * ($b * 6) = $res")

    // Anzichè assegnare magic a una val si poteva anche assegnare direttamente a e b. Cambia solo che non possiamo ri-utilizzare magic con mult6 e mult per altri input
    // val res = magic(mult6, mult)(a, b);

    // Punto c)
    val interi: List[Int] = List(1, 2, 3)
    println(s"Lista originale: $interi")
    val interiDoubled = interi.map(x => x * 2)
    // Oppure in versione più compatta
    // val interiDoubled = interi.map(_ * 2)
    println(s"Lista $interi con elementi raddoppiati è $interiDoubled")

    // Punto d)
    val interiSummed = interi.reduce(_ + _)
    // Oppure in versione estesa
    // val interiSummed = interi.reduce((a, b) => a + b)
    println(s"La somma di $interi è $interiSummed")

  }
}
