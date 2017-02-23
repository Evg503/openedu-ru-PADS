import inspect

def openedu_io_to_str(arg):
    if isinstance(arg, str):
        return arg
    elif isinstance(arg, bytes):
        return arg.decode()
    elif hasattr(arg, "__iter__"):
        return " ".join(str(i) for i in arg)
    else:
        return str(arg)


class openedu_io:
    def create_tokenizer(self):
        for line in self.inf:
            for token in line.split():
                yield token

    def __enter__(self):
        self.inf = open("input.txt", "rt", 1)
        self.ouf = open("output.txt", "wt", 1)
        self.tokens = self.create_tokenizer()
        return self

    def __exit__(self, type, value, traceback):
        self.inf.close()
        self.ouf.close()

    def next_int(self):
        return int(self.next_token())

    def next_float(self):
        return float(self.next_token())

    def next_token(self):
        return self.tokens.__next__()

    def all_tokens(self):
        return self.tokens

    def write(self, arg):
        self.ouf.write(openedu_io_to_str(arg))

    def writeln(self, arg):
        self.write(arg)
        self.write("\n")
