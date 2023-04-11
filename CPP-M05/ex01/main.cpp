/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 21:24:38 by leferrei          #+#    #+#             */
/*   Updated: 2023/04/11 21:28:24 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"


int	main(void)
{
	Form form("Reginald Formilious III", 105);
	Bureaucrat bc("Bob \"the donk\" Donkey", 107);
	bc.signForm(form);
	while (bc.getGrade() > form.getReqGrade())
		bc.incGrade();
	bc.signForm(form);
	bc.signForm(form);
	
}