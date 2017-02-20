public class Example {
    public static void main(String[] args) {
        try (IO.Scanner in  = IO.newScanner();
             IO.Printer out = IO.newPrinter()) {
            out.println(Math.sqrt(in.nextInt()));
        }
    }
}
