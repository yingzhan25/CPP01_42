/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yingzhan <yingzhan@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 12:07:29 by yingzhan          #+#    #+#             */
/*   Updated: 2025/11/07 12:57:37 by yingzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string humanName) : _weapon(NULL), _name(humanName) {}

void	HumanB::setWeapon(Weapon& weaponName)
{
	_weapon = &weaponName;
}

//Only pointer can be used with if()
void	HumanB::attack()const
{
	if (_weapon)
	{
		std::cout << _name << " attacks with their ";
		std::cout << _weapon->getType() << std::endl;
	}
	else
		std::cout << _name << " attacks without weapon" << std::endl;
}