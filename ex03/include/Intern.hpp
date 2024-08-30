/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 14:11:10 by JFikents          #+#    #+#             */
/*   Updated: 2024/08/30 14:57:24 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "AForm.hpp"
# include "AExceptions.hpp"

enum FormType
{
	SHRUBBERY_CREATION,
	ROBOTOMY_REQUEST,
	PRESIDENTIAL_PARDON
};

class Intern
{
	private:
		AForm	*_makeShrubberyCreationForm(std::string const &target);
		AForm	*_makeRobotomyRequestForm(std::string const &target);
		AForm	*_makePresidentialPardonForm(std::string const &target);
		enum FormType	find_form_type(std::string const &form_name);

	public:
		Intern()									= default;
		~Intern()									= default;
		Intern(Intern const &other)					= default;
		Intern	&operator =(Intern const &other)	= default;

		AForm	*makeForm(std::string const &form_name, std::string const &target);

		class UnknownFormTypeException : public AUknownFormTypeException {};
};

#endif