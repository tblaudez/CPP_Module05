/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ShrubberyCreationForm.hpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/29 16:02:04 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/09/30 12:41:29 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once


#include "ATargetedForm.hpp"


class ShrubberyCreationForm : public ATargetedForm {

public:

	ShrubberyCreationForm(std::string target="target");
	ShrubberyCreationForm(ShrubberyCreationForm const& src);
	ShrubberyCreationForm& operator=(ShrubberyCreationForm const& rhs);
	~ShrubberyCreationForm();

private:

	virtual void	_action() const;

};
