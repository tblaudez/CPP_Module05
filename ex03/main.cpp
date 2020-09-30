/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/29 15:37:13 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/09/30 11:55:14 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

#include <cstdlib>


int	main(void) {

	srand(time(0));

	Bureaucrat	bob("Robert", 1);
	Intern		someRandomIntern;
	Form*		form;

	{
		form = someRandomIntern.makeForm("presidential pardon", "Joe Mama");
		if (form != NULL) {
			bob.signForm(*form);
			bob.executeForm(*form);
		}
	}


	{
		form = someRandomIntern.makeForm("shrubbery creation", "Bedroom");
		if (form != NULL) {
			bob.signForm(*form);
			bob.executeForm(*form);
		}
	}


	{
		form = someRandomIntern.makeForm("robotomy request", "Bendy");
		if (form != NULL) {
			bob.signForm(*form);
			bob.executeForm(*form);
		}
	}


	{
		form = someRandomIntern.makeForm("lol idk", "Jafar");
		if (form != NULL) {
			bob.signForm(*form);
			bob.executeForm(*form);
		}
	}

	return 0;
}
