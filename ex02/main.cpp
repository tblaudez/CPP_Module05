/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/29 15:37:13 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/10/09 12:42:23 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <cstdlib> // srand
#include <ctime> // time
#include <iostream> // cerr


int	main(void) {

	srand(time(0));

	try
	{
		Bureaucrat				bob("Robert", 24);

		PresidentialPardonForm	pp("Larry");
		std::cout << pp << std::endl;
		RobotomyRequestForm		rr("Henry");
		std::cout << rr << std::endl;
		ShrubberyCreationForm	sc("Living_room");
		std::cout << sc << std::endl;

		bob.signForm(pp);
		bob.executeForm(pp);

		bob.signForm(rr);
		bob.executeForm(rr);

		bob.signForm(sc);
		bob.executeForm(sc);
	}
	catch (std::exception& e) {

		std::cerr << "Error : " << e.what() << std::endl;
	}



	return 0;
}
