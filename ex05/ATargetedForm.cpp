/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ATargetedForm.cpp                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/30 12:28:16 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/09/30 14:32:05 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ATargetedForm.hpp"


ATargetedForm::ATargetedForm(std::string const& name, int signingGrade,
int executingGrade, std::string const& target) :
AForm(name, signingGrade, executingGrade), _target(target) {

}


ATargetedForm::ATargetedForm(ATargetedForm const& src) : AForm(src), _target(src._target) {

	*this = src;
}


ATargetedForm&	ATargetedForm::operator=(ATargetedForm const& rhs) {

	if (this != &rhs) {
		AForm::operator=(rhs);
	}

	return *this;
}


ATargetedForm::~ATargetedForm() {

}


std::string const&	ATargetedForm::getTarget() const {

	return this->_target;
}


void				ATargetedForm::execute(Bureaucrat const& executor) const {

	AForm::execute(executor);
	this->_action();
}


void				ATargetedForm::print(std::ostream& o) const {

	o << "(<" << this->getName() << "> [SGrade: " << this->getSigningGrade()
	<< ", EGrade: " << this->getExecutingGrade() << ", Signed: " << this->getSigned()
	<< ", Target: " << this->getTarget() << "])";
}
