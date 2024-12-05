#include <iostream>
using namespace std;

class Persona
{
private:
  string nome;

public:
  Persona(string nome)
  {
    this->nome = nome;
    cout << "Creata persona di nome: " << nome << endl;
  }

  string getNome() { return this->nome; }

  // (NON RICHIESTO DALLA TRACCIA) Imposta il nome della persona al contrario
  void setNomeReversed(int len)
  {
    string copiaNome = getNome();

    for (int i = len - 1, j = 0; i >= 0; i--, j++)
      this->nome[j] = copiaNome[i];
  }

  // Distruttore di Persona
  ~Persona()
  {
    cout << "Distrutta persona di nome: " << this->getNome() << endl;
  }
};

class Studente : public Persona
{
private:
  string matricola;

public:
  Studente(string nome, string matricola) : Persona(nome)
  {
    this->matricola = matricola;
    cout << "Creato studente di nome " << nome << " e matricola " << matricola << endl;
  }

  string getMatricola() { return this->matricola; }

  // Distruttore di Studente
  ~Studente()
  {
    cout << "Distrutto studente di matricola: " << matricola << endl;
  }
};

int main(int argc, char const *argv[])
{

  /*
   * Usando un raw pointer dobbiamo gestire manualmente l'allocazioe e deallocazione della memoria, in questo caso con
   * l'operatore "new" per allocare e "delete" per deallocare.
   * Omettere "delete" non causa errore, tuttavia la memoria non viene liberata una volta usciti dal
   * blocco di codice ottenendo un memory leak.
   */
  {
    Studente *rawPointerStudente = new Studente("Federico", "12ab");
    delete rawPointerStudente;

    // Uscire dal blocco NON causa la de-allocazione di rawPointerStudente, dobbiamo per forza liberarlo noi
  }

  cout << endl;

  /*
   * Usando invece uno smart pointer la gestione della memoria avviene in modo automatico. Lo spazio viene automaticamente
   * allocato entrando nel blocco e deallocato uscendone.
   *
   * In questo primo caso usiamo uno unique pointer, la cui ownership NON può essere condivisa da più oggetti allo stesso momento
   */
  {
    unique_ptr<Studente> uniquePointerStudente(new Studente("Luca", "45bg"));

    // Uscire dal blocco CAUSA la de-allocazione di uniquePointerStudente
  }

  cout << endl;

  /*
   * Usando invece uno shared pointer l'effetto sulla memoria è lo stesso ma la ownership può essere condivisa da più oggetti
   */
  {
    shared_ptr<Studente> sharedPointerStudente(new Studente("Marco", "56fd"));

    // Notate dall'output sulla console come non stiamo creando né un nuovo studente né una nuova persona
    shared_ptr<Studente> copiaDiMarco(sharedPointerStudente);
    cout << "Al momento ci sono " << copiaDiMarco.use_count() << " copie dello studente Marco \n";

    // METODI AGGIUNTIVI NON RICHIESTI DALLA TRACCIA
    /**
     * Modificando il nome della copia vediamo che viene modificato anche il nome dell'originale. Notare inoltre come tramite
     * '->' abbiamo usato uno dei metodi dell'oggetto salvato sull'heap puntato dal raw pointer
     */

    copiaDiMarco->setNomeReversed(5);
    cout << "Nuovo nome della copia di Marco: " << copiaDiMarco->getNome() << endl;
    cout << "Nuovo nome del Marco originale: " << sharedPointerStudente->getNome() << endl;

    // Usando .reset() possiamo rinuniciare alla ownership del puntatore prima che venga deallocato
    copiaDiMarco.reset();

    // Essendoci ancora un owner la memoria dedicata al puntatore non viene de-allocata
    cout << "Al momento ci sono " << sharedPointerStudente.use_count() << " copie dello studente Marco \n";

    // Uscire dal blocco CAUSA la de-allocazione di sharedPointerStudente poiché usciamo dallo scope di tutti i possessori
  }

  return 0;
}