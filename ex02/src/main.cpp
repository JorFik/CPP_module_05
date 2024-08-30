/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:49:51 by JFikents          #+#    #+#             */
/*   Updated: 2024/08/30 13:57:39 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include <iostream>

#define HEADER_NO_SIGN_EXECUTE " ----------------------- Try executing without signing ----------------------- "
#define HEADER_SIGN_ALL_FORMS " --------------------------- Try to sign all forms --------------------------- "
#define HEADER_EXECUTE_ALL_FORMS " -------------------------- Try executing all forms -------------------------- "

int	main(void)
{
	Bureaucrat	ceo_bureaucrat("CEO", 1);
	Bureaucrat	high_bureaucrat("Boss John", 42);
	Bureaucrat	low_bureaucrat("Common Joe", 150);
	AForm		*stack_of_forms[3] = {
		new ShrubberyCreationForm("CEO's Home"),
		new PresidentialPardonForm("Joe"),
		new RobotomyRequestForm("Joe")
	};

	std::cout << ceo_bureaucrat << std::endl;
	std::cout << high_bureaucrat << std::endl;
	std::cout << low_bureaucrat << std::endl;
	std::cout << std::endl;
	std::cout << HEADER_NO_SIGN_EXECUTE << std::endl << std::endl;
	for (int i = 0; i < 3; i++)
	{
		std::cout << *stack_of_forms[i] << std::endl;
		ceo_bureaucrat.executeForm(*stack_of_forms[i]);
		high_bureaucrat.executeForm(*stack_of_forms[i]);
		low_bureaucrat.executeForm(*stack_of_forms[i]);
		std::cout << std::endl;
	}
	std::cout << HEADER_SIGN_ALL_FORMS << std::endl << std::endl;
	for (int i = 0; i < 3; i++)
	{
		low_bureaucrat.signForm(*stack_of_forms[i]);
		high_bureaucrat.signForm(*stack_of_forms[i]);
		ceo_bureaucrat.signForm(*stack_of_forms[i]);
		std::cout << std::endl;
	}
	std::cout << HEADER_EXECUTE_ALL_FORMS << std::endl;
	for (int i = 0; i < 3; i++)
	{
		std::cout << std::endl;
		std::cout << *stack_of_forms[i] << std::endl;
		std::cout << std::endl;
		low_bureaucrat.executeForm(*stack_of_forms[i]);
		high_bureaucrat.executeForm(*stack_of_forms[i]);
		ceo_bureaucrat.executeForm(*stack_of_forms[i]);
		std::cout << std::endl;
	}
	for (int i = 0; i < 3; i++)
		delete stack_of_forms[i];
	return (0);
}
