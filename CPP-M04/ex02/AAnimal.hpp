/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:55:58 by leferrei          #+#    #+#             */
/*   Updated: 2023/03/08 16:43:59 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	AAnimal_H	
# define AAnimal_H

# include <iostream>

class AAnimal
{
	protected:
		std::string _type;
	public:
		AAnimal ( void );
		AAnimal ( const AAnimal &a);
		virtual AAnimal &operator= (const AAnimal &a);
		virtual ~AAnimal ( void );
		virtual void	makeSound( void ) const = 0;
		virtual const std::string &get_type( void ) const;
};

#endif
