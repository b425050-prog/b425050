<div align="center">

# 🧪 Object-Oriented Programming Laboratory

### From structured records to pointers and dynamic memory

**C / C++17 • 6 Labs • 60 Source Programs • IIIT Bhubaneswar**

[![Language](https://img.shields.io/badge/language-C%20%7C%20C%2B%2B17-0b6db7?style=for-the-badge&logo=cplusplus&logoColor=white)](https://isocpp.org/)
[![Labs](https://img.shields.io/badge/labs-01--06-7957d5?style=for-the-badge)](#-laboratory-map)
[![Build](https://img.shields.io/badge/build-g%2B%2B%20-Wall-success?style=for-the-badge)](#%EF%B8%8F-quick-start)

<picture>
  <source media="(prefers-reduced-motion: reduce)" srcset="assets/lab6_pointer_memory_preview.png">
  <img src="assets/lab6_pointer_memory.gif" width="100%" alt="Animated C++ pointer and memory visualization">
</picture>

**Newest:** [Lab 06 — C++ Pointers](./LAB%206/) · pointer arithmetic, traversal, functions, and dynamic arrays

</div>

---

## 🗺️ Laboratory Map

| Lab | Topic | Core ideas | Programs |
|:---:|---|---|:---:|
| [**01**](./LAB%201/) | Structures & Records | Structures, nested records, arrays of structures | 10 |
| [**02**](./LAB%202/) | Classes & Objects | Encapsulation, private data, member functions | 10 |
| [**03**](./Lab3/) | Dynamic Memory Allocation | `new`, `delete`, dynamic arrays and matrices | 10 |
| [**04**](./LAB%204/) | Friend Function & Friend Class | Controlled private access and object collaboration | 10 |
| [**05**](./LAB%205/) | Function Overloading | Overload resolution and compile-time polymorphism | 10 |
| [**06**](./LAB%206/) | **C++ Pointers** | Dereferencing, pointer arithmetic, traversal, `delete[]` | **10** |

Each lab has its own guide with a problem index, source links, compilation commands, and viva-ready notes.

## ✨ Featured: Lab 06

Lab 06 follows a pointer from a single variable into arrays, functions, text traversal, searching, and dynamically allocated memory. The programs deliberately use pointer arithmetic where the worksheet restricts array indexing.

<picture>
  <source media="(prefers-reduced-motion: reduce)" srcset="assets/pointer_traversal_preview.png">
  <img src="assets/pointer_traversal.gif" width="100%" alt="Pointer moving through consecutive integer array elements">
</picture>

```cpp
int values[] = {18, 42, 27, 64, 35, 51};
int* current = values;

while (current < values + 6) {
    std::cout << *current << ' ';  // dereference the current element
    ++current;                     // advance by one integer
}
```

> `++current` advances to the next `int`; pointer arithmetic is automatically scaled by the pointed-to type.

## ▶️ Quick Start

Clone the repository and enter any lab folder:

```bash
git clone https://github.com/b425050-prog/b425050.git
cd b425050/"LAB 6"
g++ -std=c++17 -Wall -Wextra -pedantic L6P1.cpp -o L6P1
./L6P1
```

On Windows PowerShell, run the generated executable with `./L6P1.exe` or `.\L6P1.exe`.

## 📁 Repository Layout

```text
b425050/
├── README.md
├── assets/              # animated GIFs and static fallbacks
├── LAB 1/               # structures and records
├── LAB 2/               # classes and objects
├── Lab3/                # dynamic memory allocation
├── LAB 4/               # friend functions and classes
├── LAB 5/               # function overloading
└── LAB 6/               # C++ pointers (10 programs)
```

## ✅ Code Quality

- Descriptive identifiers instead of single-letter working variables
- Focused comments that explain pointer intent and memory ownership
- Input validation for sizes, positions, and status codes
- `const` pointers for read-only traversal
- Matching `delete[]` for every dynamically allocated array
- Portable C++17 builds with warning flags enabled

---

<div align="center">

**International Institute of Information Technology, Bhubaneswar**

Built as a practical progression through C and C++ fundamentals.

</div>
