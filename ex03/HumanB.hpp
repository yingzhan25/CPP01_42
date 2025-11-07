/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yingzhan <yingzhan@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 11:59:53 by yingzhan          #+#    #+#             */
/*   Updated: 2025/11/07 12:46:18 by yingzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP
#include "Weapon.hpp"
#include <string>

class HumanB
{
	private:
		Weapon*	_weapon;
		std::string	_name;
	public:
		HumanB(std::string humanName);
		void	setWeapon(Weapon& weaponName);
		void	attack()const;
};

#endif