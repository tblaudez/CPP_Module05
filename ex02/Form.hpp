/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/29 13:47:29 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/09/29 15:24:00 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once


#include "Bureaucrat.hpp"

#include <iostream>
#include <string>
#include <stdexcept>


class Form {

public:

	Form(std::string name="Form", int signingGrade=150, int executingGrade=150);
	Form(Form const& src);
	Form& operator=(Form const& rhs);
	virtual ~Form();

	std::string const&	getName() const;
	int					getSigningGrade() const;
	int					getExecutingGrade() const;
	bool				getSigned() const;

	void				beSigned(Bureaucrat const& bureaucrat);
	void				execute(Bureaucrat const& executor) const;
	virtual void		action() const = 0;

	class GradeTooHighException : public std::runtime_error {
		public:
			GradeTooHighException(std::string const& msg="Grade is less than 1") :
			std::runtime_error(msg) {}
	};

	class GradeTooLowException : public std::runtime_error {
		public:
			GradeTooLowException(std::string const& msg="Grade is more than 150") :
			std::runtime_error(msg) {}
	};

	class FormNotSignedException : public std::runtime_error {
		public:
			FormNotSignedException(std::string const& msg="The form is not signed") :
			std::runtime_error(msg) {}
	};

private:

	std::string	_name;
	int const	_signingGrade;
	int const	_executingGrade;
	bool		_signed;

	void		_checkGrade() const;

};

std::ostream&	operator<<(std::ostream& o, Form const& i);
