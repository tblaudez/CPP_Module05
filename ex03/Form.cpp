/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/29 13:56:47 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/09/30 11:06:43 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

#include <iostream>


Form::Form(std::string name, int signingGrade, int executingGrade) : _name(name),
_signingGrade(signingGrade), _executingGrade(executingGrade), _signed(false) {

	this->_checkGrade();
}


Form::Form(Form const& src) : _signingGrade(src._signingGrade),
_executingGrade(src._executingGrade) {

	*this = src;
}


Form&	Form::operator=(Form const& rhs) {

	if (this != &rhs) {
		this->_name = rhs._name;
		this->_signed = rhs._signed;
	}

	return *this;
}


Form::~Form() {

}


std::ostream&	operator<<(std::ostream& o, Form const& i) {

	o << "Form <" << i.getName() << "> - Signing Grade : " << i.getSigningGrade()
	<< " - Executing Grade : " << i.getExecutingGrade() << " - Signed :"
	<< i.getSigned();
	return o;
}


std::string	const&	Form::getName() const {

	return this->_name;
}


int					Form::getSigningGrade() const {

	return this->_signingGrade;
}


int					Form::getExecutingGrade() const {

	return this->_executingGrade;
}


bool				Form::getSigned() const {

	return this->_signed;
}


void				Form::beSigned(Bureaucrat const& bureaucrat) {

	if (bureaucrat.getGrade() > this->_signingGrade) {
		throw Form::GradeTooLowException(bureaucrat.getName()
			+ " is not important enough to sign " + this->_name);
	}

	this->_signed = true;
}


void				Form::_checkGrade() const {

	if (this->_signingGrade < 1 || this->_executingGrade < 1) {
		throw Form::GradeTooHighException("Form <" + this->_name
			+ "> has a grade below 1");
	} else if (this->_signingGrade > 150 || this->_executingGrade > 150) {
		throw Form::GradeTooLowException("Form <" + this->_name
			+ "> has a grade above 150");
	}
}


void				Form::execute(Bureaucrat const& executor) const {

	if (this->_signed == false) {
		throw Form::FormNotSignedException("Form <" + this->_name +
		"> is not signed yet");
	}
	else if (executor.getGrade() > this->_executingGrade) {
		throw Form::GradeTooLowException(executor.getName() +
		" has too low grade to execute form <" + this->_name + ">");
	}

	this->_action();
}
