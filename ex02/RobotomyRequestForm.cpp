/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RobotomyRequestForm.cpp                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/29 15:55:07 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/10/09 13:00:52 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

#include <iostream> // cout
#include <cstdlib> // rand


RobotomyRequestForm::RobotomyRequestForm(std::string const& target) :
AForm("RobotomyRequestForm", 72, 45), _target(target) {

}


RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& src) :
AForm(src) {

	*this = src;
}


RobotomyRequestForm&	RobotomyRequestForm::operator=(RobotomyRequestForm const& rhs) {

	if (this != &rhs) {
		AForm::operator=(rhs);
		this->_target = rhs._target;
	}

	return *this;
}


RobotomyRequestForm::~RobotomyRequestForm() {

}


std::ostream&	operator<<(std::ostream& o, RobotomyRequestForm const& i) {

	o << static_cast<AForm const&>(i);
	o << " - Target : " << i.getTarget();
	return o;
}


std::string const&	RobotomyRequestForm::getTarget() const {

	return this->_target;
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
