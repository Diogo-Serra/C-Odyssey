int	ft_atoi(const char *s)
{
	int	number;
	int	sign;

	number = 0;
	sign = 1;
	while ((*s == 32) || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s++ == '-')
			sign *= -1;
	}
	while (*s >= '0' && *s <= '9')
		number = (number * 10) + (*s++ - '0');
	return (number * sign);
}