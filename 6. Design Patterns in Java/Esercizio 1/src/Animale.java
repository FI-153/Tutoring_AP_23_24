/**
 * Classe visitabile da un visitatore il cui metodo visit resttituisce un
 * generico E
 */
public class Animale implements Visitable {

  @Override
  public <E> E accept(Visitor<E> v) {
    return v.visit(this);
  }

}