/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PresidentialPardonForm.cpp                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/29 15:26:47 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/09/30 12:41:57 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm(std::string target) :
ATargetedForm("Presidential Pardon Form", 25, 5, target) {

}


PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& src) :
ATargetedForm(src) {

	*this = src;
}


PresidentialPardonForm&	PresidentialPardonForm::operator=(PresidentialPardonForm const& rhs) {

	if (this != &rhs) {
		ATargetedForm::operator=(rhs);
	}

	return *this;
}


PresidentialPardonForm::~PresidentialPardonForm() {

}


void				PresidentialPardonForm::_action() const {

	std::cout << this->_target << " has been pardoned by Zafod Beeblebrox"
	<< std::endl;
}
