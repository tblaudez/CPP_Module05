/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RobotomyRequestForm.cpp                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/29 15:55:07 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/10/09 13:26:19 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

#include <iostream> // cout
#include <cstdlib> // rand


RobotomyRequestForm::RobotomyRequestForm(std::string const& target) :
ATargetedForm("RobotomyRequestForm", 72, 45, target) {

}


RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& src) :
ATargetedForm(src) {

	*this = src;
}


RobotomyRequestForm&	RobotomyRequestForm::operator=(RobotomyRequestForm const& rhs) {

	if (this != &rhs) {
		ATargetedForm::operator=(rhs);
	}

	return *this;
}


RobotomyRequestForm::~RobotomyRequestForm() {

}


void				RobotomyRequestForm::_action() const {

	std::cout << "* LOUD DRILLING NOISES *" << std::endl;

	if (rand() % 2 == 0) {
		std::cout << this->_target << " has been successfuly robotomized!"
		<< std::endl;
	}
	else {
		std::cout << "The operation is a failure.." << std::endl;
	}
}
