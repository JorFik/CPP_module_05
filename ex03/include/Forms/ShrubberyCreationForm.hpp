/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 20:17:16 by JFikents          #+#    #+#             */
/*   Updated: 2024/08/30 12:26:06 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

# define SHRUBBERY_TREE \
"                     .o00o\n\
                   o000000oo\n\
                  00000000000o\n\
                 00000000000000\n\
              oooooo  00000000  o88o\n\
           ooOOOOOOOoo  ```''  888888\n\
         OOOOOOOOOOOO'.qQQQQq. `8888'\n\
        oOOOOOOOOOO'.QQQQQQQQQQ/.88'\n\
        OOOOOOOOOO'.QQQQQQQQQQ/ /q\n\
         OOOOOOOOO QQQQQQQQQQ/ /QQ\n\
           OOOOOOOOO `QQQQQQ/ /QQ'\n\
             OO:F_P:O `QQQ/  /Q'\n\
                \\\\. \\ |  // |\n\
                d\\ \\\\\\|_////\n\
                qP| \\\\ _' `|Ob\n\
                   \\  / \\  \\Op\n\
                   |  | O| |\n\
           _       /\\. \\_/ /\\\\\n\
            `---__/|_\\\\   //| \\ __\n\
                  `-'  `-'`-'-'"

class ShrubberyCreationForm : public AForm
{
	private:
		void	_action(void) const override;

	public:
		~ShrubberyCreationForm() override = default;
		ShrubberyCreationForm	&operator =\
			(ShrubberyCreationForm const &other) = delete;
		ShrubberyCreationForm(std::string const &target);
		ShrubberyCreationForm(ShrubberyCreationForm const &other);
};

#endif