/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/29 13:47:29 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/10/09 11:58:14 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once


#include "Bureaucrat.hpp"

#include <stdexcept> // runtime_error
#include <string> // duh..
#include <ostream> // duh..


class Form {

public:

	Form(std::string const& name="Form", int signingGrade=150, int executingGrade=150);
	Form(Form const& src);
	Form& operator=(Form const& rhs);
	~Form();

	std::string const&	getName() const;
	int					getSigningGrade() const;
	int					getExecutingGrade() const;
	bool				getSigned() const;

	void				beSigned(Bureaucrat const& bureaucrat);

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

private:

	void		_checkGrade() const;

	std::string const	_name;
	int const			_signingGrade;
	int const			_executingGrade;
	bool				_signed;

};

std::ostream&	operator<<(std::ostream& o, Form const& i);
