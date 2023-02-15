/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:34:17 by leferrei          #+#    #+#             */
/*   Updated: 2023/02/15 17:22:08 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

class	Fixed
{
	private:
		int					integral;
		static const int	decimal = 8;

	public:
		Fixed( void );
		Fixed( const Fixed &n);
		Fixed &operator = (const Fixed &n);
		~Fixed( void );
		int	getRawBits( void ) const;
		void	setRawBits( int const raw);
};

#endif