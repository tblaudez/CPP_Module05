/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/30 11:14:05 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/10/09 13:42:39 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

#include <iostream> // cout


typedef AForm*	(Intern::*formFunctionPointer)(std::string const& target) const;


Intern::Intern() {

}


Intern::Intern(Intern const& src) {

	*this = src;
}


Intern&	Intern::operator=(Intern const& rhs) {

	if (this != &rhs) {
		/* Do things */
	}

	return *this;
}


Intern::~Intern() {

}


AForm*	Intern::makeForm(std::string const& formName, std::string const& target) const {

	formFunctionPointer functions[3] = {&Intern::_makePresidentialPardonForm,
		&Intern::_makeRobotomyRequestForm, &Intern::_makeShrubberyCreationForm};
	std::string			actions[3] = {"presidential pardon", "robotomy request",
		"shrubbery creation"};

	for (int i=0; i < 3; i++) {
		if (formName == actions[i]) {
			return (this->*functions[i])(target);
		}
	}

	return NULL;
}


AForm*	Intern::_makePresidentialPardonForm(std::string const& target) const {

	PresidentialPardonForm* form = new PresidentialPardonForm(target);
	std::cout << "Intern creates " << static_cast<ATargetedForm&>(*form) << std::endl;
	return form;
}


AForm*	Intern::_makeRobotomyRequestForm(std::string const& target) const {

	RobotomyRequestForm* form = new RobotomyRequestForm(target);
	std::cout << "Intern creates " << static_cast<ATargetedForm&>(*form) << std::endl;
	return form;
}


AForm*	Intern::_makeShrubberyCreationForm(std::string const& target) const {

	ShrubberyCreationForm* form = new ShrubberyCreationForm(target);
	std::cout << "Intern creates " << static_cast<ATargetedForm&>(*form) << std::endl;
	return form;
}
