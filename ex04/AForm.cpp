/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AForm.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/29 13:56:47 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/10/09 13:39:45 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"


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

	o << "<" << i.getName()
	<< "> - Signing Grade : " << i.getSigningGrade()
	<< " - Executing Grade : " << i.getExecutingGrade()
	<< " - Signed : " << std::boolalpha << i.getSigned();
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

	if (bureaucrat.getGrade() > this->_signingGrade) {
		throw AForm::GradeTooLowException(bureaucrat.getName()
			+ " is not important enough to sign " + this->_name);
	}

	this->_signed = true;
}


void				AForm::_checkGrade() const {

	if (this->_signingGrade < 1 || this->_executingGrade < 1) {
		throw AForm::GradeTooHighException("Form <" + this->_name
			+ "> has a grade below 1");
	}
	else if (this->_signingGrade > 150 || this->_executingGrade > 150) {
		throw AForm::GradeTooLowException("Form <" + this->_name
			+ "> has a grade above 150");
	}
}


void				AForm::execute(Bureaucrat const& executor) const {

	if (this->_signed == false) {
		throw AForm::FormNotSignedException("Form <" + this->_name +
		"> is not signed yet");
	}
	else if (executor.getGrade() > this->_executingGrade) {
		throw AForm::GradeTooLowException(executor.getName() +
		" has too low grade to execute form <" + this->_name + ">");
	}
}
