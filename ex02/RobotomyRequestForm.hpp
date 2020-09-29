/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RobotomyRequestForm.hpp                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/29 15:54:05 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/09/29 16:01:43 by tblaudez      ########   odam.nl         */
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

	virtual void	action() const;
};

std::ostream&	operator<<(std::ostream& o, RobotomyRequestForm const& i);
