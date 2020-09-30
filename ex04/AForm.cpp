/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AForm.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/29 13:56:47 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/09/30 14:31:37 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

#include <iostream>
#include <sstream>


AForm::AForm(std::string const& name, int signingGrade, int executingGrade) : _name(name),
_signingGrade(signingGrade), _executingGrade(executingGrade), _signed(false) {

	this->_checkGrade();
}


AForm::AForm(AForm const& src) : _name(src._name), _signingGrade(src._signingGrade),
_executingGrade(src._executingGrade) {

	*this = src;
}


AForm&	AForm::operator=(AForm const& rhs) {

	if (this != &rhs) {
		this->_signed = rhs._signed;
	}

	return *this;
}


AForm::~AForm() {

}


std::ostream&	operator<<(std::ostream& o, AForm const& i) {

	i.print(o);
	return o;
}


std::string	const&	AForm::getName() const {

	return this->_name;
}


int					AForm::getSigningGrade() const {

	return this->_signingGrade;
}


int					AForm::getExecutingGrade() const {

	return this->_executingGrade;
}


bool				AForm::getSigned() const {

	return this->_signed;
}


void				AForm::beSigned(Bureaucrat const& bureaucrat) {

	std::ostringstream	oss;


	if (bureaucrat.getGrade() > this->_signingGrade) {
		oss << bureaucrat << " has too low grade to sign " << *this;
		throw AForm::GradeTooLowException(oss.str());
	}

	this->_signed = true;
}


void				AForm::execute(Bureaucrat const& executor) const {

	std::ostringstream	oss;

	if (this->_signed == false) {
		oss << *this << " is not signed yet";
		throw AForm::FormNotSignedException(oss.str());
	}
	else if (executor.getGrade() > this->_executingGrade) {
		oss << executor << " has too low grade to execute " << *this;
		throw AForm::GradeTooLowException(oss.str());
	}
}

void				AForm::_checkGrade() const {

	std::ostringstream	oss;

	if (this->_signingGrade < 1 || this->_executingGrade < 1) {
		oss << *this << " has grade below 1";
		throw AForm::GradeTooHighException(oss.str());
	}
	else if (this->_signingGrade > 150 || this->_executingGrade > 150) {
		oss << *this << " has grade above 150";
		throw AForm::GradeTooLowException(oss.str());
	}
}
