/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yingzhan <yingzhan@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 11:05:53 by yingzhan          #+#    #+#             */
/*   Updated: 2025/11/07 11:49:52 by yingzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string humanName, Weapon& weaponName) : _weapon(weaponName), _name(humanName) {}

void	HumanA::attack()const
{
	std::cout << _name << " attacks with their ";
	std::cout << _weapon.getType() << std::endl;
}