"""Compile and check all Lab 7 exercises. Requires Python 3 and g++.

Run from any directory: python scripts/verify_lab7.py
Use --record-samples only when intentionally refreshing the sample transcripts.
No third-party Python packages are required.
"""

import argparse
import os
from pathlib import Path
import shutil
import subprocess
import tempfile

ROOT = Path(__file__).resolve().parents[1]
LAB = ROOT / "LAB 7"

# Expected values are independent, hand-calculated worksheet examples.
SAMPLES = {
    1: ("Asha Das\n50000 4 10000\n", ["Experience bonus: 10000.00", "Final salary: 70000.00"]),
    2: ("Ravi Kumar\nB425001\n80 75 90\nAsha Das\nB425050\n80 75 90\n",
        ["Final total: 245.00", "Final total: 250.00"]),
    3: ("OD 02 AB 1234\n3 2000 500\n", ["Registration number: OD 02 AB 1234", "Total rental cost: 7500.00"]),
    4: ("00101\n10000 5\n00202\n2000 3000 100\n",
        ["Account number: 00101", "Updated balance: 10500.00", "Updated balance: 1900.00"]),
    5: ("80 75 90 95\n", ["Academic total: 245.00", "Total: 340.00", "Average: 85.00"]),
    6: ("25 65\n", ["Internal exam marks: 25.00", "External exam marks: 65.00"]),
    7: ("Asha Das\n21 B425050 9.2 TA101 15000\n",
        ["Name: Asha Das", "Age: 21", "Roll number: B425050", "CGPA: 9.20",
         "Employee ID: TA101", "Salary: 15000.00", "Shared Person base: Yes"]),
    8: ("Ravi Kumar\nP101 35 2500 4\n", ["Patient name: Ravi Kumar", "Total hospital bill: 10000.00"]),
    9: ("Asha Das\n35 E101 80000\nSoftware Development\n",
        ["Person constructor\nEmployee constructor\nManager constructor",
         "Name: Asha Das", "Age: 35", "Employee ID: E101", "Salary: 80000.00",
         "Department: Software Development"]),
    10: ("E501\nRavi Kumar\nC++\nSelenium WebDriver\n",
         ["Employee ID: E501", "Name: Ravi Kumar", "Programming language: C++",
          "Testing tool: Selenium WebDriver", "Shared Employee base: Yes"]),
}

# (problem, input, expected fragments); exercise important semantic boundaries.
BOUNDARIES = [
    (1, "Zero Bonus\n1000 0 0\n", ["Experience bonus: 0.00", "Final salary: 1000.00"]),
    (1, "Fractional Salary\n1000.50 2 50.25\n", ["Experience bonus: 100.05", "Final salary: 1150.80"]),
    (2, "Regular\nR1\n100 100 100\nScholar\nS1\n100 100 100\n",
     ["Final total: 300.00", "Final total: 305.00"]),
    (2, "Regular\nR1\n0 0 0\nScholar\nS1\n0 0 0\n",
     ["Final total: 0.00", "Final total: 5.00"]),
    (3, "ZERO\n0 2000 500\n", ["Total rental cost: 0.00"]),
    (3, "DECIMAL\n2 100.50 10.25\n", ["Total rental cost: 221.50"]),
    (4, "001\n1000 0\n002\n3000 3000 100\n", ["No maintenance charge.", "Updated balance: 3000.00"]),
    (4, "001\n1000 0\n002\n4000 3000 100\n", ["No maintenance charge.", "Updated balance: 4000.00"]),
    (4, "001\n0 5\n002\n50 3000 100\n", ["Maintenance charge deducted.", "Updated balance: -50.00"]),
    (5, "0 0 0 0\n", ["Total: 0.00", "Average: 0.00"]),
    (5, "100 100 100 100\n", ["Total: 400.00", "Average: 100.00"]),
    (5, "1 2 3 4\n", ["Total: 10.00", "Average: 2.50"]),
    (6, "0 100\n", ["Internal exam marks: 0.00", "External exam marks: 100.00"]),
    (7, "Boundary Name\n0 0001 10 0002 0\n", ["CGPA: 10.00", "Shared Person base: Yes"]),
    (8, "Zero Days\n0001 0 2500 0\n", ["Total hospital bill: 0.00"]),
    (9, "Multi Word Name\n0 0001 0\nResearch and Development\n",
     ["Person constructor\nEmployee constructor\nManager constructor", "Department: Research and Development"]),
    (10, "0001\nMulti Word Name\nVisual Basic\nSelenium WebDriver\n",
     ["Employee ID: 0001", "Programming language: Visual Basic", "Shared Employee base: Yes"]),
]

