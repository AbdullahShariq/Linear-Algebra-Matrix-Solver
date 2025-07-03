# Linear-Algebra-Matrix-Solver

A robust command-line application written in C for performing fundamental linear algebra matrix operations. This program is designed to facilitate matrix calculations, making it an excellent tool for students, educators, and developers exploring linear algebra concepts such as matrix inversion, transposition, cofactors, and solving systems of linear equations using the Gauss-Jordan method.

---

##  Features

- **Matrix Inverse**: Compute the inverse of a 2x2 or 3x3 matrix using the adjoint and determinant method.  
- **Matrix Transpose**: Interchange rows and columns of a matrix of any size (up to 10x10).  
- **Cofactor Matrix**: Calculate the cofactor matrix for a 3x3 matrix.  
- **Minor Matrix**: Generate the minor matrix for a 3x3 matrix.  
- **Gauss-Jordan Elimination**: Solve systems of linear equations by reducing the augmented matrix to row-echelon form.  
- **User-Friendly Interface**: Interactive menu-driven program with clear prompts and error handling for invalid inputs (e.g., non-invertible matrices).

---

##  Prerequisites

To compile and run this program, you need:

- A C compiler (e.g., `gcc`)
- Standard C libraries (`stdio.h`, `math.h`, `string.h`)
- A system with a command-line interface (Linux, macOS, or Windows with terminal support)

> **Note:** Ensure the `-lm` flag is used when compiling to link the math library.

---

##  How to Compile and Run

### 1. Clone the Repository

```bash
git clone https://github.com/AbdullahShariq/Linear-Algebra-Matrix-Solver.git
cd Linear-Algebra-Matrix-Solver
```
### 2.Compile the Code
```bash
gcc main.c -o matrix_solver -lm
```
### 3.Run the Program
```bash
./matrix_solver
```

---

##  Usage Instructions

- Launch the program to access the interactive menu.
- Select an operation by entering the corresponding letter:

  - `i`: Compute the inverse of a 2x2 or 3x3 matrix.  
  - `t`: Transpose a matrix of user-specified dimensions.  
  - `c`: Calculate the cofactor matrix of a 3x3 matrix.  
  - `m`: Calculate the minor matrix of a 3x3 matrix.  
  - `g`: Solve a system of linear equations using Gauss-Jordan elimination.  
  - `e`: Exit the program.

- Follow the prompts to input matrix dimensions and elements.
- Results will be displayed in formatted output (e.g., matrices or solutions).


