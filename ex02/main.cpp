/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/29 15:37:13 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/09/29 16:43:41 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <cstdlib>


int	main(void) {

	srand(time(0));

	try
	{
		Bureaucrat				bob("Robert", 24);
		PresidentialPardonForm	presidentialPardon("Larry");
		RobotomyRequestForm		robotomyRequest("Henry");
		ShrubberyCreationForm	shrubberyCreation("Living_room");

		bob.signForm(presidentialPardon);
		bob.executeForm(presidentialPardon);

		bob.signForm(robotomyRequest);
		bob.executeForm(robotomyRequest);

		bob.signForm(shrubberyCreation);
		bob.executeForm(shrubberyCreation);
	}
	catch (std::exception& e) {

		std::cerr << "Error : " << e.what() << std::endl;
	}



	return 0;
}
