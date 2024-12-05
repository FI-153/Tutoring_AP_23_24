#include <iostream>
#include <string>
using namespace std;

/**
 * Osservazione:
 * Non essendo specificato dalla traccia, questa implementazione richiede come costruttore il nome delle nazioni
 * coinvolte nella partita. Sarebbe andata bene anche se si fossero passare direttamente oggetti di tipo 'Nazionale'
 * al costruttore di 'Partita'.
 *
 * L'importante è dimostrare di saper gestire puntatori e reference su stack e heap!
 */

class Nazionale
{
private:
  string nomePaese;

public:
  // Costruttore di default (non implementato!)
  // Nazionale()
  // {
  //   cout << "Creata nazionale di default";
  // }

  // Costruttore customizzato che prende il nome del paese come input
  Nazionale(string nomePaese)
  {
    this->nomePaese = nomePaese;
    cout << "Creata nazionale del paese: " << nomePaese << endl;
  }
};

class Partita_stack
{
private:
  Nazionale n1;
  Nazionale n2;

public:
  /**
   * Usiamo le initializion list poiché non disponiamo di un costruttore di default per 'Nazionale'.
   * Altrimenti non sarebbero state necessarie.
   */
  Partita_stack(string nomeNaz1, string nomeNaz2) : n1(nomeNaz1), n2(nomeNaz2)
  {
    cout << "Creata partita tra " << nomeNaz1 << " e " << nomeNaz2 << endl;
  }
};

class Partita_pointerHeap
{
private:
  Nazionale *n1;
  Nazionale *n2;

public:
  /**
   * Usiamo initilizer list purché non siano necessarie trattandosi di un puntatore dell'heap (che come tale può essere Null).
   */
  Partita_pointerHeap(string nomeNaz1, string nomeNaz2) : n1(new Nazionale(nomeNaz1)), n2(new Nazionale(nomeNaz2))
  {
    cout << "Creata partita tra " << nomeNaz1 << " e " << nomeNaz2 << endl;
  }
};

class Partita_refHeap
{
private:
  Nazionale &n1;
  Nazionale &n2;

public:
  /**
   * Dobbiamo per forza usare le initilization list poiché le nazionali sono indicate come reference a un'area dell'heap.
   * Per loro natura le reference sono puntatori che non possono mai essere nulli, ecco perché siamo obbligati a instanziarle
   * prima ancora dell'oggetto 'Partita_refHeap'.
   */
  Partita_refHeap(string nomeNaz1, string nomeNaz2) : n1(*(new Nazionale(nomeNaz1))), n2(*(new Nazionale(nomeNaz2)))
  {
    cout << "Creata partita tra " << nomeNaz1 << " e " << nomeNaz2 << endl;
  }
};

int main(int argc, char const *argv[])
{

  Partita_stack pStack("Canada", "Italia");
  cout << endl;

  Partita_pointerHeap pPointerHeap("Messico", "Argentina");
  cout << endl;

  Partita_stack Partita_refHeap("Islanda", "Papaua Nuova Guinea");

  return 0;
}
