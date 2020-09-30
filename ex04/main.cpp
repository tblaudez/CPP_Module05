/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/30 13:18:01 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/09/30 14:52:08 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "OfficeBlock.hpp"

int	main(void) {

	Intern		intern;
	Bureaucrat	joe("Joe", 67);
	Bureaucrat	bob("Robert", 7);
	OfficeBlock	ob;

	ob.setExecutingBureaucrat(&bob);
	ob.setSigningBureaucrat(&joe);
	ob.setIntern(&intern);

	try
	{
		ob.doBureaucracy("presidential pardon", "Bob Lennon");
		ob.doBureaucracy("shrubbery creation", "oven");
		ob.doBureaucracy("robotomy request", "Bendy");
	}
	catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}


	return 0;
}
