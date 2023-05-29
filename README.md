# `0x11.c-printf` Project

This project, `0x11.c-printf`, was built by Phillipa Aidoo and Christabel Aidoo. It focuses on implementing a simplified version of the `printf` function in the C programming language.

## Overview

The `printf` function is a commonly used function in C that allows you to print formatted output to the console. It provides a flexible way to display data, such as strings, numbers, and other variables, with various formatting options.

The purpose of this project is to create a simplified version of the `printf` function from scratch. By implementing this function, we aim to demonstrate a deeper understanding of how the `printf` function works and improve our skills in C programming.

## Features

The `0x11.c-printf` project aims to provide the following features:

1. **Basic Data Types**: Support for printing basic data types, including integers, characters, and strings.
2. **Format Specifiers**: Implementation of common format specifiers, such as `%d` for integers, `%c` for characters, and `%s` for strings.
3. **Width and Precision**: Support for specifying the width and precision of printed values, similar to the original `printf` function.
4. **Modifiers**: Implementation of length modifiers, such as `l` for long integers.
5. **Error Handling**: Proper error handling for invalid format strings or unsupported format specifiers.

## Usage

To use the `0x11.c-printf` function, follow these steps:

1. Clone the `0x11.c-printf` repository to your local machine.
2. Open the project in your preferred C development environment.
3. Include the `printf.h` header file in your C source code.
4. Call the `printf` function in your code, providing the format string and any necessary arguments.

Here's an example of how to use the `printf` function:

```c
#include <stdio.h>
#include "printf.h"

int main() {
    int num = 10;
    printf("The value is: %d\n", num);
    return 0;
}

Acknowledgments
We would like to thank the C programming community and the developers of the original printf function for their valuable insights and contributions.

If you have any further questions or need assistance, please feel free to reach out.

Happy coding!

Phillipa Aidoo & Christabel Aidoo
