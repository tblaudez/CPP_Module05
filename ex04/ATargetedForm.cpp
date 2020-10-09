/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ATargetedForm.cpp                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/30 12:28:16 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/10/09 13:08:09 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ATargetedForm.hpp"


ATargetedForm::ATargetedForm(std::string const& name, int signingGrade,
int executingGrade, std::string const& target) :
AForm(name, signingGrade, executingGrade), _target(target) {

}


ATargetedForm::ATargetedForm(ATargetedForm const& src) : AForm(src) {

	*this = src;
}


ATargetedForm&	ATargetedForm::operator=(ATargetedForm const& rhs) {

	if (this != &rhs) {
		AForm::operator=(rhs);
		this->_target = rhs._target;
	}

	return *this;
}


ATargetedForm::~ATargetedForm() {

}


std::ostream&	operator<<(std::ostream& o, ATargetedForm const& i) {

	o << static_cast<AForm const&>(i);
	o << " - Target : " << i.getTarget();
	return o;
}


std::string const&	ATargetedForm::getTarget() const {

	return this->_target;
}


void				ATargetedForm::execute(Bureaucrat const& executor) const {

	AForm::execute(executor);
	this->_action();
}
