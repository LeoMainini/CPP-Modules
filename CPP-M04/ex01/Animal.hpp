/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:55:58 by leferrei          #+#    #+#             */
/*   Updated: 2023/03/07 16:13:11 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ANIMAL_H	
# define ANIMAL_H

# include <iostream>

class Animal
{
	protected:
		std::string	_type;
		
	public:
		Animal( void );
		Animal( const Animal &a);
		Animal &operator= (const Animal &a);
		~Animal( void );
		void	makeSound( void ) const;
		const std::string &get_type( void ) const;
};


#endif