INVALID = [
    (1, "Name\n-1 2 100\n"), (1, "Name\n100 abc 10\n"),
    (1, "Name\n1e308 1000 1e308\n"),
    (2, "Name\nR1\n101 0 0\n"),
    (3, "REG\n-1 10 1\n"), (3, "REG\n3 1e308 1e308\n"),
    (4, "S1\n1000 -5\n"), (4, "S1\n1e308 1e308\nC1\n0 0 0\n"),
    (5, "-1 50 50 50\n"), (5, "100 100 100 101\n"),
    (6, "25 -1\n"), (7, "Name\n21 R1 10.1 E1 1000\n"),
    (8, "Name\nP1 35 2000 -1\n"), (8, "Name\nP1 35 1e308 10\n"),
    (9, "Name\n35 E1 -1\n"), (10, "E1\nName\nC++\n"),
]


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--record-samples", action="store_true")
    args = parser.parse_args()
    compiler = shutil.which("g++")
    if not compiler:
        raise SystemExit("g++ is required. Install a C++17 GCC compiler and add it to PATH.")
    passed = 0
    with tempfile.TemporaryDirectory(prefix="oop_lab7_") as temp:
        executables = {}
        for number in range(1, 11):
            source = LAB / f"L7P{number}.cpp"
            code = source.read_text(encoding="utf-8")
            if "#include <iostream>" not in code or "using namespace std;" not in code:
                raise AssertionError(f"{source.name}: required source style is missing")
            target = Path(temp) / (source.stem + (".exe" if os.name == "nt" else ""))
            subprocess.run([compiler, "-std=c++17", "-Wall", "-Wextra", "-pedantic", "-Werror",
                            str(source), "-o", str(target)], check=True)
            executables[number] = target
        print("Compiled 10 programs with no warnings.")

        def run(number, data, expected=(), valid=True):
            nonlocal passed
            result = subprocess.run([str(executables[number])], input=data, text=True,
                                    capture_output=True, timeout=5)
            if valid and result.returncode != 0:
                raise AssertionError(f"P{number} unexpectedly rejected input: {result.stderr}")
            if not valid and result.returncode == 0:
                raise AssertionError(f"P{number} accepted invalid/incomplete input: {data!r}")
            for fragment in expected:
                if fragment not in result.stdout:
                    raise AssertionError(f"P{number} missing {fragment!r} in {result.stdout!r}")
            passed += 1
            return result.stdout

        samples = LAB / "samples"
        if args.record_samples:
            samples.mkdir(exist_ok=True)
        for number, (data, expected) in SAMPLES.items():
            output = run(number, data, expected)
            input_path = samples / f"L7P{number}.in.txt"
            output_path = samples / f"L7P{number}.out.txt"
            if args.record_samples:
                input_path.write_text(data, encoding="utf-8")
                output_path.write_text(output, encoding="utf-8")
            else:
                if input_path.read_text(encoding="utf-8") != data:
                    raise AssertionError(f"P{number}: recorded input differs")
                if output_path.read_text(encoding="utf-8") != output:
                    raise AssertionError(f"P{number}: recorded output differs")
        for number, data, expected in BOUNDARIES:
            run(number, data, expected)
        for number, data in INVALID:
            run(number, data, valid=False)
        for number in range(1, 11):
            run(number, "", valid=False)
    print(f"PASS: {passed} runtime cases; samples, boundaries, invalid input and EOF checked.")


if __name__ == "__main__":
    main()
