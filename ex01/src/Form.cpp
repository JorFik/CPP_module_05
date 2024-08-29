/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 17:21:56 by JFikents          #+#    #+#             */
/*   Updated: 2024/08/29 18:33:46 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

static bool	isGradeValid(int grade)
{
	return (grade >= 1 && grade <= 150);
}

Form::Form(std::string const name, int sign_grade, int exec_grade):
	_name(name),
	_signed(false),
	_sign_grade(sign_grade),
	_exec_grade(exec_grade)
{
	if (isGradeValid(sign_grade) == false || isGradeValid(exec_grade) == false)
		std::cerr << "Error Creating " << this->getName() << ", " << std::flush;
	if (isGradeValid(sign_grade) == false)
		std::cerr << "Sign " << std::flush;
	if (isGradeValid(exec_grade) == false)
		std::cerr << "Exec " << std::flush;
	if (sign_grade < 1 || exec_grade < 1)
		throw Form::GradeTooHighException();
	if (sign_grade > 150 || exec_grade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(Form const &other):
	Form(other._name, other._sign_grade, other._exec_grade){}

const std::string	&Form::getName(void) const
{
	static std::string	format;

	return (format = "Form " + this->_name);
}

bool	Form::isSigned(void) const
{
	return (this->_signed);
}

int	Form::getSignGrade(void) const
{
	return (this->_sign_grade);
}

int	Form::getExecGrade(void) const
{
	return (this->_exec_grade);
}

void	Form::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > this->getSignGrade())
		throw Form::GradeTooLowException();
	this->_signed = true;
}

std::ostream	&operator <<(std::ostream &out, Form const &form)
{
	out << form.getName() << " is ";
	if (form.isSigned())
		out << "signed. It required";
	else
		out << "not signed. It requires";
	out << " grade " << form.getSignGrade() << " to be sign, and grade ";
	out << form.getExecGrade() << " to be execute.";
	return (out);
}
