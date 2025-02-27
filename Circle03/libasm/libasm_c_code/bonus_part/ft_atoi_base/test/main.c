/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 01:39:28 by gipark            #+#    #+#             */
/*   Updated: 2021/01/09 03:09:27 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int main(void)
{
	char *s1 = "-12234ab65fsfs799";
	char *s2 = "---7B;f147483647wj";
	char *s3 = "-1010";
	printf("-12234ab65fsfs799(10): %d\n", ft_atoi_base(s1, "0123456789"));
	printf("---7B;f147483647wj(16): %d\n", ft_atoi_base(s2, "0123456789ABCDEF"));
	printf("-1010(2): %d\n", ft_atoi_base(s3, "01"));
	return (0);
}
