/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BureaucratExceptions.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:45:40 by JFikents          #+#    #+#             */
/*   Updated: 2024/08/29 17:12:39 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const char	*AGradeTooHighException::what() const noexcept
{
	return ("Grade is too high.");
}

const char	*AGradeTooLowException::what() const noexcept
{
	return ("Grade is too low.");
}
