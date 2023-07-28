# _printf

Authors: Carlos Carrasquillo and Juan Silva

`_printf` is a simplified implementation of the `printf` function in C. It provides basic functionality to format and print data to the standard output (usually the console). This version of `_printf` supports `%c`, `%s`, and `%%` format specifiers.

## How to Use

To use the `_printf` function, include the `main.h` header file in your C program. Make sure to have the `_printf` function implementation available in your project.

```c
#include <stdio.h>
#include "main.h"

int main() {
    _printf("Hello, %s!\n", "world");
    _printf("A single character: %c\n", 'A');
    _printf("Percent sign: %%\n");

    return 0;
}
```

Compile your program and run it to see the formatted output.
use - gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c
run it with ./a.out

## Function Signature

```c
int _printf(const char *format, ...);
```

## Supported Format Specifiers

- `%c`: Prints a single character.
- `%s`: Prints a null-terminated string.
- `%%`: Prints a single percent sign.
- `&d`: Prints a signed integer.
- `&i`: Prints an unsigned integer.

## Return Value

The `_printf` function returns the total number of characters printed to the standard output.

## Limitations

This version of `_printf` has some limitations:
- It only supports `%c`, `%s`, and `%%` format specifiers.
- It does not handle more complex format specifiers like `%f`, `%x`, etc.
- Error handling for invalid format specifiers is not implemented.

## Authors

- Carlos Carrasquillo ([GitHub Profile](https://github.com/carlfrank))
- Juan Silva ([GitHub Profile](https://github.com/Mizuinu30))

## License

 This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
