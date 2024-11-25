package esempi_2020;

import java.util.ArrayList;
import java.util.List;

import javax.swing.JDialog;



class Pila<S>{	
	S l;
	//S ll[] = new S[6]; // NO 
	void push(S s){}
	S pop() {return null;}
}

public class GenericaConParam {
public static void main(String[] args) {
	Pila<Integer> p; // S <- Integer
	p.push("g");
	Integer i = p.pop(); // no cast
	
	massimo(new ArrayList<String>());//-> T <- String

	massimo(new ArrayList<JDialog>());//-> T <- JDialog

}

// due Number e fa la somma
static <T extends Number> double somma(T a, T b){
	return a.doubleValue() + b.doubleValue(); 
}

// massimo all'interno di una lista
static <T extends Comparable<T>> T massimo(List<T> l) {
	T max = l.get(0);
	for (T t: l) {
		if (t.compareTo(max)>0) max = t;
	}
	return max;
}


}
