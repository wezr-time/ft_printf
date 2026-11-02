*This project has been created as part of the 42 curriculum by `ymoubtas`.*

# ft_printf

## Description

The goal of **ft_printf** is to recreate a simplified version of the standard C `printf()` function.

The project introduces variadic functions in C and teaches how to handle a variable number of arguments. The function reads a format string, detects each conversion, prints the corresponding value, and returns the number of characters printed.

The mandatory conversions are:

| Conversion | Description |
| --- | --- |
| `%c` | Prints a character. |
| `%s` | Prints a string. |
| `%p` | Prints a pointer address in hexadecimal. |
| `%d` / `%i` | Prints a signed decimal number. |
| `%u` | Prints an unsigned decimal number. |
| `%x` | Prints a hexadecimal number using lowercase letters. |
| `%X` | Prints a hexadecimal number using uppercase letters. |
| `%%` | Prints a percent sign. |

## Instructions

### Compilation

Run the following command at the root of the repository:

```bash
make
```

This creates the static library `libftprintf.a`.

Other available Makefile commands:

```bash
make clean   # Remove object files
make fclean  # Remove object files and the library
make re      # Rebuild the library
```

### Usage

Include `ft_printf.h` in your C file and link the library when compiling:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, %s! Number: %d\n", "42", 42);
    return (0);
}
```

```bash
cc main.c -L. -lftprintf -o program
./program
```

## Algorithm and Data Structure

The function processes the format string from left to right, one character at a time.

1. If the current character is not `%`, it is printed as a normal character.
2. If the current character is `%`, the next character is checked to identify the conversion.
3. The corresponding argument is retrieved from the variadic argument list using `va_arg` with the appropriate type.
4. The value is printed using the helper function for that conversion.
5. The number of characters successfully printed is counted and returned.

The main type used to handle variadic arguments is `va_list`. It provides the information needed to access arguments passed after the named format parameter. The argument list is initialized with `va_start`, arguments are retrieved using `va_arg`, and `va_end` is called when argument processing is complete.

The function processes the format string one character at a time. When it encounters a % character, it checks the following character to identify the requested conversion and retrieves the corresponding argument.

For numeric conversions, the value is converted into digits using the appropriate base: 10 for decimal numbers and 16 for hexadecimal numbers. Negative signs are handled for signed conversions, while the hexadecimal alphabet determines whether letters are printed in lowercase or uppercase.

This approach allows the format string to be processed in a single pass, following the order of its characters. Using `va_list` avoids the need to manually store all the variadic arguments in a separate collection. Helper functions keep the conversion and printing logic organized and independent.

Finally, the implementation writes characters directly instead of recreating the original printf() buffer management, as required by the project.

## Resources

- [printf(3) — Linux manual page](https://man7.org/linux/man-pages/man3/printf.3.html)
- [stdarg(3) — Linux manual page](https://man7.org/linux/man-pages/man3/stdarg.3.html)
- [C variable arguments — cppreference](https://en.cppreference.com/w/c/variadic)
- The **ft_printf** subject provided by 42.

### AI Usage

AI tools were used as a learning aid to understand difficult concepts, discuss ideas and arguments, and design test cases. AI was not used to write or generate the project's code.
