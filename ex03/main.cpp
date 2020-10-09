/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/29 15:37:13 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/10/09 12:59:17 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

#include <cstdlib> // srand
#include <ctime> // time
#include <iostream> // cout


int	main(void) {

	srand(time(0));

	Bureaucrat	bob("Robert", 1);
	Intern		someRandomIntern;
	AForm*		form;

	{
		form = someRandomIntern.makeForm("presidential pardon", "Joe Mama");
		if (form != NULL) {
			bob.signForm(*form);
			bob.executeForm(*form);
		}
		std::cout << "-----------" << std::endl;
	}


	{
		form = someRandomIntern.makeForm("shrubbery creation", "Bedroom");
		if (form != NULL) {
			bob.signForm(*form);
			bob.executeForm(*form);
		}
		std::cout << "-----------" << std::endl;
	}


	{
		form = someRandomIntern.makeForm("robotomy request", "Bendy");
		if (form != NULL) {
			bob.signForm(*form);
			bob.executeForm(*form);
		}
		std::cout << "-----------" << std::endl;
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
