#### How to use the stress tester (Thanks Errichto)
- `a.cpp` - incorrect solution
- `brute.cpp` - correct slow solution
- `in` - sample input
- `gen.cpp` - test generator
- `s.sh` - script that tests a.cpp and brute.cpp against each other
- `gen_tree.cpp` - stupid tree generator
- `gen_tree2.cpp` - better tree generator

My compilation flags:

1. fast running time
    `g++ -O2 -std=c++17 -Wno-unused-result -Wshadow -Wall -o a a.cpp`

2. check for mistakes
    `g++ -std=c++17 -Wshadow -Wall -o a a.cpp
        -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -g`
