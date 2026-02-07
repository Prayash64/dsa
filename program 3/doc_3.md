# Recursive Reverse Traversal of Linked List

This C program demonstrates how to traverse and print the elements of a Singly Linked List in **reverse order** using recursion, without actually reversing the links of the list.

## 1. Data Structures Definition

The program uses a self-referential structure to define the Linked List nodes.

### `struct Node`
This structure represents a single element in the linked list.
* **`int data`**: Stores the integer value of the node.
* **`struct Node *next`**: A pointer that stores the address of the next node in the sequence. If it is `NULL`, it indicates the end of the list.

## 2. Function Descriptions

### `struct Node* createNode(int value)`
* **Purpose:** Utility function to create a new linked list node.
* **Mechanism:**
    1.  Allocates memory dynamically using `malloc`.
    2.  Assigns the given `value` to the `data` field.
    3.  Initializes the `next` pointer to `NULL`.
    4.  Returns the pointer to the newly created node.

### `void reverseTraversal(struct Node *head)`
* **Purpose:** Prints the list elements in reverse order using recursion.
* **Mechanism (The Stack Approach):**
    1.  **Base Case:** If `head` is `NULL` (end of list), the function returns.
    2.  **Recursive Call:** It calls itself with `head->next` *before* printing. This pushes the current node onto the system's call stack.
    3.  **Print:** After the recursive call returns (i.e., when it effectively comes "back" from the end of the list), it prints `head->data`. This results in the last element being printed first.



## 3. Overview of Main Method

The `main()` function handles the setup and execution:

1.  **List Creation:** It manually creates a hardcoded linked list with three nodes:
    * Node 1: `10`
    * Node 2: `20`
    * Node 3: `30`
    * *Structure:* `10 -> 20 -> 30 -> NULL`
2.  **Output:** It prints a label and then calls `reverseTraversal(head)`.
3.  **Result:** The recursive function prints `30`, then `20`, then `10`.

## 🛠️ How to Run

1.  **Compile the program:**
    ```bash
    gcc main.c -o reverse_list
    ```

2.  **Run the executable:**
    * **Windows:**
        ```bash
        reverse_list.exe
        ```
    * **Linux/Mac:**
        ```bash
        ./reverse_list
        ```

## 📸 Expected Output

```text
Reverse Traversal of Linked List: 30 20 10