#include <iostream>
using namespace std;

/**
 * setA che accetta un puntatore raw.
 *
 * Se la traccia dell'esercizio non chiedesse di creare 3 funzioni overloaded per gestire le 3 tipologie di
 * passaggio con i puntatori sarebbe sufficiente disporre solo di questa in quanto potremmo passarle il
 * puntatore raw wrappato nel puntatore smart (istruzione .get()). Questo metodo è generalmente poco safe.
 */
void setA(char *S)
{
  if (S == nullptr)
    return;

  S[0] = 'A';
}

/**
 * setA che accetta uno Shared Pointer.
 */
void setA(shared_ptr<char> S)
{
  if (S.get() == nullptr)
    return;

  // Tramite .get() possiamo accedere al puntatore wrappato dallo smart pointer
  S.get()[0] = 'A';
}

/**
 * setA che accetta uno Unique Pointer.
 *
 * DOMANDINE:
 *  - Come mai dobbiamo passare lo unique pointer by-reference?
 *      Perché passarlo by-value implicherebbe la necessità di doverne creare una copia, ma ciò
 *      non è possibile per gli unique pointers in quanto possono avere un solo owner alla volta.
 *      Per forzare questo comportamento viene offuscato il copy constructor dello shared pointer.
 *
 *  - Come mai non è necessario farlo per lo shared pointer?
 *      Perché, al contrario dello unique pointer, possiamo farne una copia. Provando a valutare il
 *      numero do owner prima della chiamata, all'interno del metodo e dopo la chiamata avremmo
 *      rispettivamente 1, 2 e poi ancora 1 owner.
 */
void setA(unique_ptr<char> &U)
{
  if (U.get() == nullptr)
    return;

  U.get()[0] = 'A';
}

void copyStringToArray(char *dst, string src)
{
  for (int i = 0; i < src.length(); i++)
    dst[i] = src[i];
}

int main(int argc, char const *argv[])
{

  string originalString = "Hello";
  int len = originalString.length();

  // In Cpp possiamo ancora usare malloc, ma non free()
  //  char *word = (char *)malloc(sizeof(char) * len);
  char *word = new char[len];
  copyStringToArray(word, originalString);
  setA(word);
  cout << "Raw pointer:\t" << word << endl;

  char *sWord = new char[len];
  copyStringToArray(sWord, originalString);
  shared_ptr<char> sWord_ptr(sWord);
  setA(sWord_ptr);
  cout << "Shared pointer:\t" << sWord << endl;

  char *uWord = new char[len];
  copyStringToArray(uWord, originalString);
  unique_ptr<char> uWord_ptr(uWord);
  setA(uWord_ptr);
  cout << "Unique pointer:\t" << uWord << endl;

  return 0;
}