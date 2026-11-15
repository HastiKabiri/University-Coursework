# 🎓 Academic Assignment: Student Record Management System (Singly Linked List)

This repository contains an independent implementation of a Student Record Management System, developed as part of an official academic assignment for the **CT077-3-2 Data Structures & Algorithms (DSTR)** module at **Asia Pacific University of Technology & Innovation (APU)**. 

## 📋 Assignment Overview
*   **Module Code:** CT077-3-2
*   **Assignment Title:** Developing a Student Record Management System Using Arrays and Linked Lists in C++
*   **My Role:** Role 3 — Linked List Developer (Basic Sort)
*   **Implementation Type:** Individual Deliverable (Singly Linked List from scratch)

---

## 📌 Role Specifics & Architecture

As the Linked List Developer for this assignment, my specific task is to design, implement, and empirically measure a memory-efficient system using a custom pointer-based structure without relying on any built-in C++ standard template libraries (STL):

*   **Data Structure:** Singly Linked List (SLL) built completely from scratch.
*   **Sorting Algorithm:** Selection Sort / Bubble Sort ($O(n^2)$ time complexity class)[cite: 1].
*   **Searching Algorithm:** Linear Search ($O(n)$ time complexity class)[cite: 1].
*   **Benchmarking Unit:** Microseconds ($\mu s$) utilizing C++ `<chrono>` to map empirical growth rates against theoretical Big-O curves[cite: 1].

---

## 🛠️ System Features & Constraints

### 1. Data Structure Operations
*   **Insert:** Support for inserting new student records at the **beginning**, **end**, or a **specified position** in the list[cite: 1].
*   **Delete:** Removal of a node cleanly from dynamic memory by a unique `Student ID`[cite: 1].
*   **Search:** Linear search lookup by `Student ID` or `Full Name`[cite: 1].
*   **Display:** Complete sequential traversal and formatting of the current list records[cite: 1].
*   **Count:** Traverses and returns the exact runtime count of nodes in the list[cite: 1].
*   **Sort:** Sorts the entire linked list by **CGPA** in ascending/descending order using an $O(n^2)$ algorithm via pointer re-linking[cite: 1].

### 2. Assignment Guardrails & Error Handling
*   Prevents operations on an empty data structure[cite: 1].
*   Rejects duplicate Student IDs to ensure data integrity[cite: 1].
*   Gracefully handles the deletion of non-existent records[cite: 1].
*   Validates CGPA inputs strictly between the range `0.0` and `4.0`[cite: 1].
*   Skips or reports malformed lines within CSV inputs[cite: 1].

---

## 📊 Dataset Scale & Big-O Benchmark Testing

The coursework requires verifying code execution times across four progressively scaled datasets to observe empirical execution time growth trends and validate Big-O complexity[cite: 1]:

| File Name | Records | File Size | Expected $O(n^2)$ Sort Growth Trend | Expected $O(n)$ Search Trend |
| :--- | :--- | :--- | :--- | :--- |
| `students_500.csv` | 500 | ~25 KB | Baseline reference[cite: 1] | Baseline reference |
| `students_2000.csv` | 2,000 | ~100 KB | $\sim 16\times$ baseline[cite: 1] | $\sim 4\times$ baseline[cite: 1] |
| `students_8000.csv` | 8,000 | ~400 KB | $\sim 256\times$ baseline | $\sim 16\times$ baseline[cite: 1] |
| `students_30000.csv`| 30,000 | ~1.5 MB | $\sim 3600\times$ baseline | $\sim 60\times$ baseline[cite: 1] |

> 💡 **Note:** All execution times are captured meticulously in **microseconds ($\mu s$)** using `<chrono>` as required by the assignment guidelines[cite: 1].

---

## 📂 Repository Structure

```text
├── TPXXXXXX_Name_CT077_LW1.cpp  # Main C++ source code containing SLL implementation[cite: 1]
├── TPXXXXXX_PerfRecord.txt       # Completed Individual Performance Record template[cite: 1]
├── README.md                     # Repository documentation (this file)
├── DATASET_README.txt            # Guideline document for analyzing the dataset scales[cite: 1]
├── programmes.csv                # Reference table for academic faculty details[cite: 1]
├── students_500.csv              # 500 Records Dataset[cite: 1]
├── students_2000.csv             # 2,000 Records Dataset[cite: 1]
├── students_8000.csv             # 8,000 Records Dataset[cite: 1]
└── students_30000.csv            # 30,000 Records Dataset[cite: 1]
