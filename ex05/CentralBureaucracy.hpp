/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   CentralBureaucracy.hpp                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/30 14:56:38 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/09/30 16:06:35 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once


#include "OfficeBlock.hpp"

#include <iostream>
#include <string>


class CentralBureaucracy {

public:

	CentralBureaucracy();
	~CentralBureaucracy();

	void	feed(Bureaucrat* bureaucrat) const;
	void	queueUp(std::string* customer);
	void	doBureaucracy() const;

private:

	CentralBureaucracy(CentralBureaucracy const& src);
	CentralBureaucracy& operator=(CentralBureaucracy const& rhs);

	OfficeBlock**	_offices;
	int				_queueCeiling;
	std::string**	_queue;

	void			_enlargeQueue(int newCeiling);
	void			_clear();

};

std::ostream&	operator<<(std::ostream& o, CentralBureaucracy const& i);
