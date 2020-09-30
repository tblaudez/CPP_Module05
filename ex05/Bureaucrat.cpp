/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/29 12:59:45 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/09/30 14:42:39 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

#include <iostream>
#include <sstream>


Bureaucrat::Bureaucrat(std::string const& name, int grade) : _name(name),
_grade(grade) {

	this->_check_grade();
}


Bureaucrat::Bureaucrat(Bureaucrat const& src) : _name(src._name) {

	*this = src;
}


Bureaucrat&	Bureaucrat::operator=(Bureaucrat const& rhs) {

	if (this != &rhs) {
		this->_grade = rhs._grade;
	}

	return *this;
}


Bureaucrat::~Bureaucrat() {

}


std::ostream&	operator<<(std::ostream& o, Bureaucrat const& i) {

	o << "(<" << i.getName() << "> [Grade: " << i.getGrade() << "])";
	return o;
}


std::string const&	Bureaucrat::getName() const {

	return this->_name;
}


int					Bureaucrat::getGrade() const {

	return this->_grade;
}


void				Bureaucrat::incrementGrade() {

	this->_grade -= 1;
	this->_check_grade();
}


void				Bureaucrat::decrementGrade() {

	this->_grade += 1;
	this->_check_grade();
}


void				Bureaucrat::signForm(AForm& form) const {

	std::cout << *this << " signs " << form << std::endl;

	form.beSigned(*this);
}


void				Bureaucrat::executeForm(AForm const& form) const {

	std::cout << *this << " executes " << form << std::endl;

	form.execute(*this);
}


void				Bureaucrat::_check_grade() const {

	std::ostringstream	oss;

	if (this->_grade < 1) {
		oss << *this << " has grade below 1";
		throw Bureaucrat::GradeTooHighException(oss.str());
	}
	else if (this->_grade > 150) {
		oss << *this << " has grade above 150";
		throw Bureaucrat::GradeTooLowException(oss.str());
	}
}
