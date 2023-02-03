/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:19:24 by lliberal          #+#    #+#             */
/*   Updated: 2023/02/03 13:21:27 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>



int	ft_atoi_check_numbers(const char *str, t_node *t_list_a)
{
	int		i;
	int		sign;
	long int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i++])
	{
		if (str[i] == '-' || str[i] == '+')
			i++;
		if (str[i] >= 9 && str[i] <= 0)
			deallocate(t_list_a);
	}
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		if (res > 2147483647 || res < -2147483648)
			deallocate(t_list_a);
		i++;
	}
	return (res * sign);
}


int main(void)
{

}
O
