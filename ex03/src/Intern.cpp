/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 14:12:20 by JFikents          #+#    #+#             */
/*   Updated: 2024/08/30 15:04:46 by JFikents         ###   ########.fr       */
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

enum FormType	Intern::find_form_type(std::string const &form_name)
{
	std::string normalize_form_name = form_name;

	for (size_t i = 0; i < normalize_form_name.length(); i++)
		normalize_form_name[i] = std::tolower(normalize_form_name[i]);
	if (normalize_form_name == "shrubbery creation")
		return (SHRUBBERY_CREATION);
	else if (normalize_form_name == "robotomy request")
		return (ROBOTOMY_REQUEST);
	else if (normalize_form_name == "presidential pardon")
		return (PRESIDENTIAL_PARDON);
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
		form = (this->*form_maker[form_type])(target);
		std::cout << "Intern creates a " << form->getName() << " for " << target;
		std::cout << "." << std::endl;
	}
	catch (std::exception &e){
		std::cerr << "Intern can't create the form, it's a " << e.what();
		std::cerr << std::endl;
	}
	return (form);
}
