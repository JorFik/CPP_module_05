/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AExceptions.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:45:40 by JFikents          #+#    #+#             */
/*   Updated: 2024/08/30 15:04:24 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AExceptions.hpp"

const char	*AGradeTooHighException::what() const noexcept
{
	return ("Grade is too high.");
}

const char	*AGradeTooLowException::what() const noexcept
{
	return ("Grade is too low.");
}

const char	*ANotSignedException::what() const noexcept
{
	return ("Form is not signed.");
}

const char	*ASignedException::what() const noexcept
{
	return ("Form is already signed.");
}

const char	*AUknownFormTypeException::what() const noexcept
{
	return ("Unknown form type.");
}
