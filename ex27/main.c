/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 09:08:39 by ertrigna          #+#    #+#             */
/*   Updated: 2024/11/05 09:47:52 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *str, int fd)
{
	size_t	i;

	i = 0;
	while (str[i])
		ft_putchar_fd(str[i++], fd);
}

int	ft_show_file(char *av[])
{
	int		fd;
	int		ret;
	char	temp[1];

	ret = 1;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (0);
	while (ret > 0)
	{
		ret = read(fd, temp, 1);
		if (ret > 0)
			ft_putchar_fd(temp[0], 1);
	}
	if (ret == -1)
	{
		close(fd);
		return (0);
	}
	if (close(fd) == -1)
		return (0);
	return (1);
}

int	main(int ac, char *av[])
{
	if (ac == 1)
		ft_putstr_fd("File name missing.\n", 2);
	else if (ac == 2)
	{
		if (!ft_show_file(av))
			ft_putstr_fd("Cannot read file.\n", 2);
	}
	else
		ft_putstr_fd("Too many arguments.\n", 2);
	return (0);
}
