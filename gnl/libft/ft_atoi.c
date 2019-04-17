/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 21:28:05 by ckatelin          #+#    #+#             */
/*   Updated: 2019/04/08 16:06:45 by ckatelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static	int		check_pls_res(const char *str, int i, long int res, int mns)
{
	if (((str[i + 1] && ((res * 10 + str[i] - '0') * mns == 922337203685477580
					&& str[i + 1] > '7' && str[i + 1] <= '9'))
				|| ((res * 10 + str[i] - '0') * mns > 922337203685477580
					&& str[i + 1] >= '0' && str[i + 1] <= '9')))
		return (1);
	return (0);
}

static	int		check_mns_res(const char *str, int i, long int res, int mns)
{
	if ((res * 10 + str[i] - '0') * mns <= -922337203685477580 &&
			str[i + 1] > '7' && str[i + 1] <= '9')
		return (1);
	return (0);
}

long	int		ft_atoi(const char *str)
{
	int			mns;
	long int	res;
	int			i;

	i = 0;
	res = 0;
	mns = 1;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' ||
			str[i] == '\f' || str[i] == '\v' || str[i] == '\r')
		i++;
	if (str[i] == '-')
		mns = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (check_pls_res(str, i, res, mns))
			return (9223372036854775807);
		else if (check_mns_res(str, i, res, mns))
			return (-9223372036854775807 - 1);
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * mns);
}
