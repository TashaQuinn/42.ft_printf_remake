#include "ft_printf.h"

void ft_print_char(char c, int *count) {

    write(1, &c, 1);
    *count += 1;
}

void ft_print_nbr(long nbr, int *count, char qualifier) {

    if (qualifier == 'd') {

        if (nbr == -2147483648) {
            write(1, "-2", 2);
            *count += 2;
            nbr = 147483648;
        }

        if (nbr < 0) {
            nbr *= -1;
            ft_print_char('-', count);
        }
    }

    if (nbr >= 10) {
        ft_print_nbr(nbr / 10, count, qualifier);
        ft_print_nbr(nbr % 10, count, qualifier);
    }
    else
        ft_print_char(nbr + 48, count);

}

void ft_print_str(char *str, int *count) {

    if (!str) {
        ft_print_str("(null)", count);
        return ;
    }

    for (int ch = 0; str[ch]; ch++)
        ft_print_char(str[ch], count);

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
    
    for (j = i - 1; j > 0; j--) 
        ft_print_char(hexadecimalNumber[j], count);
}

void ft_print_ptr(void *p, int *count) {

    if (p == NULL)
        ft_print_str("(nil)", count);
    else {
        ft_print_str("0x", count);
        char qualifier = 'p';
        ft_to_hex(qualifier, (uintptr_t)p, count);
    }
}

void ft_print_hex(unsigned int hex, int *count, const char *format) {

    char qualifier = (*format == 'x') ? 'x' : 'X';
                    
    ft_to_hex(qualifier, hex, count);

}

int ft_printf(const char *format, ...) {
    
    int count = 0;
    va_list arg_ptr;
    va_start(arg_ptr, format);

    if ((!format) || (*format == '%' && !format[1]))
        return -1;
    
    for (int i = 0; format[i]; i++) {

        if (format[i] && format[i] != '%')
            ft_print_char(format[i], &count);

        else if (format[i] == '%') {

            i++;

            if (format[i] == '%')
                ft_print_char('%', &count);

            else if (format[i] == 'd' || format[i] == 'i') {
                char qualifier = 'd';
                ft_print_nbr(va_arg(arg_ptr, int), &count, qualifier);
            }

            else if (format[i] == 'u') {     
                char qualifier = 'u';
                ft_print_nbr((unsigned int)va_arg(arg_ptr, unsigned int), &count, qualifier);
            }

            else if (format[i] == 's')
                ft_print_str((char *)va_arg(arg_ptr, char *), &count);

            else if (format[i] == 'c')
                ft_print_char((char)va_arg(arg_ptr, int), &count);

            else if (format[i] == 'p')
                ft_print_ptr(va_arg(arg_ptr, void *), &count);

            else if (format[i] == 'x' || format[i] == 'X')
                ft_print_hex((unsigned long)va_arg(arg_ptr, unsigned int), &count, &format[i]);

            else {
                ft_print_char('%', &count);
                i++;
            }
        }
    }

    va_end(arg_ptr);
    return count;

}