/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   OfficeBlock.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/30 12:58:26 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/10/09 13:15:35 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once


#include "Bureaucrat.hpp"
#include "Intern.hpp"


class OfficeBlock {

public:

	OfficeBlock(Bureaucrat* signingBureaucrat=NULL, Bureaucrat* executingBureaucrat=NULL, Intern* intern=NULL);
	~OfficeBlock();

	void	setSigningBureaucrat(Bureaucrat* bureaucrat);
	void	setExecutingBureaucrat(Bureaucrat* bureaucrat);
	void	setIntern(Intern* intern);

	void	doBureaucracy(std::string const& formName, std::string const& target);

	class MissingWorkerException : public std::runtime_error {
		public:
			MissingWorkerException(std::string const& msg="The Office Block is missing a worker") :
			std::runtime_error(msg) {}
	};

	class UnknownFormException : public std::runtime_error {
		public:
			UnknownFormException(std::string const& msg="Unknown form name") :
			std::runtime_error(msg) {}
	};

private:

	OfficeBlock(OfficeBlock const& src);
	OfficeBlock& operator=(OfficeBlock const& rhs);

	Bureaucrat*	_signingBureaucrat;
	Bureaucrat*	_executingBureaucrat;
	Intern*		_intern;

	void		_check_workers() const;

};
