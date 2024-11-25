package esempi_2020;
// generica con gli Object
class Pila{	
	void push(Object o){}	
	Object pop() {return null;}
}
// soluzione con generici coi "sottotipi"
class PiladiStringhe extends Pila{
	@Override
	void push(Object o){push((String)o);}	
	void push(String o){super.push(o);} // overload
	@Override // override con sottotipazione del tipo ritornato
	String pop() {return null;}
	
}

public class GenericsconObject {

	static void printAll(Object[] l) {}
		
	public static void main(String[] args) {
		String[] nomi = {"a","b","c"};
		printAll(nomi);
		
		Pila pilaStringhe = new Pila();
		pilaStringhe.push("ooo");
		String x = (String)pilaStringhe.pop(); //1. conversioni
		pilaStringhe.push(new Integer(1)); // 2. nessun controllo
		
		PiladiStringhe ps2 = new PiladiStringhe();
		ps2.push("kkk");
		ps2.push(new Integer(6)); // -> errore in esecuzione
		String l = ps2.pop();
	}
	
}
