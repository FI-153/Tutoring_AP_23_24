import java.util.ArrayList;

/**
 * Pedanteria semantica: 
 * 
 * le convenzioni sull'uso dei Type parameters vorrebbero 
 * che in questo caso si usassero <K,V> indicanti "Key" e "Value" ma la traccia 
 * vuole <T,S> quindi ce lo facciamo andare bene
 */

/**
 * Struttura dati di tipo key-value che salva un oggetto di tipo S identificato
 * da una chiave di tipo T che sia comparable
 */
public class Dizionario<T extends Comparable<T>, S> {

  /**
   * ArrayList contenente le chiavi
   */
  private ArrayList<T> keys = new ArrayList<>();

  /**
   * ArrayList contenente i valori
   */
  private ArrayList<S> values = new ArrayList<>();

  /**
   * Ultimo indice occupato del dizionario
   */
  int lastIndex;

  /**
   * Creiamo un Dizionario
   */
  public Dizionario() {
    lastIndex = 0;
  }

  /**
   * Inserisce una tupla <Chiave, Valore> nel dizionario
   * 
   * @param key   Chiave della tupla
   * @param value Valore da salvare alla relativa chiave
   */
  public void insertTuple(T key, S value) {

    /*
     * Aggiungiamo i valori nelle relative ArrayList allo stesso indice, come da
     * richiesta
     */
    keys.add(lastIndex, key);
    values.add(lastIndex, value);

    lastIndex++;
  }

  /**
   * Cerca il valore corrispondente alla chiave fornita
   * 
   * @param key Chiave del valore da cercare
   * @return Il valore associato alla chiave oppure null
   */
  public S search(T key) {

    // Usiamo index per capire se la chiave sia stata trovata o meno
    int index = -1;

    for (int i = 0; i < keys.size(); i++)
      if (keys.get(i).equals(key))
        index = i;

    /**
     * Se esiste una chiave estraiamo il relativo valore da values.
     * Un metodo più elegante per gestire questo sccenario sarebbe lanciare
     * un'eccezione e gestirla poi alla chiamata.
     */
    return index >= 0 ? values.get(index) : null;
  }

}
