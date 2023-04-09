# Data-Structures-Mini-Project-2

This C++ project implements Prim's algorithm to find the minimum spanning tree of an undirected, connected, weighted graph. It uses an adjacency list representation and provides functions to add edges to the graph and print the minimum spanning tree. The code is well-organized, properly indented, and includes comments for clarity.

![Screenshot 2023-04-09 195319](https://user-images.githubusercontent.com/23602136/230802301-f4b3b092-12ce-4ad8-9366-9d0dc020ddf6.png)

## Features

- Implements Prim's algorithm for finding the minimum spanning tree
- Uses adjacency list representation for efficient graph traversal
- Provides functions to add edges to the graph and print the minimum spanning tree
- Includes a main function for testing the implemented algorithm

## Team Members

- Noah Legault
- Devin St John
- Andrew Donate

## Project Structure

- Header Inclusions: The necessary C++ standard library headers are included, such as \<iostream>, \<list>, \<queue>, and \<vector>, which provide functionalities used in the implementation of Prim's algorithm.

- Graph Class Definition: The Graph class is defined, which represents the graph data structure. It has a private member variable vertices to store the number of vertices in the graph, and a pointer adj to represent the adjacency list of the graph. The class has a constructor Graph(int vertices) to allocate memory for the adjacency list, and member functions addEdge(int u, int v, int w) to add edges to the graph, and primMST() to find and print the minimum spanning tree of the graph using Prim's algorithm.

- Graph Class Implementation: The implementation of the Graph class member functions is provided in the same file after the class definition. The member functions addEdge() and primMST() are implemented using standard C++ syntax and algorithms, including the use of standard containers like std::list, std::vector, and std::priority_queue.

- Main Function: The main() function is the entry point of the program. It creates an instance of the Graph class with 9 vertices, adds edges to the graph using the addEdge() function, and calls the primMST() function to find and print the minimum spanning tree of the graph using Prim's algorithm.

## Rubric for Evaluation

- Correct implementation of Prim's algorithm
- Proper printing of the minimum spanning tree
- Overall code quality, including organization, indentation, and comments

## Project Deadline

The project submission deadline is April 10, 2023, with a presentation scheduled for the same date.

## Learning Objectives

- Develop skills in implementing graph traversal algorithms
- Learn how to find minimum spanning trees using Prim's algorithm
- Understand how to use adjacency lists to represent graphs

This project is aimed at helping learners improve their programming skills and gain a better understanding of graph algorithms and data structures.
