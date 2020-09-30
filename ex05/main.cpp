/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/30 13:18:01 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/09/30 16:06:06 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "CentralBureaucracy.hpp"

int	main(void) {


	CentralBureaucracy cb;

	for (int i=0; i<40; i++) {
		cb.feed(new Bureaucrat("Pierre", rand()%150));
	}

	for (int i=0; i<40; i++) {
		cb.queueUp(new std::string("Jean"));
	}

	cb.doBureaucracy();

	return 0;
}
