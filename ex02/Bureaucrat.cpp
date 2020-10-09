/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/29 12:59:45 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/10/09 13:43:20 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

#include <iostream> // cout


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

	o << i.getName() << ", bureaucrat grade " << i.getGrade() << std::endl;
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

	try
	{
		std::cout << this->_name << " signs form <" << form.getName() << '>'
		<< std::endl;
		form.beSigned(*this);
	}
	catch (std::exception& e) {
		std::cerr << "Warning : " << e.what() << std::endl;
	}
}


void				Bureaucrat::executeForm(AForm const& form) const {

	try
	{
		std::cout << this->_name << " executes form <" << form.getName()
		<< ">" << std::endl;
		form.execute(*this);
	}
	catch (std::exception& e) {
		std::cerr << "Warning : " << e.what() << std::endl;
	}
}


void				Bureaucrat::_check_grade() const {

	if (this->_grade < 1) {
		throw Bureaucrat::GradeTooHighException(this->_name + " has a grade below 1");
	} else if (this->_grade > 150) {
		throw Bureaucrat::GradeTooLowException(this->_name + " has a grade above 150");
	}
}
