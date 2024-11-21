#include "ft_printf.h"
#include <limits.h> // Include the <limits.h> header file
#include <stdio.h>
int main()
{
	// printf("|%0d|\n",4);
	printf("%i\n",ft_printf(" |%05u| ", -15));
	printf("%i\n",printf(" |%05u| ", -15));
	// printf(" |%05u| ", -15);
	// printf("|%0d|\n",4);
	// printf("|%0d|\n",4);
}
