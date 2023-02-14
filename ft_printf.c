#include "ft_printf.h"

void ft_putchar(char c) {
	write(1, &c, 1);
}

void ft_print_nbr(long nbr, int *count) {

    if (nbr >= 10) {
        ft_print_nbr(nbr / 10, count);
        ft_print_nbr(nbr % 10, count);
    }
    else {
        ft_putchar(nbr + 48);
        *count += 1;
    }

}

void ft_to_hex(char qualifier, unsigned long format, int *count) {

    int remainder = 0, i = 1, j;
    char hexadecimalNumber[100];
    unsigned long quotient = 0;
    
    quotient = format;
        
    while (quotient != 0) {

        remainder = quotient % 16;
        if (remainder < 10)
            remainder += 48;
        else if (remainder >= 10 && qualifier == 'X')
            remainder += 55;
        else if ((remainder >= 10 && qualifier == 'x') || (remainder >= 10 && qualifier == 'p'))
            remainder += 87;

        hexadecimalNumber[i++] = remainder;
		quotient /= 16;
    }
    
    for (j = i - 1; j > 0; j--) {
        write(1, &hexadecimalNumber[j], 1);
        *count += 1;
    }  

}

int ft_printf(const char *format, ...) {
    
    int count = 0;
    va_list arg_ptr;
    va_start(arg_ptr, format);

    if ((!format) || (*format == '%' && !format[1]))
        return -1;
    
    for (int i = 0; format[i]; i++) {

        if (format[i] && format[i] != '%') {
            write(1, &format[i], 1);
            count++;
        }

        else if (format[i] == '%') {

            i++;

            if (format[i] == '%') {
                write(1, "%", 1);
                count++;
            }

            else if (format[i] == 'd' || format[i] == 'i') {
                
                int nbr = va_arg(arg_ptr, int);

                if (nbr == -2147483648) {
                    write(1, "-2", 2);
                    nbr = 147483648;
                    count += 2;
                }

                if (nbr < 0) {
                    nbr *= -1;
                    write(1, "-", 1);
                    count++;
                }
                
                ft_print_nbr(nbr, &count);
            }

            else if (format[i] == 'u') {     
                unsigned int uint = (unsigned int)va_arg(arg_ptr, unsigned int);
                ft_print_nbr(uint, &count);
            }

            else if (format[i] == 's') {

                char *str = (char *)va_arg(arg_ptr, char *);

                if (!str) {
                    write(1, "(null)\n", 7);
                    count += 7;
                    break ;
                }

                int ch = 0;
                while (str[ch]) {
                    write(1, &str[ch] , 1);
                    ch++;
                    count++;
                }
            }

            else if (format[i] == 'c') {
                char c = (char)va_arg(arg_ptr, int);
                write(1, &c, 1);
                count++;
            }

            else if (format[i] == 'p') {

                void *p = va_arg(arg_ptr, void *);

                if (p == NULL) {
                    write(1, "(nil)", 5);
                    count += 5;
                }
                else {
                    write(1, "0x", 2);
                    count += 2;
                    char qualifier = 'p';
                    ft_to_hex(qualifier, (uintptr_t)p, &count);
                }
            }

            else if (format[i] == 'x' || format[i] == 'X') {

                unsigned long x = (unsigned long)va_arg(arg_ptr, unsigned int);
                char qualifier;

                if (format[i] == 'x')
                    qualifier = 'x';
                else
                    qualifier = 'X';
                ft_to_hex(qualifier, x, &count);
            }

            else {
                write(1, "%", 1);
                count++;
                i++;
            }

        }
    }

    va_end(arg_ptr);

    return count;

}