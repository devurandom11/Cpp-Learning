#!/usr/bin/env bash
program=$1

case "${program}" in
    "main")
        echo "item = main"
        clang++ -Og -g -Wall -Werror -pedantic main.cpp -o main && chmod +x ./main && ./main
    ;;
    "test")
        echo "program = test"
        clang++ -Og -g -Wall -Werror -pedantic test.cpp -o test && chmod +x ./test && ./test
    ;;
    "selectionSort")
        echo "program = selectionSort"
        clang++ -Og -g -Wall -Werror -pedantic selectionSort.cpp -o selectionSort && chmod +x ./selectionSort && ./selectionSort
    ;;
    "insertionSort")
        echo "program = insertionSort"
        clang++ -Og -g -Wall -Werror -pedantic insertionSort.cpp -o insertionSort && chmod +x ./insertionSort && ./insertionSort
    ;;
    "shellSort")
        echo "program = shellSort"
        clang++ -Og -g -Wall -Werror -pedantic shellSort.cpp -o shellSort && chmod +x ./shellSort && ./shellSort
    ;;
    "quickSort")
        echo "program = quickSort"
        clang++ -Og -g -Wall -Werror -pedantic quickSort.cpp -o quickSort && chmod +x ./quickSort && ./quickSort
    ;;
    "clean")
        echo "program = clean"
        rm -rf *.o *.out *.exe *.stackdump *.dSYM *.exe.stackdump main test selectionSort insertionSort shellSort quickSort
    ;;
    "all")
        echo "program = all"
        clang++ -Og -g -Wall -Werror -pedantic main.cpp -o main && chmod +x ./main
        clang++ -Og -g -Wall -Werror -pedantic test.cpp -o test && chmod +x ./test
        clang++ -Og -g -Wall -Werror -pedantic selectionSort.cpp -o selectionSort && chmod +x ./selectionSort
        clang++ -Og -g -Wall -Werror -pedantic insertionSort.cpp -o insertionSort && chmod +x ./insertionSort
        clang++ -Og -g -Wall -Werror -pedantic shellSort.cpp -o shellSort && chmod +x ./shellSort
        clang++ -Og -g -Wall -Werror -pedantic quickSort.cpp -o quickSort && chmod +x ./quickSort
        executables=(test selectionSort insertionSort shellSort quickSort main)
        for executable in "${executables[@]}"
        do
            ./"$executable"
            echo ""
        done
    ;;
    *)
        echo "Incorrect Usage:"
        echo "Usage: ./build.sh [all|main|test|selectionSort|insertionSort|clean]"
    ;;
esac


