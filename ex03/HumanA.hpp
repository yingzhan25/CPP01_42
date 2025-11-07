/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yingzhan <yingzhan@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 10:56:49 by yingzhan          #+#    #+#             */
/*   Updated: 2025/11/07 11:49:46 by yingzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP
#include "Weapon.hpp"
#include <string>

class HumanA
{
	private:
		Weapon&	_weapon;
		std::string	_name;
	public:
		HumanA(std::string humanName, Weapon& weaponName);
		void	attack()const;
};

#endif