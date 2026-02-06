# Infix to Postfix Converter and Evaluator

This C program implements a Stack data structure to convert a mathematical **Infix expression** (standard math notation) into a **Postfix expression** (Reverse Polish Notation) and subsequently evaluates the result.

## 1. Data Structures Definition

The program uses **two separate stacks** implemented using static arrays to handle operators and integer values independently.

### Global Variables
* **`#define MAX 100`**: Sets the maximum size for the expression and stacks to 100 elements.

### The Operator Stack (`opStack`)
Used during the conversion phase to store operators (`+`, `-`, `*`, etc.) temporarily until their precedence determines they should be moved to the output.
* `char opStack[MAX]`: An array of characters to hold the operators.
* `int topOp`: An integer tracking the top index of the operator stack (initialized to -1).

### The Value Stack (`valStack`)
Used during the evaluation phase to store operand numbers (digits) and intermediate results.
* `int valStack[MAX]`: An integer array to store numerical values.
* `int topVal`: An integer tracking the top index of the value stack (initialized to -1).

---

## 2. Function Descriptions

The program is modularized into specific functions for stack operations, logic handling, and mathematical evaluation.

### Stack Operations
* **`void pushOp(char x)`**: Pushes a character (operator or parenthesis) onto the `opStack`.
* **`char popOp()`**: Removes and returns the top character from the `opStack`.
* **`void pushVal(int x)`**: Pushes an integer (operand) onto the `valStack`.
* **`int popVal()`**: Removes and returns the top integer from the `valStack`.

### Logic & Processing
* **`int priority(char x)`**: Determines the precedence of mathematical operators.
    * Returns `3` for Power (`^`).
    * Returns `2` for Multiply/Divide (`*`, `/`).
    * Returns `1` for Add/Subtract (`+`, `-`).
    * Returns `0` for others.
* **`void convert(char infix[], char postfix[])`**: Implements the core logic (similar to the Shunting-yard algorithm) to transform the input string `infix` into the output string `postfix`. It handles:
    * Operands (0-9): Added directly to output.
    * `(`: Pushed to stack.
    * `)`: Pops from stack until `(` is found.
    * Operators: Pops higher priority operators from the stack before pushing the current one.
* **`int evaluatePostfix(char postfix[])`**: Iterates through the generated postfix string to calculate the result.
    * If a number is found, it is pushed to `valStack`.
    * If an operator is found, two numbers are popped, the operation is performed, and the result is pushed back.

---

## 3. Overview of Main Method

The `main()` function serves as the driver for the application. Its organization is sequential:

1.  **Declaration**: It declares character arrays `infix[MAX]` and `postfix[MAX]` to store the user input and the converted string.
2.  **Input**: It prompts the user to enter an infix expression using `scanf`.
3.  **Conversion Call**: It calls `convert(infix, postfix)` to process the data.
4.  **Display Postfix**: It prints the resulting Postfix expression to the console.
5.  **Evaluation & Output**: It calls `evaluatePostfix(postfix)` inside a `printf` statement to calculate and display the final numerical result.

---

## 🛠️ How to Run

1.  **Compile the Code:**
    ```bash
    gcc main.c -o solver -lm
    ```
    *(Note: `-lm` is required on Linux/Mac to link the math library for `pow`)*

2.  **Run the Executable:**
    ```bash
    ./solver
    ```

## 📸 Output Example


![Output](https://github.com/Prayash64/dsa_assignment/blob/main/output/2.jpg?raw=true)
