import java.util.ArrayList;
import java.util.List;

public class App {
    public static void main(String[] args) throws Exception {
        Animale animale = new Animale();
        Pesce pesce = new Pesce();

        DeterminaNuotaVisitor determinaNuotaVisitor = new DeterminaNuotaVisitor();
        System.out.println("L'animale può nuotare? " + animale.accept(determinaNuotaVisitor));
        System.out.println("Il pesce può nuotare? " + pesce.accept(determinaNuotaVisitor));

        // Contare il numero di animali che possono nuotare
        List<Animale> lAnimali = new ArrayList<>();
        lAnimali.add(new Animale());
        lAnimali.add(new Animale());
        lAnimali.add(new Animale());
        lAnimali.add(new Animale());
        lAnimali.add(new Animale());
        lAnimali.add(new Pesce());
        lAnimali.add(new Pesce());
        lAnimali.add(new Pesce());
        System.out.println("La lista contiene " + App.contaPesci(lAnimali) + " animali che possono nuotare");
    }

    /**
     * Funzione statica per contare quanti animali possono nuotare (aka. quanti
     * pesci sono contenuti nella lista).
     * 
     * @param animali Lista di animali
     * @return Numero di pesci nella lista
     */
    public static int contaPesci(List<Animale> animali) {
        return (int) animali
                .stream()
                .filter(a -> a.accept(new DeterminaNuotaVisitor()))
                .count();
    }
}
