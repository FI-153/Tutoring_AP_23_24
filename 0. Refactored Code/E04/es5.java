package esempi_2020;

import java.util.ArrayList;
import java.util.List;

class A3{	int a = 0; @Override
	public String toString() {
		return "A";
	}}

class B3 extends A3{
	public boolean equals(B3 a) { return a.a==this.a;}
	public String toString() {
		return "B";
	}
}
class C3 extends A3{
	@Override
	public boolean equals(Object a) {
		return ((A3)a).a==this.a;
	}
	public String toString() {
		return "C";
	}
}


public class EsercizioGenerici {

	public static void main(String[] args) {
		List<A3> lista = new ArrayList<>();
		lista.add(new B3());
		lista.add(new C3());
		for(A3 a: lista) System.out.println(a);
		A3 a = new A3();
		for(A3 i: lista) {
			System.out.println(i.equals(a));
		}
		
		
	}
	
}
