/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 20:36:13 by JFikents          #+#    #+#             */
/*   Updated: 2024/08/30 13:54:47 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <random>

RobotomyRequestForm::RobotomyRequestForm(std::string const &target):
	AForm("Robotomy Request", 72, 45, target)
{
	_gen.seed(std::random_device()());
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other):
	RobotomyRequestForm(other._target){}

void	RobotomyRequestForm::_action(void) const
{
	std::bernoulli_distribution	distribution(0.5);
	bool	success = distribution(_gen);

	std::cout << DRILLING_NOISE << std::endl;
	if (success)
		std::cout << this->_target << " has been robotomized successfully.";
	else
	{
		std::cout << this->_target << "'s robotomization failed.\nSorry ";
		std::cout << this->_target << ", we still love you.";
	}
	std::cout << std::endl;
}
