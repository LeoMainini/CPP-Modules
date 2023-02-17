/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:34:17 by leferrei          #+#    #+#             */
/*   Updated: 2023/02/17 20:04:12 by leferrei         ###   ########.fr       */
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
		//Cons/Destructors
		Fixed( void );
		Fixed( const Fixed &n);
		Fixed( const float num );
		Fixed( const int num );
		~Fixed( void );
		//Overrides
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
		//Logic functions
		int	getRawBits( void ) const;
		void	setRawBits( int const raw);
		int	toInt( void ) const;
		float toFloat( void ) const;
		//Static functions
		static Fixed	&min(Fixed &a, Fixed &b);
		const static Fixed	&min(const Fixed &a, const Fixed &b);
		static Fixed	&max(Fixed &a, Fixed &b);
		const static Fixed	&max(const Fixed &a, const Fixed &b);

};

#endif