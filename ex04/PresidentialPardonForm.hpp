/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PresidentialPardonForm.hpp                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/29 15:19:51 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/10/09 13:08:50 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once


#include "ATargetedForm.hpp"


class PresidentialPardonForm : public ATargetedForm {

public:

	PresidentialPardonForm(std::string const& target="target");
	PresidentialPardonForm(PresidentialPardonForm const& src);
	PresidentialPardonForm& operator=(PresidentialPardonForm const& rhs);
	virtual ~PresidentialPardonForm();

private:

	virtual void	_action() const;

};
