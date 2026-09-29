<div align="center">

# Lab 6 · Operator Overloading

**C++17 · 10 exercises · Group B2 · 29 September 2026**

IIIT Bhubaneswar · B.Tech 3rd Semester · OOP Laboratory

<picture>
  <source media="(prefers-reduced-motion: reduce)" srcset="../assets/operator_overloading_preview.png">
  <img src="../assets/operator_overloading.gif" width="100%" alt="An overloaded plus operator adds and normalises two distances to 9 feet 3 inches.">
</picture>

[Repository home](../README.md) · [Lab Exam-1: pointers](../Lab%20Exam-1/)

</div>

These programs follow **OOP_LAB_6_B2.pdf**. Every exercise uses the required overloaded operator in `main()` and is a separate, runnable C++ program.

## Exercise index

| # | Exercise | Class | Operator | Source |
|:---:|:---|:---|:---|:---:|
| 1 | Distance Addition | `Distance` | `+` | [L6P1.cpp](./L6P1.cpp) |
| 2 | Complex Number Subtraction | `Complex` | binary `-` | [L6P2.cpp](./L6P2.cpp) |
| 3 | Student Marks Comparison | `Student` | `>` | [L6P3.cpp](./L6P3.cpp) |
| 4 | Negative Value Converter | `Number` | unary `-` | [L6P4.cpp](./L6P4.cpp) |
| 5 | Time Addition | `Time` | `+` | [L6P5.cpp](./L6P5.cpp) |
| 6 | Counter Increment | `Counter` | prefix and postfix `++` | [L6P6.cpp](./L6P6.cpp) |
| 7 | Date Equality Checker | `Date` | `==` | [L6P7.cpp](./L6P7.cpp) |
| 8 | Inventory Combination | `Item` | `+` | [L6P8.cpp](./L6P8.cpp) |
| 9 | Temperature Comparison | `Temperature` | `<` and `>` | [L6P9.cpp](./L6P9.cpp) |
| 10 | Shopping Cart Calculator | `Product` | `+` and `>` | [L6P10.cpp](./L6P10.cpp) |

## Compile and run

From this folder, compile **one source file at a time**:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic L6P1.cpp -o L6P1
./L6P1
```

In Windows PowerShell, use `-o L6P1.exe` and run `.\L6P1.exe`. Substitute the exercise number as needed. Do not link all ten source files into one executable: each has its own `main()`.

## Sample runs

For numeric inputs, spaces and newlines are interchangeable. For names, enter the full name on its own line, then the numeric values on the next line. In the table below, **↵ means press Enter**.

| Program | Sample input | Key result |
|:---|:---|:---|
| P1 | `5 8` ↵ `3 7` | `Result: 9 feet 3 inches` |
| P2 | `8 5` ↵ `3 2` | `C1 - C2 = 5 + 3i` |
| P3 | `Asha` ↵ `90` ↵ `Ravi` ↵ `85` | `Asha has higher marks.` |
| P4 | `25` | `n1 = 25`, `n2 = -25` |
| P5 | `4 45` ↵ `2 30` | `Result: 7 hours 15 minutes` |
| P6 | `10` | Prefix returns `11`; postfix returns `11`; final counter is `12` |
| P7 | `15 08 2026` ↵ `15 08 2026` | `Both dates are equal.` |
| P8 | `Notebook` ↵ `50 2` ↵ `Notebook` ↵ `50 3` | Combined quantity `5`; total `250.00` |
| P9 | `20 30` | `First temperature is lower than the second.` |
| P10 | `Pen` ↵ `10 2` ↵ `Pen` ↵ `10 5` | Second total is higher; combined quantity `7`, total `70.00` |

## What to notice

- **Distances and times:** constructors normalise inches and minutes, including inputs already above 12 or 60. Time represents a duration, so hours do not wrap at 24.
- **Complex numbers:** negative imaginary results print as `a - bi`.
- **Student and temperature comparisons:** both directions are checked so ties receive their own message. Comparison operators return `bool`.
- **Unary minus:** `-n1` returns a new `Number`. The original value stays unchanged.
- **Prefix increment:** `Counter& operator++()` changes the counter and returns a reference to it.
- **Postfix increment:** `Counter operator++(int)` saves the old value, increments the counter, and returns the saved copy. The dummy `int` distinguishes the signature.
- **Dates:** equality compares day, month, and year. Input validation handles month lengths and Gregorian leap years.
- **Inventory and products:** addition requires both the same name and the same price. A mismatch throws `std::invalid_argument`, which `main()` catches to display a message. Both originals are printed after the attempt.
- **Shopping cart:** `>` compares `price * quantity`, not just the unit price. Comparison works even when the products cannot be combined.

## Input conventions

Names can contain spaces and are matched case-sensitively. Distances, durations, marks, prices, and quantities must be non-negative. Prices and quantities in P8/P10 are capped at one billion. Prices use `double` for this classroom exercise and must compare exactly to combine items. Temperature values and complex components must be finite.

Integer console inputs use `int`; distance/time arithmetic, stored counter values, unary negation, and combined quantities use `long long` to accommodate the results of those inputs. Invalid numeric input exits with a message and a nonzero status.

## Viva quick notes

| Question | Answer |
|:---|:---|
| What is operator overloading? | Giving an existing C++ operator behaviour for a user-defined type. |
| Can overloading change precedence? | No. Precedence, associativity, and the number of operands stay the same. |
| Why pass `const Class&`? | It avoids copying the operand and prevents changing it through that reference. |
| Why make an operator a `const` member? | It promises not to modify the left-hand object and allows use on const objects. |
| Why return an object from `+`? | The sum is a new value; neither input needs to change. |
| Why return `bool` from comparisons? | Their result answers a true-or-false question. |

---

[← Repository home](../README.md) · [Previous: Function overloading](../LAB%205/) · [Lab Exam-1](../Lab%20Exam-1/)
