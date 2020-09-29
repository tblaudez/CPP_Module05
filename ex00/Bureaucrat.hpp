/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/29 12:51:40 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/09/29 13:32:29 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once


#include <iostream>
#include <stdexcept>
#include <string>


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

	class GradeTooHighException : public std::runtime_error {
		public:
			GradeTooHighException() : std::runtime_error("Grade is less than 1") {}
	};

	class GradeTooLowException : public std::runtime_error {
		public:
			GradeTooLowException() : std::runtime_error("Grade is more than 150") {}
	};

private:

	void				_check_grade();

	std::string const	_name;
	int					_grade;

};

std::ostream&	operator<<(std::ostream& o, Bureaucrat const& i);
