/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 17:21:56 by JFikents          #+#    #+#             */
/*   Updated: 2024/08/30 13:53:12 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

static bool	isGradeValid(int grade)
{
	return (grade >= 1 && grade <= 150);
}

AForm::AForm(std::string const name, int sign_grade, int exec_grade,
	std::string const &target):
	_name(name),
	_signed(false),
	_sign_grade(sign_grade),
	_exec_grade(exec_grade),
	_target(target)
{
	if (isGradeValid(sign_grade) == false || isGradeValid(exec_grade) == false)
		std::cerr << "Error Creating " << this->getName() << ", " << std::flush;
	if (isGradeValid(sign_grade) == false)
		std::cerr << "Sign " << std::flush;
	if (isGradeValid(exec_grade) == false)
		std::cerr << "Exec " << std::flush;
	if (sign_grade < 1 || exec_grade < 1)
		throw AForm::GradeTooHighException();
	if (sign_grade > 150 || exec_grade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(AForm const &other):
	AForm(other._name, other._sign_grade, other._exec_grade, other._target){}

const std::string	&AForm::getName(void) const
{
	static std::string	format;

	return (format = "Form " + this->_name);
}

bool	AForm::isSigned(void) const
{
	return (this->_signed);
}

int	AForm::getSignGrade(void) const
{
	return (this->_sign_grade);
}

int	AForm::getExecGrade(void) const
{
	return (this->_exec_grade);
}

const std::string	&AForm::getTarget(void) const
{
	return (this->_target);
}

std::ostream	&operator <<(std::ostream &out, AForm const &form)
{
	out << form.getName() << ": \n";
	out << "\tIt is ";
	if (form.isSigned())
		out << "";
	else
		out << "not ";
	out << "signed.\n\tIt requires grade " << form.getSignGrade() << " to be sign, and grade ";
	out << form.getExecGrade() << " to be execute.";
	out << "\n\tIt has " << form.getTarget() << " as the designated target.";
	return (out);
}

//?----------------------- Sign Form function (EX01) -----------------------?//

void	AForm::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > this->getSignGrade())
		throw AForm::GradeTooLowException();
	if (this->isSigned())
		throw AForm::SignedException();
	this->_signed = true;
}

//?---------------------- Execute Form function (EX02) ----------------------?//

void	AForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getExecGrade())
		throw AForm::GradeTooLowException();
	if (this->isSigned() == false)
		throw AForm::NotSignedException();
	this->_action();
}
