/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RobotomyRequestForm.hpp                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/29 15:54:05 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/10/09 13:10:27 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once


#include "ATargetedForm.hpp"


class RobotomyRequestForm : public ATargetedForm {

public:

	RobotomyRequestForm(std::string const& target="target");
	RobotomyRequestForm(RobotomyRequestForm const& src);
	RobotomyRequestForm& operator=(RobotomyRequestForm const& rhs);
	virtual ~RobotomyRequestForm();

private:

	virtual void	_action() const;

};
