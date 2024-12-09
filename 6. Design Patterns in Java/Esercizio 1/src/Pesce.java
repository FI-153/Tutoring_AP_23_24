/**
 * Sottoclasse di Animale. Come tale è visitabile da un visitatore il cui metodo
 * visit resttituisce un generico E
 */
public class Pesce extends Animale {

  /*
   * Necessario eseguire override del metodo!
   * 
   * Altrimenti in fase di esecuzione il compilatore eseguirebbe sempre il metodo
   * "accept" di Animale (superclasse) e mai di Pesce. Avendo stabilito che un
   * Animale non può nuotare ritornerebbe sempre false.
   */
  @Override
  public <E> E accept(Visitor<E> v) {
    return v.visit(this);
  }

}
