/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   OfficeBlock.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/30 13:10:18 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/10/09 13:36:52 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "OfficeBlock.hpp"

#include <iostream> // cout


OfficeBlock::OfficeBlock(Bureaucrat* signingBureaucrat, Bureaucrat* executingBureaucrat,
Intern* intern) : _signingBureaucrat(signingBureaucrat),
_executingBureaucrat(executingBureaucrat), _intern(intern) {

}


OfficeBlock::OfficeBlock(OfficeBlock const& src) {

	*this = src;
}


OfficeBlock&	OfficeBlock::operator=(OfficeBlock const& rhs) {

	if (this != &rhs) {
		this->_signingBureaucrat = rhs._signingBureaucrat;
		this->_executingBureaucrat = rhs._executingBureaucrat;
		this->_intern = rhs._intern;
	}

	return *this;
}


OfficeBlock::~OfficeBlock() {

}


void	OfficeBlock::setSigningBureaucrat(Bureaucrat* bureaucrat) {

	this->_signingBureaucrat = bureaucrat;
}


void	OfficeBlock::setExecutingBureaucrat(Bureaucrat* bureaucrat) {

	this->_executingBureaucrat = bureaucrat;
}


void	OfficeBlock::setIntern(Intern* intern) {

	this->_intern = intern;
}


void	OfficeBlock::doBureaucracy(std::string const& formName, std::string const& target) {

	std::cout << "-------- Form Start --------" << std::endl;

	this->_check_workers();

	AForm*	form = this->_intern->makeForm(formName, target);
	if (form == NULL) {
		throw OfficeBlock::UnknownFormException("Unknown form name : " + formName);
	}

	this->_signingBureaucrat->signForm(*form);
	this->_executingBureaucrat->executeForm(*form);

	std::cout << "-------- Form Complete --------" << std::endl << std::endl;
}


void	OfficeBlock::_check_workers() const {

	if (this->_signingBureaucrat == NULL) {
		throw OfficeBlock::MissingWorkerException("The Office Block is missing its signing Bureaucrat");
	} else if (this->_executingBureaucrat == NULL) {
		throw OfficeBlock::MissingWorkerException("The Office Block is missing its executing Bureaucrat");
	} else if (this->_intern == NULL) {
		throw OfficeBlock::MissingWorkerException("The Office Block is missing its intern");
	}
}
