/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:49:51 by JFikents          #+#    #+#             */
/*   Updated: 2024/08/29 16:40:30 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

static void	try_create_bureaucrat_with_invalid_grade(void)
{
	try
	{
		Bureaucrat	too_high_bureaucrat("CEO of CEO John", 0);
		std::cout << too_high_bureaucrat << "." << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat	too_low_bureaucrat("Assistent of Assistent of freelancer John", 151);
		std::cout << too_low_bureaucrat << "." << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

static void	try_change_grade_of_bureaucrat(Bureaucrat &high_bureaucrat,
	Bureaucrat &low_bureaucrat)
{
	try
	{
		low_bureaucrat.promoteBureaucrat();
		std::cout << low_bureaucrat << "." << std::endl;
		low_bureaucrat.demoteBureaucrat();
		std::cout << low_bureaucrat << "." << std::endl;
		low_bureaucrat.demoteBureaucrat();
	}
	catch (const Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		high_bureaucrat.demoteBureaucrat();
		std::cout << high_bureaucrat << "." << std::endl;
		high_bureaucrat.promoteBureaucrat();
		std::cout << high_bureaucrat << "." << std::endl;
		high_bureaucrat.promoteBureaucrat();
	}
	catch (const Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int	main(void)
{
	Bureaucrat	high_bureaucrat("Boss John", 1);
	std::cout << high_bureaucrat << "." << std::endl;
	Bureaucrat	low_bureaucrat("Common worker John", 150);
	std::cout << low_bureaucrat <<  "." << std::endl;

	try_create_bureaucrat_with_invalid_grade();
	try_change_grade_of_bureaucrat(high_bureaucrat, low_bureaucrat);
	return (0);
}
