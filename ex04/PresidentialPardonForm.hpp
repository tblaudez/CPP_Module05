/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PresidentialPardonForm.hpp                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/29 15:19:51 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/09/30 12:37:40 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once


#include "ATargetedForm.hpp"


class PresidentialPardonForm : public ATargetedForm {

public:

	PresidentialPardonForm(std::string target="target");
	PresidentialPardonForm(PresidentialPardonForm const& src);
	PresidentialPardonForm& operator=(PresidentialPardonForm const& rhs);
	virtual ~PresidentialPardonForm();

private:

	virtual void	_action() const;

};
