/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PresidentialPardonForm.hpp                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/29 15:19:51 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/10/09 13:00:25 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once


#include "AForm.hpp"


class PresidentialPardonForm : public AForm {

public:

	PresidentialPardonForm(std::string const& target="target");
	PresidentialPardonForm(PresidentialPardonForm const& src);
	PresidentialPardonForm& operator=(PresidentialPardonForm const& rhs);
	virtual ~PresidentialPardonForm();

	std::string const&	getTarget() const;

private:

	virtual void	_action() const;

	std::string		_target;

};

std::ostream&	operator<<(std::ostream& o, PresidentialPardonForm const& i);
