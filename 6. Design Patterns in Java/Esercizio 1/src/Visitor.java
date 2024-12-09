/**
 * Visitatore i cui metodi "visit" ritorano un generico E
 */
public interface Visitor<E> {

  /**
   * Visita un animale
   * 
   * @param a animale da visitare
   * @return risultato della visita
   */
  public E visit(Animale a);

  /**
   * Visita un pesce
   * 
   * @param p pesce da visitare
   * @return risultato della visita
   */
  public E visit(Pesce p);

}
