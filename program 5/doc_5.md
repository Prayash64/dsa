# Graph Traversal: BFS and DFS Implementation

This C program implements an **Undirected Graph** using an **Adjacency Matrix** representation. It demonstrates two fundamental graph traversal algorithms:
1.  **Breadth-First Search (BFS)** using a Queue.
2.  **Depth-First Search (DFS)** using a Stack (Iterative approach).

## 1. Data Structures Definition

The program uses three distinct structures to manage graph data and traversal logic.

### `struct Graph`
Represents the graph itself.
* **`int vertices`**: Stores the number of active vertices in the graph.
* **`int adjMatrix[MAX][MAX]`**: A 2D array (Adjacency Matrix) where `adjMatrix[i][j] = 1` indicates an edge exists between vertex `i` and vertex `j`, and `0` indicates no edge.

### `struct Queue` (For BFS)
A helper structure to manage the "First-In-First-Out" (FIFO) logic required for Breadth-First Search.
* **`int items[MAX]`**: Array to store queued vertices.
* **`int front`, `int rear`**: Pointers to track the beginning and end of the queue.

### `struct Stack` (For DFS)
A helper structure to manage the "Last-In-First-Out" (LIFO) logic required for the iterative Depth-First Search.
* **`int items[MAX]`**: Array to store stacked vertices.
* **`int top`**: Pointer to track the top element of the stack.

## 2. Function Descriptions

### Graph Operations
* **`void initGraph(Graph* g, int vertices)`**: Initializes the graph by setting the vertex count and filling the matrix with zeros.
* **`void addEdge(Graph* g, int v, int w)`**: Creates an undirected connection between `v` and `w`. It sets both `matrix[v][w]` and `matrix[w][v]` to 1.
* **`void displayMatrix(Graph* g)`**: Prints the current state of the adjacency matrix in a readable grid format.

### Traversal Algorithms
* **`void BFS(Graph* g, int startVertex)`**:
    * **Logic:** Uses a **Queue**. It starts at a vertex, visits it, and adds all its unvisited neighbors to the queue. It explores the graph layer by layer (neighbors first, then neighbors of neighbors).
* **`void DFS(Graph* g, int startVertex)`**:
    * **Logic:** Uses a **Stack**. It pushes the starting vertex, pops it to visit, and then pushes its unvisited neighbors.
    * *Note:* Neighbors are pushed in reverse order (high to low) so that they are popped and processed in ascending order (low to high).

### Helper Functions
* **Queue Helpers:** `enqueue`, `dequeue`, `isEmpty`, `initQueue`.
* **Stack Helpers:** `push`, `pop`, `isStackEmpty`, `initStack`.

## 3. Overview of Main Method

The `main()` function serves as a driver to demonstrate the functionality:
1.  **Setup:** Creates a graph with 5 vertices (0 to 4).
2.  **Edge Creation:** Manually adds edges to form a specific structure: `(0-1), (0-3), (1-2), (1-4), (2-3), (2-4)`.
3.  **Visualization:** Displays the Adjacency Matrix to show the internal representation.
4.  **Traversal Testing:**
    * Runs **BFS** starting from Vertex 0.
    * Runs **DFS** starting from Vertex 0.
    * Repeats the process starting from Vertex 2 to show how the traversal order changes based on the starting point.

## 🛠️ How to Run

1.  **Compile the program:**
    ```bash
    gcc main.c -o graph_traversal
    ```

2.  **Run the executable:**
    * **Windows:**
        ```bash
        graph_traversal.exe
        ```
    * **Linux/Mac:**
        ```bash
        ./graph_traversal
        ```

## 📸 Expected Output

```text
=== Undirected Graph Implementation ===
Creating graph with 5 vertices (0 to 4)

Adding edges...
Edges added: (0-1), (0-3), (1-2), (1-4), (2-3), (2-4)

Adjacency Matrix:
    0  1  2  3  4 
 0 [ 0 1 0 1 0]
 1 [ 1 0 1 0 1]
 2 [ 0 1 0 1 1]
 3 [ 1 0 1 0 0]
 4 [ 0 1 1 0 0]

BFS Traversal starting from vertex 0:
Order: 0 1 3 2 4 

DFS Traversal starting from vertex 0:
Order: 0 1 2 3 4 
...