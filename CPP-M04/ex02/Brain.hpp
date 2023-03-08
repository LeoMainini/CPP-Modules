/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:29:54 by leferrei          #+#    #+#             */
/*   Updated: 2023/03/07 17:29:06 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
# define BRAIN_H

# include <iostream>

class Brain
{
	public:
		std::string ideas[100];
		Brain( void );
		Brain( const Brain &b);
		Brain &operator = (const Brain &b);
		~Brain( void );

};

#endif