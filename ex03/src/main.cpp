/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:49:51 by JFikents          #+#    #+#             */
/*   Updated: 2024/08/30 15:02:15 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include <iostream>

int	main(void)
{
	Bureaucrat	ceo_bureaucrat("The CEO", 1);
	Intern		intern;
	AForm		*form[7];

	form[0] = intern.makeForm("shrubbery creation", "the CEO's home");
	form[1] = intern.makeForm("robotomy request", "Marvin");
	form[2] = intern.makeForm("presidential pardon", "Arthur");
	form[3] = intern.makeForm("ShrUbbEry cReaTion", "the CEO's Miami home");
	form[4] = intern.makeForm("RobOtomY Request", "Bender");
	form[5] = intern.makeForm("PrEsidentIal Pardon", "the CEO's daughter");
	form[6] = intern.makeForm("Unknown Form", "Unknown Target");

	std::cout << std::endl;
	for (int i = 0; i < 7; i++)
	{
		if (form[i] != nullptr)
		{
			ceo_bureaucrat.signForm(*form[i]);
			ceo_bureaucrat.executeForm(*form[i]);
			delete form[i];
			std::cout << std::endl;
		}
	}
	return (0);
}
