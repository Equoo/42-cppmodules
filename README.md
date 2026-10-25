# C++ modules (42)

The ten 42 C++ modules, written in C++98: from classes and memory to templates, the STL and algorithms.

## Build and run

Each exercise has its own `Makefile`:

```bash
make -C cpp09/ex02
./cpp09/ex02/PmergeMe 3 5 9 7 4
```

## Modules

| Module | Topic |
| --- | --- |
| cpp00 – cpp01 | Classes, namespaces, references, memory allocation |
| cpp02 | Operator overloading, orthodox canonical form, fixed-point numbers |
| cpp03 – cpp04 | Inheritance, polymorphism, abstract classes, interfaces |
| cpp05 | Exceptions |
| cpp06 | C++ casts (`ScalarConverter`, serialization, type identification) |
| cpp07 – cpp08 | Templates, STL containers and iterators |
| cpp09 | STL in practice: Bitcoin exchange (`btc`), reverse Polish notation calculator (`RPN`), merge-insertion sort (`PmergeMe`) |

## Highlight: PmergeMe

An implementation of the Ford-Johnson merge-insertion sort, written twice, on `std::vector` and on `std::list`, to compare how the same algorithm behaves on contiguous and linked containers.

## What I learned

Object-oriented design in C++, generic programming with templates, and choosing an STL container for its complexity rather than by habit.
