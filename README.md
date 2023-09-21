# Stack and Queue Implementation in C

This C project provides implementations of two fundamental data structures: Stacks and Queues. Stacks are based on the LIFO (Last-In-First-Out) principle, while Queues are based on the FIFO (First-In-First-Out) principle. These data structures are essential for various applications in computer science and programming.

## Table of Contents

- [Overview](#overview)
- [Stacks](#stacks)
  - [LIFO (Last-In-First-Out)](#lifo-last-in-first-out)
  - [Stack Operations](#stack-operations)
- [Queues](#queues)
  - [FIFO (First-In-First-Out)](#fifo-first-in-first-out)
  - [Queue Operations](#queue-operations)
- [Brainfuck](#brainfuck)
- [Authors](#authors)
- [Feedback](#feedback)
- [Links](#links)
- [Badges](#badges)

## Overview

In computer science, a Stack is a linear data structure that follows the LIFO (Last-In-First-Out) principle. It means that the element added last will be the first one to be removed. Stacks are often used for managing function calls, undo operations, and in algorithms like depth-first search.

On the other hand, a Queue is a linear data structure that follows the FIFO (First-In-First-Out) principle. It means that the element added first will be the first one to be removed. Queues are commonly used in task scheduling, breadth-first search, and more.



### FIFO (First-In-First-Out)

A Queue operates based on the FIFO principle, which means that the first element enqueued is the first one to be dequeued.

## Stacks

### Stack Operations

This project provides the following stack operations:

- `push(item)`: Adds an item to the top of the stack.
- `pop()`: Removes and returns the item from the top of the stack.
- `peek()`: Returns the item at the top of the stack without removing it.
- `isEmpty()`: Checks if the stack is empty.

## Queues

### Queue Operations

This project provides the following queue operations:

- `enqueue(item)`: Adds an item to the rear of the queue.
- `dequeue()`: Removes and returns the item from the front of the queue.
- `peek()`: Returns the item at the front of the queue without removing it.
- `isEmpty()`: Checks if the queue is empty.


## `Monty` executes the following opcodes:


| Opcode | Description |
| -------- | ----------- |
| `push` | Pushes an element to the stack |
| `pall` | Prints all the values on the stack |
| `pint` | Prints the value at the top of the stack |
| `pop` | Removes the top element of the stack |
| `swap` | Swaps the top two elements of the stack |
| `queue` | Sets the format of the data to a queue (FIFO) |
| `stack` | Sets the format of the data to a stack (LIFO) |
| `nop` | Doesn't do anything |
| `add` | Adds the top two elements of the stack |
| `sub` | Subtracts the top element of the stack from the second top element of the stack |
| `mul` | Multiplies the second top element of the stack with the top element of the stack |
| `div` | Divides the second top element of the stack by the top element of the stack |
| `mod` | Computes the rest of the division of the second top element of the stack by the top element of the stack |
| `pchar` | Prints the char at the top of the stack |
| `pstr` | Prints the string starting at the top of the stack |
| `rotl` | Rotates the stack to the top |
| `rotr` | Rotates the stack to the bottom |

## Brainfuck

`Brainfuck` (often abbreviated as BF) is an esoteric programming language created in 1993 by Urban Müller. It is known for its extreme minimalism and is designed to be a challenging and quirky language with just a small set of commands. Brainfuck is intentionally difficult to write and read, making it more of a novelty or educational programming language rather than a practical one.

Here are the key features of Brainfuck:

- `Minimalistic Commands:` Brainfuck uses only eight simple commands, which are represented by single characters: +, -, >, <, [, ], ., and ,.
- `Tape-Based Memory:` Brainfuck operates on an array of memory cells, each initially set to zero. A data pointer points to the current cell.

- `commands:`
```
+ and -: Increment and decrement the value in the current memory cell, respectively.
```
```
> and <: Move the data pointer to the right or left, changing the current memory cell.
```
```
[ and ]: Conditional loops. While the current memory cell is nonzero, the code between [ and ] is executed.
```
```
.: Output the character in the current memory cell as a character.
```
```
,: Input a character and store its ASCII value in the current memory cell.
```

- `Limited Memory:` The memory in Brainfuck is typically quite limited, consisting of a fixed number of cells (usually 30,000) and only capable of holding small integer values.

- `No I/O or Arithmetic Operations:` Brainfuck lacks built-in arithmetic operators or I/O functions. It relies on the programmer to implement any complex logic.

- `Whitespace Ignored:` Any characters other than the eight Brainfuck commands are treated as whitespace and are ignored by the interpreter.

## Authors

- [@M-ESSALHI](https://www.github.com/)
- [@oy](https://www.github.com/)

## Feedback

If you have any feedback, please reach out to us at salhy@oy..


## Links
[![portfolio](https://img.shields.io/badge/my_portfolio-000?style=for-the-badge&logo=ko-fi&logoColor=white)](https://.com/)
[![linkedin](https://img.shields.io/badge/linkedin-0A66C2?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/)
[![twitter](https://img.shields.io/badge/twitter-1DA1F2?style=for-the-badge&logo=twitter&logoColor=white)](https://twitter.com/)

## Badges

Add badges from somewhere like: [shields.io](https://shields.io/)

[![MIT License](https://img.shields.io/badge/License-MIT-green.svg)](https://choosealicense.com/licenses/mit/)
[![GPLv3 License](https://img.shields.io/badge/License-GPL%20v3-yellow.svg)](https://opensource.org/licenses/)
[![AGPL License](https://img.shields.io/badge/license-AGPL-blue.svg)](http://www.gnu.org/licenses/agpl-3.0)