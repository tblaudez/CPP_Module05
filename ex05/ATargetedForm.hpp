/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ATargetedForm.hpp                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/30 12:23:45 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/09/30 14:36:26 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once


#include "AForm.hpp"


class ATargetedForm : public AForm {

public:

	ATargetedForm(std::string const& name="ATargetedForm", int signingGrade=150, int executingGrade=150, std::string const& target="target");
	ATargetedForm(ATargetedForm const& src);
	ATargetedForm& operator=(ATargetedForm const& rhs);
	virtual ~ATargetedForm();

	std::string const&	getTarget() const;
	virtual void		execute(Bureaucrat const& executor) const;
	virtual void		print(std::ostream& o) const;

protected:

	std::string const	_target;

private:

	virtual void		_action() const = 0;

};
