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
     * Allows conveniently printing various primitives and objects
     * separated by the given character.
     */
    public static final class SequencePrinter {
        private boolean hasStarted = false;
        private final char separator;
        private final PrintWriter base;

        /**
         * Constructs a SequencePrinter out of an existing PrintWriter
         * and a character to separate tokens.
         * @param base the PrintWriter used for output.
         * @separator the character to separate tokens.
         */
        public SequencePrinter(PrintWriter base, char separator) {
            this.base = base;
            this.separator = separator;
        }

        /**
         * Resets the SequencePrinter such that the next token will be output
         * without the leading separator.
         * @return itself.
         */
        public SequencePrinter begin() {
            hasStarted = false;
            return this;
        }

        private void check() {
            if (hasStarted) {
                base.print(separator);
            }
            hasStarted = true;
        }

        /**
         * Prints a character, with the separator character prepended to it if necessary.
         * @param value the value to be printed.
         * @return itself.
         */
        public SequencePrinter add(char value) {
            check();
            base.print(value);
            return this;
        }

        /**
         * Prints the given characters,
         * with the separator character prepended to all of them
         * (including, if necessary, the leading one).
         * @param values the values to be printed.
         * @return itself.
         */
        public SequencePrinter add(char[] values) {
            return add(values, 0, values.length);
        }

        /**
         * Prints the given characters from the given range,
         * with the separator character prepended to all of them
         * (including, if necessary, the leading one).
         * @param values the values to be printed.
         * @from the first index to use for printing.
         * @until the next-to-last index to use for printing.
         * @return itself.
         */
        public SequencePrinter add(char[] values, int from, int until) {
            for (int i = from; i < until; ++i) {
                add(values[i]);
            }
            return this;
        }

        public SequencePrinter add(int value) {
            check();
            base.print(value);
            return this;
        }

        public SequencePrinter add(int[] values) {
            return add(values, 0, values.length);
        }

        public SequencePrinter add(int[] values, int from, int until) {
            for (int i = from; i < until; ++i) {
                add(values[i]);
            }
            return this;
        }

        public SequencePrinter add(long value) {
            check();
            base.print(value);
            return this;
        }

        public SequencePrinter add(long[] values) {
            return add(values, 0, values.length);
        }

        public SequencePrinter add(long[] values, int from, int until) {
            for (int i = from; i < until; ++i) {
                add(values[i]);
            }
            return this;
        }

        public SequencePrinter add(double value) {
            check();
            base.print(value);
            return this;
        }

        public SequencePrinter add(double[] values) {
            return add(values, 0, values.length);
        }

        public SequencePrinter add(double[] values, int from, int until) {
            for (int i = from; i < until; ++i) {
                add(values[i]);
            }
            return this;
        }

        public SequencePrinter add(Object value) {
            check();
            base.print(value);
            return this;
        }

        public SequencePrinter add(Object[] values) {
            return add(values, 0, values.length);
        }

        public SequencePrinter add(Object[] values, int from, int until) {
            for (int i = from; i < until; ++i) {
                add(values[i]);
            }
            return this;
        }

        public SequencePrinter add(Iterator<?> iterator) {
            while (iterator.hasNext()) {
                add(iterator.next().toString());
            }
            return this;
        }

        public SequencePrinter add(Iterable<?> collection) {
            return add(collection.iterator());
        }

        public SequencePrinter print() {
            return begin();
        }

        public SequencePrinter println() {
            base.println();
            return begin();
        }
    }

    /**
     * Printer is a convenience subclass of {@link PrintWriter}.
     * It provides additional functionality to print several whitespace-separated entities.
     */
    public static final class Printer extends PrintWriter {
        private final SequencePrinter spaces = new SequencePrinter(this, ' ');
        private final SequencePrinter lines = new SequencePrinter(this, '\n');

        /**
         * Creates a new Printer which writes to the specified file.
         * @param filename the name of the file to be written to.
         */
        public Printer(String filename) throws IOException {
            super(filename);
        }

        /**
         * Returns a SequencePrinter which separates output tokens by single whitespaces.
         * @return the SequencePrinter which separates output tokens by spaces.
         */
        public SequencePrinter withSpaces() {
            return spaces.begin();
        }

        /**
         * Returns a SequencePrinter which separates output tokens by single newlines.
         * @return the SequencePrinter which separates output tokens by newlines.
         */
        public SequencePrinter withNewlines() {
            return lines.begin();
        }

        /**
         * Prints all given ints, separated by a whitespace and finished with a newline.
         * @param ints the ints to be printed.
         * @return itself.
         */
        public Printer println(int[] ints) {
            withSpaces().add(ints).println();
            return this;
        }

        /**
         * Prints all given longs, separated by a whitespace and finished with a newline.
         * @param first the first long to be printed.
         * @param others the other longs to be printed.
         * @return itself.
         * @deprecated use the {$link SequencePrinter} obtained by {@link withSpaces}.
         */
        @Deprecated
        public Printer println(long first, long... others) {
            withSpaces().add(first).add(others).println();
            return this;
        }

        /**
         * Prints all given longs, separated by a whitespace and finished with a newline.
         * @param longs the longs to be printed.
         * @return itself.
         */
        public Printer println(long[] longs) {
            withSpaces().add(longs).println();
            return this;
        }

        /**
         * Prints all given doubles, separated by a whitespace and finished with a newline.
         * @param doubles the doubles to be printed.
         * @return itself.
         */
        public Printer println(double[] doubles) {
            withSpaces().add(doubles).println();
            return this;
        }

        /**
         * Prints all given objects, separated by a whitespace and finished with a newline.
         * @param objects the objects to be printed.
         * @return itself.
         */
        public Printer println(Object[] objects) {
            withSpaces().add(objects).println();
            return this;
        }

        /**
         * Prints the elements of the given collection, separated by a whitespace and finished with a newline.
         * @param collection the collection to be printed.
         * @return itself.
         */
        public Printer printlnCollection(Collection<?> collection) {
            withSpaces().add(collection).println();
            return this;
        }
    }
}
