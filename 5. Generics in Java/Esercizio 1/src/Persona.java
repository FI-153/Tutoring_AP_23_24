/**
 * Una persona, comparabile con altre persone per dire se sono uguali
 */
public class Persona implements Comparable<Persona> {

  Persona() {
  }

  @Override
  public int compareTo(Persona o) {
    // Se i due oggetti sono uguali ritorna 0 altrimenti 1
    return this == o ? 0 : 1;
  }

}
