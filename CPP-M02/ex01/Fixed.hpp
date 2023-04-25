/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:34:17 by leferrei          #+#    #+#             */
/*   Updated: 2023/04/25 19:48:43 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H
# include <iostream>

class	Fixed
{
	private:
		int					integral;
		static const int	decimal = 8;

	public:
		Fixed( void );
		Fixed( const Fixed &n);
		Fixed( const float num );
		Fixed( const int num );
		Fixed &operator = (const Fixed &n);
		~Fixed( void );
		int	getRawBits( void ) const;
		void	setRawBits( int const raw);
		int	toInt( void ) const;
		float toFloat( void ) const;
};
	
	std::ostream &operator << (std::ostream &out, const Fixed &n);
#endif