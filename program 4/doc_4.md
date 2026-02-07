# Doubly Linked List Operations

This C program implements a **Doubly Linked List** and performs fundamental operations such as insertion after a given node and deletion of a specific node. Unlike a singly linked list, each node in this structure maintains references to both its previous and next neighbors, allowing for bidirectional traversal.

## 1. Data Structures Definition

The program relies on a specific structure to represent the nodes of the doubly linked list.

### `struct Node`
Each element in the list is defined by this structure, which contains three components:
* **`int data`**: Stores the integer value held by the node.
* **`struct Node *prev`**: A pointer to the previous node in the list. This allows for backward traversal.
* **`struct Node *next`**: A pointer to the next node in the list. This allows for forward traversal.



## 2. Function Descriptions

The program implements specific functions to manage list modifications and display.

### `void insertAfter(struct Node *prevNode, int newData)`
* **Purpose:** Inserts a new node containing `newData` immediately after a specific node (`prevNode`).
* **Logic:**
    1.  Allocates memory for the new node.
    2.  Updates the `next` pointer of the new node to point to `prevNode`'s current successor.
    3.  Updates the `prev` pointer of the new node to point to `prevNode`.
    4.  Adjusts the pointers of the surrounding nodes (`prevNode->next` and `prevNode->next->prev`) to integrate the new node into the chain.

### `void deleteNode(struct Node **head, struct Node *delNode)`
* **Purpose:** Removes a specific node (`delNode`) from the list and frees its memory.
* **Logic:**
    1.  **Head Check:** If the node to be deleted is the head, the head pointer is moved to the next node.
    2.  **Next Link:** If `delNode` has a next node, its `prev` pointer is updated to skip `delNode`.
    3.  **Prev Link:** If `delNode` has a previous node, its `next` pointer is updated to skip `delNode`.
    4.  **Memory Release:** The memory occupied by `delNode` is released using `free()`.

### `void display(struct Node *head)`
* **Purpose:** Traverses the list from the head to the end and prints the data values.
* **Format:** It prints nodes linked by arrows (e.g., `10 <-> 15 <-> NULL`) to visualize the bidirectional nature.

## 3. Overview of Main Method

The `main()` function serves as the test driver for the implementation:

1.  **Initialization:** It manually allocates two initial nodes (`first` with data `10` and `second` with data `20`) and links them together to form the initial list (`10 <-> 20`).
2.  **Insertion Test:** It calls `insertAfter(first, 15)` to insert the value `15` between `10` and `20`.
    * *Resulting List:* `10 <-> 15 <-> 20`
3.  **Deletion Test:** It calls `deleteNode(&head, second)` to remove the node containing `20`.
    * *Resulting List:* `10 <-> 15`
4.  **Output:** After every operation, the `display()` function is called to show the current state of the list.

## 🛠️ How to Run

1.  **Compile the program:**
    ```bash
    gcc main.c -o dll_ops
    ```

2.  **Run the executable:**
    * **Windows:**
        ```bash
        dll_ops.exe
        ```
    * **Linux/Mac:**
        ```bash
        ./dll_ops
        ```

## 📸 Expected Output

![Output](https://github.com/Prayash64/dsa_assignment/blob/main/output/4.jpg?raw=true)

```text
Original Doubly Linked List:
10 <-> 20 <-> NULL

After inserting 15 after 10:
10 <-> 15 <-> 20 <-> NULL

After deleting 20:
10 <-> 15 <-> NULL