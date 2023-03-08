/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:55:58 by leferrei          #+#    #+#             */
/*   Updated: 2023/03/08 16:43:59 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ANIMAL_H	
# define ANIMAL_H

# include <iostream>

class Animal
{
	protected:
		std::string _type;
	public:
		Animal ( void );
		Animal ( const Animal &a);
		virtual Animal &operator= (const Animal &a);
		virtual ~Animal ( void );
		virtual void	makeSound( void ) const = 0;
		virtual const std::string &get_type( void ) const;
};

#endif
