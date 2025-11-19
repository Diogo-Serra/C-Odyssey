#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void	*memcalloc(size_t nmemb, size_t size)
{
	void	*ptr;
	char	*p;
	size_t	total;

	if (size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	total = nmemb * size;
	ptr = malloc(total);
	if (!ptr)
		return (NULL);
	p = (char *)ptr;
	while (total--)
		*p++ = 0;
	return (ptr);
}

void	*memmcpy(void *dst, const void *src, size_t n)
{
	unsigned char			*d;
	const unsigned char		*s;

	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	while (n--)
		*d++ = *s++;
	return (dst);
}

char	*itoa(int n)
{
	char	arr[11];
	char	*out;
	long	nb;
	int		i;

	nb = (long)n;
	i = 10;
	if (nb < 0)
		nb *= -1;
	if (nb == 0)
		arr[--i] = '0';
	while (nb)
	{
		arr[--i] = (nb % 10) + '0';
		nb /= 10;
	}
	if (n < 0)
		arr[--i] = '-';
	out = (char *)memcalloc((10 - i) + 1, sizeof(char));
	if (!out)
		return (NULL);
	memmcpy(out, arr + i, 10 - i);
	return (out);
}

int	main(void)
{
	printf("%s\n", itoa(42));
}