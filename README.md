# intvec - A Simple Dynamic Vector for C

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

A lightweight, easy-to-use C library that provides a simple dynamic array (vector) for integers. This project was created to overcome the limitations of standard C arrays, offering automatic resizing and a clean API for common operations. It's an ideal tool for projects where the number of elements is not known at compile time.

This library provides both descriptive function names (e.g., `intvec_add`) and convenient short aliases (e.g., `iv_add`) for cleaner code.

## Features

* **Dynamic Resizing:** Automatically grows as you add elements.
* **Simple API:** A clean set of functions and short aliases for creating, adding, accessing, and destroying vectors.
* **Memory Safe:** Includes a dedicated function to properly free all allocated memory.
* **Portable:** Written in standard C (C99).

## Getting Started

### 1. Setup

Copy the `intvec.h` and `intvec.c` files into your project's source directory.

### 2. Include the Header

In your C file, include the header. This gives you access to all functions and aliases.
```c
#include "intvec.h"
```

### 3. Compile Your Project

When compiling with GCC, include both your source file and `intvec.c`:

```bash
gcc your_main_file.c intvec.c -o your_program_name
```

## Quick Example

This example uses the short aliases for more concise code.

```c
#include <stdio.h>
#include "intvec.h" // Include our library

int main() {
    // Use the IV_CREATE macro to declare and create the vector
    IV_CREATE(grades, 2);
    
    int current_grade;
    printf("Enter student grades (type -1 to finish):\n");

    // Read grades until the user enters -1
    while (scanf("%d", &current_grade) == 1 && current_grade != -1) {
        // Use the short alias 'iv_add'
        iv_add(grades, current_grade);
    }

    printf("\n--- Grade Report ---\n");
    int total_grades = iv_size(grades); // Use 'iv_size'

    if (total_grades > 0) {
        float sum = 0.0;
        for (int i = 0; i < total_grades; i++) {
            sum += iv_get(grades, i); // Use 'iv_get'
        }
        float average = sum / total_grades;
        printf("Average of %d grades: %.2f\n", total_grades, average);
    } else {
        printf("No grades were entered.\n");
    }

    // Use 'iv_destroy' to free memory
    iv_destroy(grades);
    printf("Memory freed. Program finished.\n");

    return 0;
}
```

## API Reference

The library provides the following functions and helper macros.

#### `IV_CREATE(vec_name, initial_capacity)`
A helper macro to declare and initialize a new `IntVector` pointer.
* **`vec_name`**: The name you want to give to your new vector variable.
* **`initial_capacity`**: The initial number of elements the vector can hold.

---

#### `iv_create(initial_capacity)`
*Alias for `IntVector* intvec_create(int initial_capacity)`*
<br>Creates a new, empty `IntVector` on the heap.
* **Returns**: A pointer to the newly created `IntVector`.

---

#### `iv_add(v, element)`
*Alias for `void intvec_add(IntVector* v, int element)`*
<br>Adds an element to the end of the vector `v`. Automatically doubles the capacity if full.

---

#### `iv_size(v)`
*Alias for `int intvec_get_size(IntVector* v)`*
<br>Returns the current number of elements in the vector `v`.

---

#### `iv_get(v, index)`
*Alias for `int intvec_get(IntVector* v, int index)`*
<br>Returns the element at a specific `index` (0-based) in the vector `v`.

---

#### `iv_destroy(v)`
*Alias for `void intvec_destroy(IntVector* v)`*
<br>Frees all memory associated with the vector `v`. **Must be called** when you are finished with the vector to prevent memory leaks.

## License

This project is licensed under the MIT License - see the `LICENSE` file for details.
