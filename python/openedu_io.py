class openedu_io:
    def create_tokenizer(self):
        for line in self.inf:
            for token in line.split():
                yield token

    def __enter__(self):
        self.inf = open("input.txt", "rb")
        self.ouf = open("output.txt", "wb")
        self.tokens = self.create_tokenizer()
        return self

    def __exit__(self, type, value, traceback):
        self.inf.close()
        self.ouf.close()

    def next_int(self):
        return int(self.next_token())

    def next_double(self):
        return double(self.next_token())

    def next_token(self):
        return self.tokens.next()

    def write(self, arg):
        if isinstance(arg, bytes):
            self.ouf.write(arg)
        else:
            self.ouf.write(bytes(arg))

    def writeln(self, arg):
        self.write(arg)
        self.write('\n')
