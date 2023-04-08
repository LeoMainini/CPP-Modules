/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:27:06 by leferrei          #+#    #+#             */
/*   Updated: 2023/03/24 14:25:41 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	DOG_H	
# define DOG_H

# include "Animal.hpp"
# include "Brain.hpp"

class Dog: public Animal
{	
	private:
		Brain *bb;
	public:
		Dog( void );
		Dog( const Dog &a);
		Dog &operator= (const Dog &a);
		~Dog( void );
		void	makeSound( void ) const;
};

#endif
