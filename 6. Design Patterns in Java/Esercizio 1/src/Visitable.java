/**
 * Interfaccia Visitable che accetta visitatori i cui metodi visit restituiscono
 * un generico E
 */
public interface Visitable {
  public <E> E accept(Visitor<E> v);
}
