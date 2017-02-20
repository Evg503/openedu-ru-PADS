import java.io.*;
import java.util.*;

/**
 * This is the wrapper library which is hopefully useful for the PADS course participants.
 */
public final class IO {
    /**
     * This exception is thrown whenever a checked exception is thrown
     * inside this wrapper library.
     */
    public static final class WrappedIOException extends RuntimeException {
        public WrappedIOException(Throwable cause) {
            super(cause);
        }
    }

    /**
     * Returns a new {@link IO.Scanner} which reads from "input.txt".
     * @return the scanner.
     */
    public static Scanner newScanner() {
        return new Scanner("input.txt");
    }

    /**
     * Returns a new {@link IO.Printer} which writes to "output.txt".
     * @return the printer.
     */
    public static Printer newPrinter() {
        try {
            return new Printer("output.txt");
        } catch (IOException ex) {
            throw new WrappedIOException(ex);
        }
    }

    /**
     * Scanner is a simple but rather fast wrapper
     * around {@link BufferedReader} and {@link StringTokenizer}
     * which reads whitespace-free tokens, ints, longs and doubles.
     *
     * This should be enough to solve problems in the PADS course.
     */
    public static final class Scanner implements Closeable {
        private final BufferedReader reader;
        private StringTokenizer tokenizer;

        /**
         * Creates a new Scanner which reads from the specified file.
         * @param filename the name of the file to be read.
         */
        public Scanner(String filename) {
            try {
                reader = new BufferedReader(new FileReader(filename));
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException ex) {
                throw new WrappedIOException(ex);
            }
        }

        /**
         * Closes the scanner.
         */
        public void close() {
            try {
                reader.close();
                tokenizer = null;
            } catch (IOException ex) {
                throw new WrappedIOException(ex);
            }
        }

        /**
         * Returns the next whitespace-free token.
         * If there is no such token, throws a {@link WrappedIOException}.
         * @return the token.
         * @throws WrappedIOException if there is no token, or IO error occurs.
         */
        public String next() {
            try {
                while (!tokenizer.hasMoreTokens()) {
                    tokenizer = new StringTokenizer(reader.readLine());
                }
                return tokenizer.nextToken();
            } catch (IOException | NullPointerException ex) {
                throw new WrappedIOException(ex);
            }
        }

        /**
         * Returns the next int.
         * If there is no token, throws a {@link WrappedIOException}.
         * If there is a token, but it is not an int, throws {@link NumberFormatException}.
         * @return the int.
         * @throws WrappedIOException if there is no token, or IO error occurs.
         * @throws NumberFormatException if there is a token, but it is not an int.
         */
        public int nextInt() {
            return Integer.parseInt(next());
        }

        /**
         * Returns the next long.
         * If there is no token, throws a {@link WrappedIOException}.
         * If there is a token, but it is not a long, throws {@link NumberFormatException}.
         * @return the long.
         * @throws WrappedIOException if there is no token, or IO error occurs.
         * @throws NumberFormatException if there is a token, but it is not a long.
         */
        public long nextLong() {
            return Long.parseLong(next());
        }

        /**
         * Returns the next double.
         * If there is no token, throws a {@link WrappedIOException}.
         * If there is a token, but it is not a double, throws {@link NumberFormatException}.
         * @return the double.
         * @throws WrappedIOException if there is no token, or IO error occurs.
         * @throws NumberFormatException if there is a token, but it is not a double.
         */
        public double nextDouble() {
            return Double.parseDouble(next());
        }
    }

    /**
     * Scanner is a convenience subclass of {@link PrintWriter}.
     * It provides additional functionality to print several whitespace-separated entities.
     */
    public static final class Printer extends PrintWriter {
        /**
         * Creates a new Printer which writes to the specified file.
         * @param filename the name of the file to be written to.
         */
        public Printer(String filename) throws IOException {
            super(filename);
        }

