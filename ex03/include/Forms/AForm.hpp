/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 16:43:39 by JFikents          #+#    #+#             */
/*   Updated: 2024/08/30 13:44:37 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <string>
#include "AExceptions.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_sign_grade;
		const int			_exec_grade;

	protected:
		const std::string	_target;

		AForm(std::string const name, int sign_grade, int exec_grade,
			std::string const &target);
		virtual void		_action(void) const = 0;

	public:
		AForm()									= delete;
		AForm	&operator =(AForm const &other)	= delete;
		virtual ~AForm()						= default;
		AForm(AForm const &other);

		const std::string	&getName(void)		const;
		bool				isSigned(void)		const;
		int					getSignGrade(void)	const;
		int					getExecGrade(void)	const;
		const std::string	&getTarget(void)	const;

		void				beSigned(Bureaucrat const &bureaucrat);

		class GradeTooHighException	: public AGradeTooHighException	{};
		class GradeTooLowException	: public AGradeTooLowException	{};
		class NotSignedException	: public ANotSignedException	{};
		class SignedException		: public ASignedException		{};

		void				execute(Bureaucrat const &executor) const;
};

std::ostream	&operator <<(std::ostream &out, AForm const &form);

#endif