/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PresidentialPardonForm.cpp                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/29 15:26:47 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/10/09 13:26:11 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

#include <iostream> // cout


PresidentialPardonForm::PresidentialPardonForm(std::string const& target) :
ATargetedForm("PresidentialPardonForm", 25, 5, target) {

}


PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& src) :
ATargetedForm(src) {

	*this = src;
}


PresidentialPardonForm&	PresidentialPardonForm::operator=(PresidentialPardonForm const& rhs) {

	if (this != &rhs) {
		AForm::operator=(rhs);
	}

	return *this;
}


PresidentialPardonForm::~PresidentialPardonForm() {

}


void	PresidentialPardonForm::_action() const {

	std::cout << this->_target << " has been pardoned by Zafod Beeblebrox"
	<< std::endl;
}
