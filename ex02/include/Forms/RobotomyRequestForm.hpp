/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 20:35:11 by JFikents          #+#    #+#             */
/*   Updated: 2024/08/30 12:19:58 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <string>
# include <random>

# define DRILLING_NOISE "* Some drilling noises *"

class RobotomyRequestForm : public AForm
{
	private:
		mutable std::mt19937	_gen;

		void	_action(void) const override;

	public:
		~RobotomyRequestForm() override = default;
		RobotomyRequestForm	&operator =\
			(RobotomyRequestForm const &other) = delete;
		RobotomyRequestForm(std::string const &target);
		RobotomyRequestForm(RobotomyRequestForm const &other);
};

#endif