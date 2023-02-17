/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:34:17 by leferrei          #+#    #+#             */
/*   Updated: 2023/02/17 16:17:33 by leferrei         ###   ########.fr       */
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
		Fixed	&operator = (const Fixed &n);
		bool	operator < (const Fixed &n);
		bool	operator > (const Fixed &n);
		bool	operator <= (const Fixed &n);
		bool	operator >= (const Fixed &n);
		bool	operator == (const Fixed &n);
		bool	operator != (const Fixed &n);
		float	operator + (const Fixed &n);
		float	operator - (const Fixed &n);
		float	operator * (const Fixed &n);
		float	operator / (const Fixed &n);
		Fixed	&operator++ ( void );
		Fixed	operator++ ( int );
		Fixed	&operator-- ( void );
		Fixed	operator-- ( int );
		friend std::ostream &operator << (std::ostream &out, const Fixed &n);
		~Fixed( void );
		int	getRawBits( void ) const;
		void	setRawBits( int const raw);
		int	toInt( void ) const;
		float toFloat( void ) const;
};

#endif