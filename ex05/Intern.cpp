/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/30 11:14:05 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/09/30 14:28:54 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"


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


std::ostream&	operator<<(std::ostream& o, Intern const& i) {

	(void)i;
	o << "Random Intern";
	return o;
}


AForm*	Intern::makeForm(std::string const& formName, std::string const& target) const {

	formFunctionPointer functions[3] = {&Intern::_makePresidentialPardonForm,
		&Intern::_makeRobotomyRequestForm, &Intern::_makeShrubberyCreationForm};
	std::string			actions[3] = {"presidential pardon", "robotomy request",
		"shrubbery creation"};
	AForm*	form = NULL;

	for (int i=0; i<3; i++) {
		if (formName == actions[i]) {
			form = (this->*functions[i])(target);
			break;
		}
	}

	if (form == NULL) {
		std::cerr << "Error : Unknown Form : " << formName << std::endl;
	} else {
		std::cout << "Intern creates " << *form << std::endl;
	}

	return form;
}


AForm*	Intern::_makePresidentialPardonForm(std::string const& target) const {

	return new PresidentialPardonForm(target);
}


AForm*	Intern::_makeRobotomyRequestForm(std::string const& target) const {

	return new RobotomyRequestForm(target);
}


AForm*	Intern::_makeShrubberyCreationForm(std::string const& target) const {

	return new ShrubberyCreationForm(target);
}
