/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:49:51 by JFikents          #+#    #+#             */
/*   Updated: 2024/08/29 18:24:49 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

static void	try_create_invalid_form(void)
{
	try{
		Form	invalid_form("Invalid Form", 0, 1);
		std::cout << invalid_form << "." << std::endl;
	}
	catch (const std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	try{
		Form	invalid_form("Invalid Form", 1, -1231);
		std::cout << invalid_form << "." << std::endl;
	}
	catch (const std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	try{
		Form	invalid_form("Invalid Form", 151, 1);
		std::cout << invalid_form << "." << std::endl;
	}
	catch (const std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	try{
		Form	invalid_form("Invalid Form", 1, 13123678);
		std::cout << invalid_form << "." << std::endl;
	}
	catch (const std::exception &e){
		std::cerr << e.what() << std::endl;
	}
}

int	main(void)
{
	Bureaucrat	high_bureaucrat("Boss John", 42);
	Bureaucrat	low_bureaucrat("Common Joe", 90);
	Form		stack_of_forms[4] = {
		Form("626-L&S", 42, 1),
		Form("2319-MI", 1, 150),
		Form("42-HGG", 91, 1),
		Form("237-S", 89, 150)
		};

	std::cout << std::endl;
	for (int i = 0; i < 4; i++)
		std::cout << stack_of_forms[i] << std::endl;
	std::cout << std::endl;
	std::cout << low_bureaucrat << "." << std::endl << std::endl;
	for (int i = 0; i < 4; i++)
		low_bureaucrat.signForm(stack_of_forms[i]);
	std::cout << std::endl;
	std::cout << high_bureaucrat << "." << std::endl << std::endl;
	for (int i = 0; i < 4; i++)
		high_bureaucrat.signForm(stack_of_forms[i]);
	std::cout << std::endl;
	try_create_invalid_form();
	std::cout << std::endl;
	for (int i = 0; i < 4; i++)
		std::cout << stack_of_forms[i] << std::endl;
	return (0);
}
