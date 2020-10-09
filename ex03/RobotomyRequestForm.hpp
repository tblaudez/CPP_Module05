/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RobotomyRequestForm.hpp                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/29 15:54:05 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/10/09 12:57:42 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once


#include "AForm.hpp"


class RobotomyRequestForm : public AForm {

public:

	RobotomyRequestForm(std::string const& target="target");
	RobotomyRequestForm(RobotomyRequestForm const& src);
	RobotomyRequestForm& operator=(RobotomyRequestForm const& rhs);
	virtual ~RobotomyRequestForm();

	std::string const&	getTarget() const;

private:

	virtual void	_action() const;

	std::string		_target;

};

std::ostream&	operator<<(std::ostream& o, RobotomyRequestForm const& i);
