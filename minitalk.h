#ifndef MINITALK_H
# define MINITALK_H
# include <stdlib.h>
char	*ft_convert_base(char *nbr, unsigned int *size);
int		ft_atoi(const char *str);
void	ft_putchar(char c);
void	ft_putnbr_base(long long int nb, char *base);
char	*ft_itoa(int n);
void	ft_bzero(void *s, size_t n);

#endif
