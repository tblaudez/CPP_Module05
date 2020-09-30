/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RobotomyRequestForm.cpp                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/29 15:55:07 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/09/30 13:27:09 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

#include <cstdlib>


RobotomyRequestForm::RobotomyRequestForm(std::string target) :
ATargetedForm("Robotomy Request Form", 72, 45, target) {

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

	switch (rand() % 2) {

		case 0: std::cout << "[" << this->_target
				<< "] has been successfuly robotomized!" << std::endl; break;

		case 1: std::cout << "The operation is a failure.." << std::endl; break;

		default: break;
	}
}
