/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/29 12:51:40 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/10/09 12:40:17 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once


#include <stdexcept> // runtime_error
#include <string> // duh..
#include <ostream> // duh..


class AForm; // Forward declration


class Bureaucrat {

public:

	Bureaucrat(std::string const& name="Robert", int grade=150);
	Bureaucrat(Bureaucrat const& src);
	Bureaucrat& operator=(Bureaucrat const& rhs);
	~Bureaucrat();

	std::string const&	getName() const;
	int					getGrade() const;

	void				incrementGrade();
	void				decrementGrade();
	void				executeForm(AForm const& form) const;
	void				signForm(AForm& form) const;

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

	void				_check_grade() const;

	std::string const	_name;
	int					_grade;

};

std::ostream&	operator<<(std::ostream& o, Bureaucrat const& i);
