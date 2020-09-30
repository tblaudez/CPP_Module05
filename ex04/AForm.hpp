/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AForm.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/29 13:47:29 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/09/30 14:36:17 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once


#include "Bureaucrat.hpp"

#include <iostream>
#include <string>
#include <stdexcept>


class AForm {

public:

	AForm(std::string const& name="AForm", int signingGrade=150, int executingGrade=150);
	AForm(AForm const& src);
	AForm& operator=(AForm const& rhs);
	virtual ~AForm();

	std::string const&	getName() const;
	int					getSigningGrade() const;
	int					getExecutingGrade() const;
	bool				getSigned() const;

	void				beSigned(Bureaucrat const& bureaucrat);
	virtual void		execute(Bureaucrat const& executor) const;
	virtual void		print(std::ostream& o) const = 0;

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

	std::string const	_name;
	int const			_signingGrade;
	int const			_executingGrade;
	bool				_signed;

	void				_checkGrade() const;
};

std::ostream&	operator<<(std::ostream& o, AForm const& i);
