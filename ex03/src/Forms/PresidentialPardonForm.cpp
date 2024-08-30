/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 12:10:54 by JFikents          #+#    #+#             */
/*   Updated: 2024/08/30 12:12:03 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const &target):
	AForm("Presidential Pardon", 25, 5, target){}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other):
	PresidentialPardonForm(other._target){}

void	PresidentialPardonForm::_action(void) const
{
	std::cout << this->_target << " has been pardoned by Zafod Beeblebrox.";
	std::cout << std::endl;
}
