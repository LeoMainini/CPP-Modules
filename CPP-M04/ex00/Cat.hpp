/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:27:00 by leferrei          #+#    #+#             */
/*   Updated: 2023/03/07 16:17:21 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CAT_H	
# define CAT_H

# include "Animal.hpp"

class Cat: public Animal
{
	public:
		Cat( void );
		Cat( const Cat &a);
		Cat &operator= (const Cat &a);
		~Cat( void );
};

#endif
