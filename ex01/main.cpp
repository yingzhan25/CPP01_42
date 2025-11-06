/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yingzhan <yingzhan@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:30:21 by yingzhan          #+#    #+#             */
/*   Updated: 2025/11/06 15:51:33 by yingzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	int	N = 5;
	Zombie* horde = zombieHorde(N, "foo");
	if (!horde)
		return (1);
	for (int i = 0; i < N; i++)
		horde[i].announce();
	delete[] horde;
	return (0);
}