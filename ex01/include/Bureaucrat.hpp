/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:02:16 by JFikents          #+#    #+#             */
/*   Updated: 2024/08/29 18:34:42 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include "BureaucratExceptions.hpp"

class Form;

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;
		Bureaucrat() = delete;

	public:
		Bureaucrat(std::string const name, int grade);
		Bureaucrat(Bureaucrat const &other);
		~Bureaucrat() = default;
		Bureaucrat	&operator =(Bureaucrat const &other);

		const std::string	&getName(void) const;
		int					getGrade(void) const;
		void				promoteBureaucrat(void);
		void				demoteBureaucrat(void);

		class GradeTooHighException : public AGradeTooHighException {};
		class GradeTooLowException : public AGradeTooLowException {};

		void				signForm(Form &form);
};

std::ostream	&operator <<(std::ostream &out, Bureaucrat const &bureaucrat);

#endif