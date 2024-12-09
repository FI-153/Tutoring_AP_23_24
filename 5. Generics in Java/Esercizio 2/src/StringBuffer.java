import java.util.Arrays;

public class StringBuffer {

  /**
   * Sottostante allo StringBuffer abbiamo un array. Non è più necessario tener
   * traccia della lunghezza di ciò che viene memorizzato potendo disporre del
   * campo "length" dell'oggeto object[], per adererenza alla traccia lo facciamo
   * lo stesso.
   * 
   * NB: Gli array in Java sono oggetti!
   */
  private Object[] array;
  private int len;

  /**
   * Costruisce uno StringBuffer contenente un array di Object
   * 
   * @param array array da inserire nello StringBuffer
   */
  public StringBuffer(Object[] array) {
    this.array = array;
    this.len = array.length;
  }

  /**
   * Accoda il contenuto del secondo StringBuffer al primo
   * 
   * @param b1 StringBuffer a cui accodare il valore
   * @param b2 StringBuffer il cui valore deve essere accodato
   */
  public void accoda(StringBuffer b1, StringBuffer b2) {

    Object[] newArray = new Object[b1.len + b2.len];

    for (int i = 0; i < b1.len; i++)
      newArray[i] = b1.array[i];

    for (int i = 0; i < b2.len; i++)
      newArray[b1.len + i] = b2.array[i];

    b1.array = newArray;
    b1.len = newArray.length;
  }

  /**
   * Ritorna la stringa rappresentante il contenuto dell'array con preposto e
   * apposto il carattere '"'.
   * 
   * Attenzione: non si tratta dell'override di "toString()" in quanto i due
   * metodi hanno una segnatura diversa. Si tratta di overloading.
   * 
   * @param b StringBuffer da considerare
   * @return Stringa rappresentante l'arary dello StringBuffer b
   */
  String toString(StringBuffer b) {
    return '"' + Arrays.stream(b.array).map(o -> o.toString()).reduce("", (str1, str2) -> str1 + str2) + '"';
  }

  /*
   * In Java non esistono distruttori, di conseguenza non è possibile cancellare
   * un oggetto. Si è deciso di "cancelalrlo" rimuovendo la reference dell'array
   * per almeno occultare il contenuto dello StringBuffer.
   * 
   * Quando un oggetto non viene più puntato da nessuna parte del codice penserà
   * poi il garbage collector ad eliminarlo. Tuttavia chiamarlo esplicitamente è
   * cattiva prassi.
   */
  void cancella(StringBuffer b) {
    array = null;
  }

}
