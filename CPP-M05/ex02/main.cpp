/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 21:24:38 by leferrei          #+#    #+#             */
/*   Updated: 2023/04/12 21:24:08 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"


int	main(void)
{
	ShrubberyCreationForm form("Reginald Formilious IIIs home");
	Bureaucrat bc("Bob \"the donk\" Donkey", 107);
	bc.signForm(form);
	form.execute(bc);
	// bc.signForm(form);
	// while (bc.getGrade() > form.getReqGrade())
	// 	bc.incGrade();
	// bc.signForm(form);
	// bc.signForm(form);
	
}