/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   OfficeBlock.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/30 12:58:26 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/09/30 16:04:50 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once


#include "Bureaucrat.hpp"
#include "Intern.hpp"

class OfficeBlock {

public:

	OfficeBlock();
	OfficeBlock(Bureaucrat& signingBureaucrat, Bureaucrat& executingBureaucrat, Intern& intern);
	~OfficeBlock();

	Bureaucrat*	getSigningBureaucrat() const;
	Bureaucrat*	getExecutingBureaucrat() const;
	Intern*		getIntern() const;

	void	setSigningBureaucrat(Bureaucrat* bureaucrat);
	void	setExecutingBureaucrat(Bureaucrat* bureaucrat);
	void	setIntern(Intern* intern);

	void	doBureaucracy(std::string const& formName, std::string const& target);

private:

	OfficeBlock(OfficeBlock const& src);
	OfficeBlock& operator=(OfficeBlock const& rhs);

	Bureaucrat*	_signingBureaucrat;
	Bureaucrat*	_executingBureaucrat;
	Intern*		_intern;

};

std::ostream&	operator<<(std::ostream& o, OfficeBlock const& i);
