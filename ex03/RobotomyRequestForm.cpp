/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RobotomyRequestForm.cpp                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/29 15:55:07 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/09/30 11:08:12 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

#include <cstdlib>


RobotomyRequestForm::RobotomyRequestForm(std::string target) :
Form("RobotomyRequestForm", 72, 45), _target(target) {

}


RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& src) :
Form(src) {

	*this = src;
}


RobotomyRequestForm&	RobotomyRequestForm::operator=(RobotomyRequestForm const& rhs) {

	if (this != &rhs) {
		Form::operator=(rhs);
		this->_target = rhs._target;
	}

	return *this;
}


RobotomyRequestForm::~RobotomyRequestForm() {

}


std::ostream&	operator<<(std::ostream& o, RobotomyRequestForm const& i) {

	o << "RobotomyRequestForm targeted to " << i.getTarget() << std::endl;
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
	} else {
		std::cout << "The operation is a failure.." << std::endl;
	}
}
