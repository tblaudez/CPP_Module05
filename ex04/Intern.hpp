/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/30 11:03:41 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/09/30 14:32:34 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once


#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"


class Intern {

public:

	Intern();
	Intern(Intern const& src);
	Intern& operator=(Intern const& rhs);
	~Intern();

	AForm*	makeForm(std::string const& formName, std::string const& target) const;

private:

	AForm*	_makePresidentialPardonForm(std::string const& target) const;
	AForm*	_makeRobotomyRequestForm(std::string const& target) const;
	AForm*	_makeShrubberyCreationForm(std::string const& target) const;

};

std::ostream&	operator<<(std::ostream& o, Intern const& i);