        /**
         * Prints two ints, separated by a whitespace and finished with a newline.
         * @param v1 the first int.
         * @param v2 the second int.
         */
        public void println(int v1, int v2) {
            print(v1);
            print(' ');
            println(v2);
        }

        /**
         * Prints three ints, separated by a whitespace and finished with a newline.
         * @param v1 the first int.
         * @param v2 the second int.
         * @param v3 the third int.
         */
        public void println(int v1, int v2, int v3) {
            print(v1);
            print(' ');
            println(v2, v3);
        }

        /**
         * Prints all given ints, separated by a whitespace and finished with a newline.
         * @param ints the ints to be printed.
         */
        public void println(int... ints) {
            for (int i = 0, iMax = ints.length; i < iMax; ++i) {
                if (i > 0) {
                    print(' ');
                }
                print(ints[i]);
            }
            println();
        }

        /**
         * Prints two longs, separated by a whitespace and finished with a newline.
         * @param v1 the first long.
         * @param v2 the second long.
         */
        public void println(long v1, long v2) {
            print(v1);
            print(' ');
            println(v2);
        }

        /**
         * Prints three longs, separated by a whitespace and finished with a newline.
         * @param v1 the first long.
         * @param v2 the second long.
         * @param v3 the third long.
         */
        public void println(long v1, long v2, long v3) {
            print(v1);
            print(' ');
            println(v2, v3);
        }

        /**
         * Prints all given longs, separated by a whitespace and finished with a newline.
         * @param longs the longs to be printed.
         */
        public void println(long... longs) {
            for (int i = 0, iMax = longs.length; i < iMax; ++i) {
                if (i > 0) {
                    print(' ');
                }
                print(longs[i]);
            }
            println();
        }

        /**
         * Prints two doubles, separated by a whitespace and finished with a newline.
         * @param v1 the first double.
         * @param v2 the second double.
         */
        public void println(double v1, double v2) {
            print(v1);
            print(' ');
            println(v2);
        }

        /**
         * Prints three doubles, separated by a whitespace and finished with a newline.
         * @param v1 the first double.
         * @param v2 the second double.
         * @param v3 the third double.
         */
        public void println(double v1, double v2, double v3) {
            print(v1);
            print(' ');
            println(v2, v3);
        }

        /**
         * Prints all given doubles, separated by a whitespace and finished with a newline.
         * @param doubles the doubles to be printed.
         */
        public void println(double... doubles) {
            for (int i = 0, iMax = doubles.length; i < iMax; ++i) {
                if (i > 0) {
                    print(' ');
                }
                print(doubles[i]);
            }
            println();
        }

        /**
         * Prints two objects, separated by a whitespace and finished with a newline.
         * @param v1 the first object.
         * @param v2 the second object.
         */
        public void println(Object v1, Object v2) {
            print(v1);
            print(' ');
            println(v2);
        }

        /**
         * Prints three objects, separated by a whitespace and finished with a newline.
         * @param v1 the first object.
         * @param v2 the second object.
         * @param v3 the third object.
         */
        public void println(Object v1, Object v2, Object v3) {
            print(v1);
            print(' ');
            println(v2, v3);
        }

        /**
         * Prints all given objects, separated by a whitespace and finished with a newline.
         * @param doubles the objects to be printed.
         */
        public void println(Object... objects) {
            for (int i = 0, iMax = objects.length; i < iMax; ++i) {
                if (i > 0) {
                    print(' ');
                }
                print(objects[i]);
            }
            println();
        }

        /**
         * Prints the elements of the given collection, separated by a whitespace and finished with a newline.
         * @param collection the collection to be printed.
         */
        public void printlnCollection(Collection<?> collection) {
            Iterator<?> iterator = collection.iterator();
            boolean printedSomething = false;
            while (iterator.hasNext()) {
                if (printedSomething) {
                    print(' ');
                }
                print(iterator.next());
                printedSomething = true;
            }
            println();
        }
    }
}
