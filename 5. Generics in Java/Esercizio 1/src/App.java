public class App {
    public static void main(String[] args) throws Exception {
        Dizionario<Integer, Character> d = new Dizionario<>();

        d.insertTuple(1, 'a');
        d.insertTuple(4, 'd');
        d.insertTuple(3, 'c');
        d.insertTuple(8, 'h');

        System.out.println("Alla chiave 4 corrisponde '" + d.search(4) + "'");
        System.out.println("Alla chiave 1 corrisponde '" + d.search(1) + "'");
        System.out.println("Alla chiave 10 corrisponde '" + d.search(10) + "'");

        /**
         * Prova del dizionario con Studente
         * 
         * Con l'implementazine che propongo non è possibile creare un dizionario di
         * Studente nonstante sia Comparable. Questo poiché richiedo che T sia
         * comparable con sé stesso mentre Studente è comparable con Persona.
         * 
         * Se avessi invece implementato il dizionario come richiedente un T comparable
         * in generale (T extends Comparable) allora avrei potuto creare il dizionario
         * di Studenti.
         * 
         * Con la corrente implementazione è possibile unicamente creare un dizionario
         * di Persona. Detto ciò, essendo "Studente <: Persona" possiamo comunque
         * inserire uno Studente in un dizionario di Persona
         */
        Dizionario<Persona, Integer> registroVoti = new Dizionario<>();
        Studente fabio = new Studente();
        Persona luca = new Persona();
        registroVoti.insertTuple(fabio, 28);
        registroVoti.insertTuple(luca, 25);
        System.out.println("Luca ha preso " + registroVoti.search(luca));

    }
}