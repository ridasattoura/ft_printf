#include "ft_printf.h"
int main()
{

	close(1);
	int i =ft_printf("1234") + 48;
	write(2,&i,1);
	
}
