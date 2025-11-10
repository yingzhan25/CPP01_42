/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yingzhan <yingzhan@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:33:38 by yingzhan          #+#    #+#             */
/*   Updated: 2025/11/10 15:49:42 by yingzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int	main(int ac, char **av)
{
	Harl	harl;

	if (ac != 2)
	{
		std::cout << "Invalid argument" <<std::endl;
		return (1);
	}
	harl.complain(av[1]);
	return (0);
}