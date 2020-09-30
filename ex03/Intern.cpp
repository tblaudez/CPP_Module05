/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/30 11:14:05 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/09/30 11:51:12 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"


typedef Form*	(Intern::*formFunctionPointer)(std::string const& target) const;


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


Form*	Intern::makeForm(std::string const& formName, std::string const& target) const {

	formFunctionPointer functions[3] = {&Intern::_makePresidentialPardonForm,
		&Intern::_makeRobotomyRequestForm, &Intern::_makeShrubberyCreationForm};
	std::string			actions[3] = {"presidential pardon", "robotomy request",
		"shrubbery creation"};

	for (int i=0; i<3; i++) {
		if (formName == actions[i]) {
			return (this->*functions[i])(target);
		}
	}

	std::cerr << "Error : Unknown Form name" << std::endl;
	return NULL;
}


Form*	Intern::_makePresidentialPardonForm(std::string const& target) const {

	std::cout << "Intern creates <PresidentialPardonForm>" << std::endl;
	return new PresidentialPardonForm(target);
}


Form*	Intern::_makeRobotomyRequestForm(std::string const& target) const {

	std::cout << "Intern creates <RobotomyRequestForm>" << std::endl;
	return new RobotomyRequestForm(target);
}


Form*	Intern::_makeShrubberyCreationForm(std::string const& target) const {

	std::cout << "Intern creates <ShrubberyCreationForm>" << std::endl;
	return new ShrubberyCreationForm(target);
}
