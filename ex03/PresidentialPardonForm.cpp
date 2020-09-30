/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PresidentialPardonForm.cpp                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/29 15:26:47 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/09/30 11:08:00 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

#include <iostream>


PresidentialPardonForm::PresidentialPardonForm(std::string target) :
Form("PresidentialPardonForm", 25, 5), _target(target) {

}


PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& src) :
Form(src) {

	*this = src;
}


PresidentialPardonForm&	PresidentialPardonForm::operator=(PresidentialPardonForm const& rhs) {

	if (this != &rhs) {
		Form::operator=(rhs);
		this->_target = rhs._target;
	}

	return *this;
}


PresidentialPardonForm::~PresidentialPardonForm() {

}


std::ostream&	operator<<(std::ostream& o, PresidentialPardonForm const& i) {

	o << "PresidentialPardonForm targeted on " << i.getTarget();
	return o;
}


std::string const&	PresidentialPardonForm::getTarget() const {

	return this->_target;
}


void				PresidentialPardonForm::_action() const {

	std::cout << this->_target << " has been pardoned by Zafod Beeblebrox"
	<< std::endl;
}
