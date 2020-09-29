/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/29 14:24:25 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/09/29 15:02:15 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void) {

	// Form with too high grade
	{
		try
		{
			Form	hollidayForm("Holliday Form", 0, 50);
			std::cout << "You should not see this" << std::endl;
		}
		catch(std::exception& e) {
			std::cerr << "Error : " << e.what() << std::endl;
		}
	}

	// Form with too low grade
	{
		try
		{
			Form	hollidayForm("Holliday Form", 50, 151);
			std::cout << "You should not see this" << std::endl;
		}
		catch(std::exception& e) {
			std::cerr << "Error : " << e.what() << std::endl;
		}
	}

	// Bureaucrat has too low grade to sign form
	{
		try
		{
			Bureaucrat	bob;
			Form		form("Regular Form", 50, 50);

			bob.signForm(form);
		}
		catch(std::exception& e) {
			std::cerr << "Error : " << e.what() << std::endl;
		}
	}

	// Everything is fine
	{
		try
		{
			Bureaucrat	bob("Bob", 1);
			Form		form("Regular Form", 50, 50);

			bob.signForm(form);
			std::cout << "Everything is a-OK!" << std::endl;
		}
		catch(std::exception& e) {
			std::cerr << "Error : " << e.what() << std::endl;
		}
	}
	return 0;
}
