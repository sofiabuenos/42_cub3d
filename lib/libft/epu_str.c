/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epu_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrodrig <shrodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:44:03 by sheila            #+#    #+#             */
/*   Updated: 2025/02/09 18:08:13 by shrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	is_space(char str)
{
	if (str == ' ' || (str >= 9 && str <= 13))
		return (true);
	return (false);
}

char	*eup_str(char *str)
{
	bool	flag;
	char	*temp;
	int		j;

	temp = ft_calloc(ft_strlen(str), sizeof(char));
	flag = false;
	j = 0;
	if (!temp)
		return (NULL);
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	while (*str)
	{
		flag = is_space(*str);
		if (!is_space(*str))
		{
			if (flag)
				temp[j++] = ' ';
			flag = false;
			temp[j] = *str;
			j++;
		}
		str++;
	}
	return (temp);
}

/*int main ()
{
	char *av = "   hello world    	 ";

	printf("%s\n", eup_str(av));
	return (0);
}*/