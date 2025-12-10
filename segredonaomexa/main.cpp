/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-carv <jde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 18:19:19 by jde-carv          #+#    #+#             */
/*   Updated: 2025/12/10 18:29:25 by jde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.cpp"

void randomChump(std::string name);
Zombie *newZombie(std::string name);

int main() {
	Zombie *zombie1 = newZombie("jorginho");
	zombie1->announce();
	zombie1->setName("jorjao");
	zombie1->announce();

	randomChump("little chump");
	delete zombie1;
}