#include <iostream>
using namespace std;

class Motore
{
private:
  int cilindrate;

public:
  // Costruttore di default per Motore (non dichiarato!)
  // Motore()
  // {
  //   cout << "Creato motore di default\n";
  // }

  Motore(int cilindrata)
  {
    this->cilindrate = cilindrata;
    cout << "Creato motore da " << cilindrata << "cc\n";
  }
};

// Implementazione a: Motore come puntatore a una cella di memoria nello stack
class Automobile_stack
{
private:
  Motore motore;

public:
  // In questo caso le initilizer list sono necessarie poiché Motore non dispone di un costruttore di default "Motore()[}"
  Automobile_stack(int cilindrata) : motore(cilindrata)
  {
    cout << "Creata macchina come puntatore vs stack\n";
  }

  /**
   * DOMANDINA
   * Quale oggetto viene creato per primo?
   * 1. Motore della cilindrata indicata
   * 2. Automobile
   */

  /* Se Motore invece disponesse del costuttore di default le initializer list non sarebbero necessarie.
   Questo avviene perché non posso lasciare che 'motore' sia Null e quindi prima di creare il Motore da 1200cc indicato nel c
   ostruttore serve che il compilatore 'metta qualcosa' in 'motore'. In questo caso specifico verrebbe creato anzitutto un Motore
   di default, poi quello da 1200cc e infine l'Automobile*/
  // Automobile_stack(int cilindrata)
  // {
  //   this->motore = Motore(cilindrata);
  //   cout << "Creata macchina come puntatore vs stack\n";
  // }

  /**
   * DOMANDINA
   * E se invece spostassi 'cout << "Creata macchina come puntatore vs stack\n"' come prima istruzione del costruttore,
   * quando verrebbe creata l'automobile?
   *
   * Non ci sarebbero cambiamenti nella creazione dell'auto, cambia solo l'output sulla tastiera.
   */
};

// Implementazione b: Motore come puntatore a una cella di memoria nell'heap
class Automobile_pointerHeap
{
private:
  Motore *motore;

public:
  /* In questo caso le initializer list non sono necessarie in nessun caso poiché abbiamo dichiarato 'motore' come un puntatore
  che quindi può assumere il valore Null. Per questo motivo quando viene creata 'Automobile_pointerHeap' non serve che
  sia 'messo' nulla dentro 'motore' */
  Automobile_pointerHeap(int cilindrata)
  {
    this->motore = new Motore(cilindrata);
    cout << "Create macchina come puntatore vs heap" << endl;
  }

  /* Le initializer list sono certamente un'opzione valida anche in questo caso. La scelta se usarle o meno ricade in parte
   sul gusto personale rispetto a una percezione di chiarezza, oppure per motivi di performance evitando di assegnare
   direttamente variabili extra.*/
  // Automobile_pointerHeap(int cilindrata) : motore(new Motore(cilindrata))
  // {
  //   cout << "Creata macchina come puntatore vs heap" << endl;
  // }
};

// Implementazione c: Motore come reference a una porzione di memoria nell'heap
class Automobile_refHeap
{
private:
  Motore &motore;

public:
  /* In quest'ultimo caso usare le inizizer list è necessarie in ogni caso per la natura delle reference, ovvero puntatori che
  non possono mai avere valore nullo */
  Automobile_refHeap(int cilindrata) : motore(*(new Motore(cilindrata)))
  {
    cout << "Create macchina come reference vs heap" << endl;
  }
};

int main(int argc, char const *argv[])
{

  cout << "STACK\n";
  Automobile_stack autoStack = Automobile_stack(1200);

  cout << "\nPUNTATORE A HEAP\n";
  Automobile_pointerHeap autoPointerHeap = Automobile_pointerHeap(1400);

  cout << "\nREFERENCE A HEAP\n";
  Automobile_refHeap autoRefHeap = Automobile_refHeap(1600);

  return 0;
}
