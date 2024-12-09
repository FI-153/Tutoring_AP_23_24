/**
 * Visitatore che permette di stabilire se un animale visitato sia in grado di
 * nuotare o meno restituendo un booleano appropriato.
 */
public class DeterminaNuotaVisitor implements Visitor<Boolean> {

  /**
   * Visita un animale generico, il quale assumiamo non possa nuotare *
   * 
   * @param a animale che viene visitato
   * @return false
   */
  @Override
  public Boolean visit(Animale a) {
    return false;
  }

  /**
   * Visita un pesce, il quale può nuovare
   * 
   * @param p pesce che viene visitato
   * @return true
   */
  @Override
  public Boolean visit(Pesce p) {
    return true;
  }

}
