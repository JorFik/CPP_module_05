/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BureaucratExceptions.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:45:40 by JFikents          #+#    #+#             */
/*   Updated: 2024/08/29 16:11:06 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const char	*Bureaucrat::GradeTooHighException::what() const noexcept
{
	return ("Grade is too high.");
}

const char	*Bureaucrat::GradeTooLowException::what() const noexcept
{
	return ("Grade is too low.");
}
