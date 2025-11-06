/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yingzhan <yingzhan@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:31:57 by yingzhan          #+#    #+#             */
/*   Updated: 2025/11/06 13:06:42 by yingzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	stackZombie("foo");

	stackZombie.announce();
	Zombie*	heapZombie = newZombie("foo2");
	heapZombie->announce();
	//destroy foo1
	randomChump("foo1");
	//destroy foo2
	delete heapZombie;
	//destroy foo
	return (0);
}