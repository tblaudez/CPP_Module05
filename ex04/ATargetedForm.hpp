/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ATargetedForm.hpp                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/30 12:23:45 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/10/09 13:06:51 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once


#include "AForm.hpp"

#include <ostream> // duh..


class ATargetedForm : public AForm {

public:

	ATargetedForm(std::string const& name="ATargetedForm", int signingGrade=150,
		int executingGrade=150, std::string const& target="target");
	ATargetedForm(ATargetedForm const& src);
	ATargetedForm& operator=(ATargetedForm const& rhs);
	virtual ~ATargetedForm();

	std::string const&	getTarget() const;
	virtual void		execute(Bureaucrat const& executor) const;

protected:

	std::string			_target;

private:

	virtual void		_action() const = 0;

};

std::ostream&	operator<<(std::ostream& o, ATargetedForm const& i);
