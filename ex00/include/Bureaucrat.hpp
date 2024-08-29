/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:02:16 by JFikents          #+#    #+#             */
/*   Updated: 2024/08/29 15:58:28 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

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

		class GradeTooHighException;
		class GradeTooLowException;

};

std::ostream	&operator <<(std::ostream &out, Bureaucrat const &bureaucrat);

class Bureaucrat::GradeTooHighException : public std::exception
{
	public:
		virtual const char	*what() const noexcept override;
		~GradeTooHighException() noexcept = default;
};

class Bureaucrat::GradeTooLowException : public std::exception
{
	public:
		virtual const char	*what() const noexcept override;
		~GradeTooLowException() noexcept = default;
};

#endif