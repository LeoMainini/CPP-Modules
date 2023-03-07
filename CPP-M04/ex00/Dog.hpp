/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:27:06 by leferrei          #+#    #+#             */
/*   Updated: 2023/03/07 15:29:23 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	DOG_H	
# define DOG_H

# include "Animal.hpp"

class Dog: public Animal
{
	public:
		Dog( void );
		Dog( const Dog &a);
		Dog &operator= (const Dog &a);
		~Dog( void );
};

#endif
