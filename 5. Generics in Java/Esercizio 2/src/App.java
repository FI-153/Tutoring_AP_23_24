class App {
  public static void main(String[] args) {

    Character[] array = { 'c', 'i', 'a', 'o' };
    StringBuffer sb1 = new StringBuffer(array);

    Character[] array2 = { 'm', 'a', 'r', 'i', 'o' };
    StringBuffer sb2 = new StringBuffer(array2);

    sb1.accoda(sb1, sb2);
    System.out.println(sb1.toString(sb1));

    Integer[] array3 = { 1, 2, 3 };
    StringBuffer sb3 = new StringBuffer(array3);
    System.out.println(sb3.toString(sb3));

    // Attenzione: l'array di sb3 contiene sia Character che Integer
    sb3.accoda(sb3, sb1);
    System.out.println(sb3.toString(sb3));
  }
}