/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PresidentialPardonForm.cpp                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/29 15:26:47 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/10/09 12:58:11 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

#include <iostream> // cout


PresidentialPardonForm::PresidentialPardonForm(std::string const& target) :
AForm("PresidentialPardonForm", 25, 5), _target(target) {

}


PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& src) :
AForm(src) {

	*this = src;
}


PresidentialPardonForm&	PresidentialPardonForm::operator=(PresidentialPardonForm const& rhs) {

	if (this != &rhs) {
		AForm::operator=(rhs);
		this->_target = rhs._target;
	}

	return *this;
}


PresidentialPardonForm::~PresidentialPardonForm() {

}


std::ostream&	operator<<(std::ostream& o, PresidentialPardonForm const& i) {

	o << static_cast<AForm const&>(i);
	o << " - Target : " << i.getTarget();
	return o;
}


std::string const&	PresidentialPardonForm::getTarget() const {

	return this->_target;
}


void				PresidentialPardonForm::_action() const {

	std::cout << this->_target << " has been pardoned by Zafod Beeblebrox"
	<< std::endl;
}
