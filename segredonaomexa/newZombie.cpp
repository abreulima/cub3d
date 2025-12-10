/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-carv <jde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 18:12:34 by jde-carv          #+#    #+#             */
/*   Updated: 2025/12/10 18:12:36 by jde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.cpp"

Zombie *newZombie(std::string name) {
	Zombie *zombie = new Zombie("");
	zombie->setName(name);
	zombie->announce();
	return (zombie);
}