/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BureaucratExceptions.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 17:13:07 by JFikents          #+#    #+#             */
/*   Updated: 2024/08/29 19:48:29 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AEXCEPTIONS_HPP
# define AEXCEPTIONS_HPP

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

class ANotSignedException : public std::exception
{
	public:
		virtual const char	*what() const noexcept override;
		~ANotSignedException() noexcept = default;
};

class ASignedException : public std::exception
{
	public:
		virtual const char	*what() const noexcept override;
		~ASignedException() noexcept = default;
};

#endif