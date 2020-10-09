/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ShrubberyCreationForm.hpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/29 16:02:04 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/10/09 13:11:44 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once


#include "AForm.hpp"


class ShrubberyCreationForm : public AForm {

public:

	ShrubberyCreationForm(std::string target="target");
	ShrubberyCreationForm(ShrubberyCreationForm const& src);
	ShrubberyCreationForm& operator=(ShrubberyCreationForm const& rhs);
	virtual ~ShrubberyCreationForm();

	std::string const&	getTarget() const;

private:

	virtual void	_action() const;

	std::string		_target;

};

std::ostream&	operator<<(std::ostream& o, ShrubberyCreationForm const& i);
