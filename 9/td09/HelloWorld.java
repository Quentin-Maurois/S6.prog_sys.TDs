/**
 * Created by lavirott on 13/05/2017, modified 27/04/2023.
 */
import java.util.Scanner;

public class HelloWorld {
    // Méthodes natives fournies grâce à une bibliothèque
    public static native void printCpp();
    public static native void printStringToCpp(String str);
    public static native String stringFromCpp();
    public native void callJavaMethod();
    public native String toString();
    public native int fib(int n);

    static {
        System.out.print("Loading Hello World native library...");
        System.loadLibrary("HelloWorld");
        System.out.println(" done.");
    }

    public static void test() {
        // fonction test créée pour l'exercice 4
        System.out.print("Hello ");
        printCpp();
    }

    private int entier = 0;

    public static void main(String args[]) {
        // Print from Java and from C/C++
        // System.out.print("Hello ");
        // HelloWorld.printCpp();

        HelloWorld.printStringToCpp("Je suis une chaine de caractères qui a été transférée depuis java vers c\n");
        System.out.println(HelloWorld.stringFromCpp());

        HelloWorld helloWorld = new HelloWorld();
        helloWorld.callJavaMethod();
        System.out.println(helloWorld.toString());
        System.out.println("fibonacci de 6 = " + helloWorld.fib(6));
        
        Scanner sc = new Scanner(System.in);
        System.out.println("Veuillez appuyer sur Entrée pour terminer le programme...");
        sc.nextLine();
        sc.close();
    }
}
