/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RobotomyRequestForm.hpp                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/29 15:54:05 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/09/30 11:07:03 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once


#include "Form.hpp"

#include <iostream>


class RobotomyRequestForm : public Form {

public:

	RobotomyRequestForm(std::string target="target");
	RobotomyRequestForm(RobotomyRequestForm const& src);
	RobotomyRequestForm& operator=(RobotomyRequestForm const& rhs);
	virtual ~RobotomyRequestForm();

	std::string const&	getTarget() const;

private:

	std::string		_target;

	virtual void	_action() const;
};

std::ostream&	operator<<(std::ostream& o, RobotomyRequestForm const& i);
