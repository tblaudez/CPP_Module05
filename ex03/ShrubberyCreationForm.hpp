/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ShrubberyCreationForm.hpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/29 16:02:04 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/09/30 11:07:07 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once


#include "Form.hpp"


class ShrubberyCreationForm : public Form {

public:

	ShrubberyCreationForm(std::string target="target");
	ShrubberyCreationForm(ShrubberyCreationForm const& src);
	ShrubberyCreationForm& operator=(ShrubberyCreationForm const& rhs);
	~ShrubberyCreationForm();

	std::string const&	getTarget() const;

private:

	std::string	_target;

	virtual void	_action() const;

};

std::ostream&	operator<<(std::ostream& o, ShrubberyCreationForm const& i);
