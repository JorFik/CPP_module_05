/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:02:16 by JFikents          #+#    #+#             */
/*   Updated: 2024/08/30 12:14:20 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include "AExceptions.hpp"

class AForm;

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;

	public:
		Bureaucrat()						= delete;
		~Bureaucrat()						= default;
		Bureaucrat(std::string const name, int grade);
		Bureaucrat(Bureaucrat const &other);
		Bureaucrat	&operator =(Bureaucrat const &other);

		const std::string	&getName(void) const;
		int					getGrade(void) const;
		void				promoteBureaucrat(void);
		void				demoteBureaucrat(void);

		class GradeTooHighException	: public AGradeTooHighException {};
		class GradeTooLowException	: public AGradeTooLowException	{};

		void				signForm(AForm &form);

		void				executeForm(AForm const &form) const;
};

std::ostream	&operator <<(std::ostream &out, Bureaucrat const &bureaucrat);

#endif