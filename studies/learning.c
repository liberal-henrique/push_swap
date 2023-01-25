/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   learning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:15:31 by lliberal          #+#    #+#             */
/*   Updated: 2023/01/23 10:57:12 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

//learning multidimensional array

int	main(int argc, char *argv[])
{
	// char numbers[][3] = {
	// 	{1, 2, 4},
	// 	{6, 7, 8},
	// 	{15, 3, 5},
	// 	{17, 5, 22},
	// 	{12, 1, 2},
	// };
	int i , j;
	int	**arr;

	arr = malloc(sizeof(int *) * 3);
	if (!arr)
		return (0);
	for (int a = 0; a < 3; a++)
	{
		arr[a] = malloc(sizeof(int) * 3);
	}
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			printf("%d", arr[i][j]);
		}
		printf("\n");
	}
}
