/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 16:43:39 by JFikents          #+#    #+#             */
/*   Updated: 2024/08/29 17:37:50 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>
#include "BureaucratExceptions.hpp"

class Bureaucrat;
class AGradeTooHighException;
class AGradeTooLowException;

class Form
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_sign_grade;
		const int			_exec_grade;

	public:
		Form()									= delete;
		Form	&operator =(Form const &other)	= delete;
		~Form()									= default;
		Form(std::string const name, int sign_grade, int exec_grade);
		Form(Form const &other);

		const std::string	&getName(void)		const;
		bool				isSigned(void)		const;
		int					getSignGrade(void)	const;
		int					getExecGrade(void)	const;

		void				beSigned(Bureaucrat const &bureaucrat);

		class GradeTooHighException : public AGradeTooHighException {};
		class GradeTooLowException : public AGradeTooLowException {};
};

std::ostream	&operator <<(std::ostream &out, Form const &form);

#endif