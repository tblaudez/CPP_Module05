/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   OfficeBlock.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/30 13:10:18 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/09/30 14:51:17 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "OfficeBlock.hpp"


OfficeBlock::OfficeBlock() : _signingBureaucrat(NULL), _executingBureaucrat(NULL),
_intern(NULL) {

}


OfficeBlock::OfficeBlock(Bureaucrat& signingBureaucrat, Bureaucrat& executingBureaucrat,
Intern& intern) : _signingBureaucrat(&signingBureaucrat),
_executingBureaucrat(&executingBureaucrat), _intern(&intern) {

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


std::ostream&	operator<<(std::ostream& o, OfficeBlock const& i) {

	(void)i;
	o << "Office Block, ready to roll";
	return o;
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

	AForm*	form = this->_intern->makeForm(formName, target);
	if (form == NULL) {
		return;
	}

	this->_signingBureaucrat->signForm(*form);
	this->_executingBureaucrat->executeForm(*form);

	std::cout << "-------- Form Complete --------" << std::endl;
}
