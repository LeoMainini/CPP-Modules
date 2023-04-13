/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 21:24:38 by leferrei          #+#    #+#             */
/*   Updated: 2023/04/13 18:19:21 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

using namespace std;

int	main(void)
{
	ShrubberyCreationForm form("Reginald Formilious IIIs home");
	RobotomyRequestForm robo("Roboticus Arnelious Jr.");
	PresidentialPardonForm	bush("George HW Bush in Epsteins island");
	Bureaucrat bc("Bob \"the donk\" Donkey", 107);
	bc.signForm(form);
	form.execute(bc);
	bc.setGrade(48);
	bc.signForm(robo);
	try {
		robo.execute(bc);
	}
	catch (AForm::GradeTooLowException &e){
		cout << e.text() << endl;
		bc.setGrade(20);
	}
	robo.execute(bc);
	bc.setGrade(4);
	bc.signForm(bush);
	bush.execute(bc);
}