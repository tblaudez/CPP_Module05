/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   CentralBureaucracy.cpp                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/30 15:07:25 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/09/30 16:08:56 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "CentralBureaucracy.hpp"


CentralBureaucracy::CentralBureaucracy() : _offices(new OfficeBlock*[20]()),
_queueCeiling(20), _queue(new std::string*[this->_queueCeiling]()) {

	for (int i=0; i<20; i++) {
		this->_offices[i] = new OfficeBlock;
		this->_offices[i]->setIntern(new Intern);
	}
}


CentralBureaucracy::CentralBureaucracy(CentralBureaucracy const& src) {

	*this = src;
}


CentralBureaucracy&	CentralBureaucracy::operator=(CentralBureaucracy const& rhs) {

	if (this != &rhs) {
		this->_clear();
		std::copy(rhs._offices, rhs._offices + 20, this->_offices);
		std::copy(rhs._queue, rhs._queue + rhs._queueCeiling, this->_queue);
		this->_queueCeiling = rhs._queueCeiling;
	}

	return *this;
}


CentralBureaucracy::~CentralBureaucracy() {

	this->_clear();
	delete[] this->_offices;
	delete[] this->_queue;
}


std::ostream&	operator<<(std::ostream& o, CentralBureaucracy const& i) {

	(void)i;
	o << "Central Bureaucracy";
	return o;
}


void	CentralBureaucracy::feed(Bureaucrat* bureaucrat) const {

	for (int i=0; i<20; i++) {
		if (this->_offices[i]->getSigningBureaucrat() == NULL) {
			this->_offices[i]->setSigningBureaucrat(bureaucrat);
		}
		else if (this->_offices[i]->getExecutingBureaucrat() == NULL) {
			this->_offices[i]->setExecutingBureaucrat(bureaucrat);
		}
	}
}


void	CentralBureaucracy::queueUp(std::string* customer) {

	for (int i=0; i<this->_queueCeiling; i++) {
		if (this->_queue[i] == NULL) {
			this->_queue[i] = customer;
			return;
		}
	}

	this->_enlargeQueue(this->_queueCeiling + 50);
	this->queueUp(customer);
}


void	CentralBureaucracy::doBureaucracy() const {

	std::string	const forms[3] = {"presidential pardon", "shrubbery creation", "robotomy request"};

	for (int i=0; i<this->_queueCeiling; i++) {
		try {
			this->_offices[i%20]->doBureaucracy(forms[rand()%3], *(this->_queue[i]));
		} catch(std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}

}


void	CentralBureaucracy::_clear() {

	for (int i=0; i<this->_queueCeiling; i++) {
		delete this->_queue[i];
	}
	for (int i=0; i<20; i++) {
		delete this->_offices[i]->getIntern();
		delete this->_offices[i];
	}
}


void	CentralBureaucracy::_enlargeQueue(int newCeiling) {

	std::string**	newArray = new std::string*[newCeiling]();

	std::copy(this->_queue, this->_queue + this->_queueCeiling, newArray);
	delete[] this->_queue;

	this->_queue = newArray;
	this->_queueCeiling = newCeiling;
}
