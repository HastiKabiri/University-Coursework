# C++ Programming

This directory contains C++ programming exercises and university assignments completed during my Software Engineering studies at Asia Pacific University.

## Practice

[Practice](Practice/) preserves the original repository's `Lab/` and `Practice/` organization. Topics include basic C++ syntax, console input/output, control flow, functions, structures, dynamic arrays, a class with copy construction and destruction, and linked-list exercises.

Some files are study drafts rather than complete programs. In particular, `Lab/LinkedList.cpp` is unfinished, `Lab/SLListOperations.cpp` contains two exercise programs in one file, `Practice/StudyCodes.cpp` includes an unfinished function example, and `Lab/topic6.cpp` is empty. They are retained as coursework, not presented as a passing application suite.

## Assignments

[Assignments](Assignments/) contains university coursework projects. The student record system uses a manually implemented singly linked list, linear search, bubble sorting by CGPA, CSV input, and operation timing. Its source uses the standard library, including `std::vector` and `std::filesystem`.

| Project | Description | Folder |
| --- | --- | --- |
| C++ Practice | Fundamental programming, memory management, classes, singly linked-list exercises, and a doubly linked music-player lab | [Practice](Practice/) |
| Singly Linked List Student Record Management System | Student records with insert, delete, search, sorting, display/count operations, and dataset benchmarking | [Assignment](Assignments/Singly-Linked-List-Student-System/) |

## Compile an individual program

Use a C++ compiler such as GCC/MinGW. For a complete practice example, run from the repository root:

```bash
g++ -std=c++17 CPP/Practice/Lab/classActivity5.cpp -o prime-exercise
```

Run `./prime-exercise` on Linux/macOS, or compile with `-o prime-exercise.exe` and run `.\prime-exercise.exe` in Windows PowerShell. This example prints prime numbers within an entered range.

For the assignment, run from its own directory so its CSV datasets can be found:

```bash
cd CPP/Assignments/Singly-Linked-List-Student-System
g++ -std=c++17 LinkedList_GroupPart.cpp -o student-system
```

Run `./student-system` on Linux/macOS. On Windows, compile with `-o student-system.exe` and run `.\student-system.exe`. The four dataset sizes are 500, 2,000, 8,000, and 30,000 synthetic records. Quadratic sorting on the largest dataset can take substantially longer.

## Import validation

Compiled with GCC/MinGW 15.2.0 using C++17:

| Result | Files |
| --- | --- |
| Compiled and passed basic console smoke checks | `Practice/Lab/classActivity5.cpp`, `Practice/Lab/lab3.cpp`, `Practice/Lab/lab7.cpp`, and the student-system assignment |
| Preserved incomplete exercises; not standalone buildable programs | `Practice/Lab/LinkedList.cpp` (unfinished structure), `Practice/Lab/SLListOperations.cpp` (duplicate exercise definitions and entry points), `Practice/Practice/StudyCodes.cpp` (nested function definition), `Practice/Lab/topic6.cpp` (empty file) |

No program-logic fixes were applied during organization. These are educational source snapshots, not a single passing application suite. Only two identifying attribution comments were redacted for privacy.

[Back to University Coursework](../README.md)
