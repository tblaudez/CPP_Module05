/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/30 13:18:01 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/10/09 13:40:42 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "OfficeBlock.hpp"

#include <cstdlib> // srand
#include <ctime> // time
#include <iostream> // cerr


int	main(void) {

	srand(time(0));

	OfficeBlock	ob;

	ob.setExecutingBureaucrat(new Bureaucrat("Bob", 34));
	ob.setSigningBureaucrat(new Bureaucrat("Joe", 56));
	ob.setIntern(new Intern);

	try
	{
		ob.doBureaucracy("duck hunt", "Donald Duck");
	}
	catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl << std::endl;
	}

	try
	{
		ob.doBureaucracy("presidential pardon", "Bob Lennon");
	}
	catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl << std::endl;
	}

	try
	{
		ob.doBureaucracy("shrubbery creation", "House");
	}
	catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl << std::endl;
	}

	try
	{
		ob.doBureaucracy("robotomy request", "Bendy");
	}
	catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl << std::endl;
	}


	return 0;
}
