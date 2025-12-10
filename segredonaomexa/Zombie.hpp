/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-carv <jde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 18:12:46 by jde-carv          #+#    #+#             */
/*   Updated: 2025/12/10 18:14:08 by jde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Zombie {
	private:
		std::string name;
		
	public:
		Zombie(std::string name);
		~Zombie();

		std::string getName(void);
		void setName(std::string name);

		void announce( void );
};
