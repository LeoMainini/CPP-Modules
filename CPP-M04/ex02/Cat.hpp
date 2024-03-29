/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:27:00 by leferrei          #+#    #+#             */
/*   Updated: 2023/05/18 18:27:17 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CAT_H	
# define CAT_H

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat: public AAnimal
{
	private:
		Brain *bb;
		
	public:
		Cat( void );
		Cat( const Cat &a);
		Cat &operator= (const Cat &a);
		void	makeSound( void ) const;
		~Cat( void );
};

#endif
