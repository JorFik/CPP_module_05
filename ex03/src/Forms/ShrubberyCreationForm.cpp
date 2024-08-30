/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 20:22:32 by JFikents          #+#    #+#             */
/*   Updated: 2024/08/30 14:00:07 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target):
	AForm("Shrubbery Creation", 145, 137, target){}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other):
	ShrubberyCreationForm(other._target){}

void	ShrubberyCreationForm::_action(void) const
{
	std::ofstream	file(this->_target + "_shrubbery");

	if (file.is_open() == false)
	{
		std::cerr << "Error: Couldn't open file " << this->_target << "_shrubbery";
		std::cerr << " for writing." << std::endl;
		return ;
	}
	file << SHRUBBERY_TREE << std::endl;
	file << std::endl;
	file << SHRUBBERY_TREE << std::endl;
	file << std::endl;
	file << SHRUBBERY_TREE << std::endl;
	file.close();
}
