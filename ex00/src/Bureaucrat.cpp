/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:01:46 by JFikents          #+#    #+#             */
/*   Updated: 2024/08/29 16:12:17 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name)
{
	if (grade < 1 || grade > 150)
		std::cerr << "Error Creating " << this->getName() << ", " << std::flush;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &other):
	_name(other._name),
	_grade(other._grade)
{}

Bureaucrat	&Bureaucrat::operator =(Bureaucrat const &other)
{
	if (this == &other)
		return (*this);
	this->_grade = other._grade;
	return (*this);
}

const std::string	&Bureaucrat::getName(void) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void	Bureaucrat::promoteBureaucrat(void)
{
	if (this->_grade == 1)
	{
		std::cerr << "Error Promoting " << *this << ", " << std::flush;
		throw Bureaucrat::GradeTooHighException();
	}
	this->_grade--;
}

void	Bureaucrat::demoteBureaucrat(void)
{
	if (this->_grade == 150)
	{
		std::cerr << "Error Demoting " << *this << ", " << std::flush;
		throw Bureaucrat::GradeTooLowException();
	}
	this->_grade++;
}

std::ostream	&operator <<(std::ostream &out, Bureaucrat const &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (out);
}
