# Singly Linked List Student Record Management System

A C++ data structures assignment from the CT077-3-2 Data Structures & Algorithms module at Asia Pacific University. Imported from [singly-linked-list-student-system-CPP](https://github.com/HastiKabiri/singly-linked-list-student-system-CPP) at commit [`eac678f`](https://github.com/HastiKabiri/singly-linked-list-student-system-CPP/commit/eac678fee3d2cd9ce5c2d8b8149c45742f6168e0).

## Verified implementation

- A singly linked list built with custom student/node structures and pointers.
- Insert at the beginning, end, or a chosen position; delete by student ID.
- Linear search by ID or full name, sequential display, and node counting.
- Bubble sort by CGPA, swapping stored records.
- CSV loading, checks for existing IDs, and dataset lookup helpers.
- Timing with `<chrono>`: the interactive sort reports microseconds, while the all-dataset benchmark reports milliseconds.

The source uses standard-library components including strings, streams, `std::vector`, and `std::filesystem`. It does not implement a custom array-based alternative or binary search.

## Files and datasets

- [LinkedList_GroupPart.cpp](LinkedList_GroupPart.cpp): current source, retained unchanged.
- [DATASET_README.txt](DATASET_README.txt): original dataset and benchmarking guide.
- [programmes.csv](programmes.csv): programme reference table.
- Student CSV datasets: [500](students_500.csv), [2,000](students_2000.csv), [8,000](students_8000.csv), and [30,000](students_30000.csv) records.
- [Original source archive](LinkedList_GroupPart_%20Hasti%20Kabiri.zip): an earlier source file and dataset guide, retained because their contents differ from the loose files.
- [README.original.md](README.original.md): original assignment description, including historical claims and filenames that do not all match this source. Use this guide and the actual code for the current implementation.

The owner confirmed that all dataset records are synthetic and that the guide and programme reference table may be shared publicly. No real student contact information should be added to these files.

## Compile and run

Use a compiler with C++17 support and run from this folder:

```bash
g++ -std=c++17 LinkedList_GroupPart.cpp -o student-system
./student-system
```

For Windows PowerShell, compile with `-o student-system.exe` and run `.\student-system.exe`.

The program prompts for a dataset before presenting its menu. Keep the CSV files alongside the executable, and expect the 30,000-record quadratic sort to take longer than smaller datasets. No executable or machine-specific VS Code settings are distributed here.

[Back to C++ Programming](../../README.md)
