/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   learning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:15:31 by lliberal          #+#    #+#             */
/*   Updated: 2023/01/30 12:06:02 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

//o meu argc ja me oferece o tamanho da minha string
//

int main(int argc, char *argv[]) {
    int i, size, numbers[argc - 1];

    if (argc < 2) {
        printf("Usage: %s <number1> <number2> ...\n", argv[0]);
        return 1;
    }

    size = argc - 1;

    for (i = 0; i < size; i++) {
        numbers[i] = atoi(argv[i + 1]);
    }

    printf("The numbers entered are: ");
    for (i = 0; i < size; i++) {
        printf("%d ", numbers[i] + 1);
    }
    printf("\n");

    return 0;
}
