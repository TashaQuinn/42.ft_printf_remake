#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h> // write
# include <stdarg.h> // va_list, va_start, va_end
# include <stdio.h> // printf
# include <stdint.h> // uintptr
# include <limits.h> // INT_MAX etc.

int	ft_printf(const char *format, ...);

#endif