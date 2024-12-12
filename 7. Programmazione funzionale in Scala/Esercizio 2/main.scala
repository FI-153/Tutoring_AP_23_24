object Esercizio2 {
  def main(args: Array[String]): Unit = {

    // Punto a)
    // Osservazione: intendiamo la posizione del carattere nella stringa, non l'indice nell'array di caratteri
    def f(s: String): String = {
      if s.isEmpty() || s.size < 9 then ""
      else s"${s.charAt(2)}${s.charAt(5)}${s.charAt(8)}"
    }
    println(f("Stringa di prova"))
    println(f("")) // Stringa nulla -> ""
    println(f("Ciao")) // Stringa con meno di 9 caratteri -> ""

    // Punto b)
    def g(s: String): String = s.concat(s)
    println(g("ciao"))

    // Punto c)
    def h(l: String => String, m: String => String): String => String = {
      (x: String) => m(l(x))
    }

    // Punto d)
    val k = h(f, g)
    println(k("oloboslorat"))

    // Punto e)
    val listString = List("oloboslorat", "olocosiorat", "olomosaor!t")
    val listStringMappedToK = listString.map(el => k(el))
    println(listStringMappedToK)

    // Punto f)
    val concatList = listStringMappedToK.reduce(_ + _)
    println(concatList)
  }
}
