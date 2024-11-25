package esempi_2020;

import java.util.ArrayList;
import java.util.List;

class Auto implements Comparable<Auto>{
	String targa;
	@Override
	public int compareTo(Auto o) {
		return targa.compareTo(o.targa);
	}
}

class SUV extends Auto{}


public class Usowildcards {
	
	static <T extends Comparable <? super T>>void sort(List<T> y){
		T t = y.get(0);
		//...
	}

	public static void main(String[] args) {
		List<String> nomi = new ArrayList<String>();
		printall(nomi);
		SUV a1,a2;
		System.out.println(a1.compareTo(a2));
		List<SUV> mysuvs = new ArrayList<SUV>();
		sort(mysuvs);		
	}

	
	static void printall(List<?> lo) {
		lo.forEach(x -> System.out.println(x));		
	}
	
	

}
