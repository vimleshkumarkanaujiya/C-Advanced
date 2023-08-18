# C++ Advanced
It contains some important C++ programs to make you understand the concepts easily.

## Command Line Arguments - C++

When you run a C++ program from the command line like this:

```
./main arg1 arg2 arg3
```

- `./program` is the name of the executable (the program itself), and it is stored in `argv[0]`.
- `arg1`, `arg2`, and `arg3` are command line arguments, and they are stored in `argv[1]`, `argv[2]`, and `argv[3]` respectively.
- `argc` will be set to `4` because there are four items in the `argv` array.

For example:

```cpp
#include <iostream>

int main(int argc, char* argv[]) {
    std::cout << "Number of arguments: " << argc << std::endl;

    for (int i = 0; i < argc; ++i) {
        std::cout << "Argument " << i << ": " << argv[i] << std::endl;
    }

    return 0;
}
```

If you run it as `./main arg1 arg2 arg3`, the output will be:

```
Number of arguments: 4
Argument 0: ./main
Argument 1: arg1
Argument 2: arg2
Argument 3: arg3
```

This mechanism allows your program to receive and process input from the command line.
