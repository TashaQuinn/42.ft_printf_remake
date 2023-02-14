#include "ft_printf.h"

int main() {  

    ft_printf("%s\n", "DECIMAL NUMBER");
    ft_printf("ft_printf: %d\n", 42);
    printf("printf   : %d\n", 42);
    ft_printf("ft_printf: %d\n", -42);
    printf("printf   : %d\n", -42);
    ft_printf("ft_printf: %d\n", INT_MAX);
    printf("printf   : %d\n", INT_MAX);
    int i = ft_printf("ft_printf: %d\n", INT_MIN);
    int j = printf("printf   : %d\n", INT_MIN);
    printf("check count (d int_min): %d (custom) and %d (original)\n\n", i, j);

    ft_printf("%s\n", "INT IN BASE 10");
    ft_printf("ft_printf: %i\n", 42);
    printf("printf   : %i\n", 42);
    ft_printf("ft_printf: %i\n", -42);
    printf("printf   : %i\n", -42);
    ft_printf("ft_printf: %i\n", INT_MAX);
    printf("printf   : %i\n", INT_MAX);
    int a = ft_printf("ft_printf: %i\n", INT_MIN);
    int b = printf("printf   : %i\n", INT_MIN);
    printf("check count (i int_min): %d (custom) and %d (original)\n\n", a, b);
    
    ft_printf("%s\n", "UNSIGNED DECIMAL NUMBER");
    ft_printf("ft_printf: %u\n", 42);
    printf("printf   : %u\n", 42);
    int c = ft_printf("ft_printf: %u\n", UINT_MAX);
    int d = printf("printf   : %u\n", UINT_MAX);
    printf("check count (uint_max): %d (custom) and %d (original)\n\n", c, d);

    ft_printf("%s \n", "CHAR");
    ft_printf("ft_printf: %c\n", 'E');
    printf("printf   : %c\n\n", 'E');

    char *str = NULL;
    ft_printf("%s\n", "STRING");
    int f = ft_printf("ft_printf: %s\n", "Ecole");
    int g = printf("printf   : %s\n", "Ecole");
    printf("check count (str): %d (custom) and %d (original)\n", f, g);
    int k = ft_printf("ft_printf: %s\n", str);
    int n = printf("printf   : %s\n", str);
    printf("check count (NULL str): %d (custom) and %d (original)\n\n", k, n);

    ft_printf("%s\n", "HEXADECIMAL NUMBER UPPERCASE");
    int l = ft_printf("ft_printf: %X\n", 42);
    int m = printf("printf   : %X\n", 42);
    printf("check count (hex upper): %d (custom) and %d (original)\n\n", l, m);


    ft_printf("%s\n", "HEXADECIMAL NUMBER LOWERCASE");
    ft_printf("ft_printf: %x\n", 42);
    printf("printf   : %x\n\n", 42);

    void *ptr_nill = NULL;
    void *ptr = "Ecole 42";
    ft_printf("%s\n", "POINTER");
    int r = ft_printf("ft_printf: %p\n", ptr);
    int t = printf("printf   : %p\n", ptr);
    printf("check count (ptr): %d (custom) and %d (original)\n", r, t);
    int p = ft_printf("ft_printf: %p\n", ptr_nill);
    int q = printf("printf   : %p\n", ptr_nill);
    printf("check count (NULL ptr): %d (custom) and %d (original)\n\n", p, q);

    ft_printf("%s\n", "PERCENT SIGN");
    ft_printf("ft_printf: %%\n");
    printf("printf   : %%\n\n");

    char *string = "Ecole";
    char ch = 'E';
    int integer = 42;
    void *pointer = "Hello world!";
    ft_printf("%s\n", "MIXED");
    int w = ft_printf("ft_printf: %c means %s %i, my 100%% love <3 It's address in my heart: %p\n", ch, string, integer, pointer);
    int v = printf("printf   : %c means %s %i, my 100%% love <3 It's address in my heart: %p\n", ch, string, integer, pointer);
    printf("check count (mixed): %d (custom) and %d (original)\n", w, v);

    return 0;

}