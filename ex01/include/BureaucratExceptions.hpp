/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BureaucratExceptions.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 17:13:07 by JFikents          #+#    #+#             */
/*   Updated: 2024/08/29 17:18:50 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_EXCEPTIONS_HPP
# define BUREAUCRAT_EXCEPTIONS_HPP

# include <exception>

class AGradeTooHighException : public std::exception
{
	public:
		virtual const char	*what() const noexcept override;
		~AGradeTooHighException() noexcept = default;
};

class AGradeTooLowException : public std::exception
{
	public:
		virtual const char	*what() const noexcept override;
		~AGradeTooLowException() noexcept = default;
};

#endif