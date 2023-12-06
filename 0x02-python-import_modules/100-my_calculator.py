#!/usr/bin/python3
if __name__ == "__main__":
    from calculator_1 import add, sub, mul, div
    from sys import argv

    if len(argv) != 4:
        print("Usage: {} <a> <operator> <b>".format(argv[0]))
        exit(1)

    op = argv[2]
    a = int(sys.argv[1])
    b = int(sys.argv[3])

    ops = {"+": add, "-": sub, "*": mul, "/": div}

    if op not in ops:
        print("Unknown operator. Available operators: +, -, * and /")
        exit(1)

    print("{} {} {} = {}".format(a, op, b, ops[op](a, b)))
