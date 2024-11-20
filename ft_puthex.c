
#include "ft_printf.h"

static int	ft_check(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		j = i + 1;
		if (base[i] == ' ' || (base[i] >= 9 && base[i] <= 13))
			return (1);
		if (base[i] == '+' || base[i] == '-')
			return (1);
		while (base[j])
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (i);
}

static int	ft_printr(size_t num, char *base, size_t len)
{
	int count = 0;
	if (num < 0)
	{
		count +=ft_putchar('-');
		num *= (-1);
		count +=ft_printr(num, base, len);
	}
	else if (num >= len)
	{
		count +=ft_printr(num / len, base, len);
		count +=ft_printr(num % len, base, len);
	}
	else
		count +=ft_putchar(base[num]);
	return count ;
}

int	ft_puthex(size_t nbr, char *base)
{
	size_t	i;

	i = ft_check(base);
	if (i <= 1)
		return 0;
	return (ft_printr(nbr, base, i));
}
