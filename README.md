
# Grade Curve Calculator

A C++ console application that calculates and applies a **grading curve** to a set of student scores.  
Users can input grades, view statistics (average, min, max), and curve the results to reach a desired average.

---

## Features
- Accepts user-entered numeric grades (0–100)
- Validates input and prevents invalid or out-of-range values
- Calculates:
  - Number of scores
  - Minimum and maximum scores
  - Original and curved averages
- Applies a grading curve based on a user-defined expected average
- Uses **object-oriented programming** with `Gradebook` and `FinalGrade` classes

---
# Example Run

Please enter a score for CS218 (type 'Q' or 'q' to quit): 80
Please enter a score for CS218 (type 'Q' or 'q' to quit): 90
Please enter a score for CS218 (type 'Q' or 'q' to quit): 70
Please enter a score for CS218 (type 'Q' or 'q' to quit): q

The original average score is: 80.00
Please enter your expected average score to curve (type 'Q' or 'q' to quit): 85

The original gradebook for CS218:
80.00 90.00 70.00
The curved gradebook for CS218:
85.00 95.00 75.00


---

## ⚙️ Technologies Used
- **Language:** C++
- **Libraries:** `<iostream>`, `<iomanip>`, `<string>`
- **Concepts:** OOP, input validation, loops, functions, data encapsulation

---

## 📁 File Structure
GradeCurveCalculator/
│
├── main.cpp # Main driver program
├── FinalGrade.h/.cpp # Class for individual grade representation
├── Gradebook.h/.cpp # Class for managing a collection of grades
└── README.md # Project description (this file)
