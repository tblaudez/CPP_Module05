/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/29 13:13:15 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/09/29 13:43:58 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void) {

	// Normal run
	{
		try {
			Bureaucrat	robert;
			Bureaucrat	bob("Bob", 75);
			Bureaucrat	james("James", 1);
			Bureaucrat	henry("Henry", 150);
			std::cout << "Everything is a-OK !" << std::endl;
		} catch (std::exception& e) {
			std::cerr << "Error : " << e.what() << std::endl;
		}
	}

	// Grade too high in constructor
	{
		try {
			Bureaucrat	trevor("Trevor", 0);
			std::cout << "You should not see this" << std::endl;
		} catch (std::exception& e) {
			std::cerr << "Error : " << e.what() << std::endl;
		}
	}

	// Grade too low in constructor
	{
		try {
			Bureaucrat	trevor("Trevor", 151);
			std::cout << "You should not see this" << std::endl;
		} catch (std::exception& e) {
			std::cerr << "Error : " << e.what() << std::endl;
		}
	}

	// Grade too high after increment
	{
		try {
			Bureaucrat	trevor("Trevor", 1);
			std::cout << trevor;
			trevor.incrementGrade();
		} catch (std::exception& e) {
			std::cerr << "Error : " << e.what() << std::endl;
		}
	}

	// Grade too low after decrement
	{
		try {
			Bureaucrat	trevor("Trevor", 150);
			std::cout << trevor;
			trevor.decrementGrade();
		} catch (std::exception& e) {
			std::cerr << "Error : " << e.what() << std::endl;
		}
	}

	return 0;
}
