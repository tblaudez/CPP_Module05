/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PresidentialPardonForm.hpp                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/29 15:19:51 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/09/29 15:33:33 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once


#include "Form.hpp"

#include <iostream>


class PresidentialPardonForm : public Form {

public:

	PresidentialPardonForm(std::string target="target");
	PresidentialPardonForm(PresidentialPardonForm const& src);
	PresidentialPardonForm& operator=(PresidentialPardonForm const& rhs);
	virtual ~PresidentialPardonForm();

	std::string const&	getTarget() const;

private:

	std::string	_target;

	virtual void	action() const;

};

std::ostream&	operator<<(std::ostream& o, PresidentialPardonForm const& i);
