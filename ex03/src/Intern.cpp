/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 14:12:20 by JFikents          #+#    #+#             */
/*   Updated: 2024/09/02 21:41:49 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

AForm	*Intern::_makeShrubberyCreationForm(std::string const &target)
{
	return (new ShrubberyCreationForm(target));
}

AForm	*Intern::_makeRobotomyRequestForm(std::string const &target)
{
	return (new RobotomyRequestForm(target));
}

AForm	*Intern::_makePresidentialPardonForm(std::string const &target)
{
	return (new PresidentialPardonForm(target));
}

static std::string	make_lowercase(std::string const &str)
{
	std::string	lowercase_str = str;

	for (size_t i = 0; i < lowercase_str.length(); i++)
		lowercase_str[i] = std::tolower(lowercase_str[i]);
	return (lowercase_str);
}

static FormType	find_form_type(std::string const &form_name)
{
	const std::string	lowercase_input = make_lowercase(form_name);
	std::string			form_types[3] =
		{"shrubbery creation", "robotomy request", "presidential pardon"};
	FormType			form_type;

	for (size_t i = 0; lowercase_input != form_types[i] && i < 3; i++)
		form_type = static_cast<FormType>(i);
	if (form_type != FormType::UNKNOWN)
		return (form_type);
	throw Intern::UnknownFormTypeException();
}

AForm	*Intern::makeForm(std::string const &form_name, std::string const &target)
{
	AForm			*form = nullptr;
	enum FormType	form_type;
	AForm			*(Intern::*form_maker[3])(std::string const &target) =
	{
		&Intern::_makeShrubberyCreationForm,
		&Intern::_makeRobotomyRequestForm,
		&Intern::_makePresidentialPardonForm
	};

	try{
		form_type = find_form_type(form_name);
		form = (this->*form_maker[static_cast<int>(form_type)])(target);
		std::cout << "Intern creates a " << form->getName() << " for ";
		std::cout << target << "." << std::endl;
	}
	catch (std::exception &e){
		std::cerr << "Intern can't create the form, it's a " << e.what();
		std::cerr << std::endl;
	}
	return (form);
}
