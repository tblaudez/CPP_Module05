/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ShrubberyCreationForm.cpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/29 16:03:58 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/10/09 13:00:46 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

#include <fstream> // ofstream


ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
AForm("ShrubberyCreationForm", 145, 137), _target(target) {

}


ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& src) :
AForm(src) {

	*this = src;
}


ShrubberyCreationForm&	ShrubberyCreationForm::operator=(ShrubberyCreationForm const& rhs) {

	if (this != &rhs) {
		AForm::operator=(rhs);
		this->_target = rhs._target;
	}

	return *this;
}


ShrubberyCreationForm::~ShrubberyCreationForm() {

}


std::ostream&	operator<<(std::ostream& o, ShrubberyCreationForm const& i) {

	o << static_cast<AForm const&>(i);
	o << " - Target : " << i.getTarget();
	return o;
}


std::string const&	ShrubberyCreationForm::getTarget() const {

	return this->_target;
}


void				ShrubberyCreationForm::_action() const {

	std::ofstream	ofs(this->_target + "_shrubbery");

	ofs << "          .     .  .      +     .      .          ." << std::endl;
	ofs << "     .       .      .     #       .           ." << std::endl;
	ofs << "        .      .         ###            .      .      ." << std::endl;
	ofs << "      .      .   \"#:. .:##\"##:. .:#\"  .      ." << std::endl;
	ofs << "          .      . \"####\"###\"####\"  ." << std::endl;
	ofs << "       .     \"#:.    .:#\"###\"#:.    .:#\"  .        .       ." << std::endl;
	ofs << "  .             \"#########\"#########\"        .        ." << std::endl;
	ofs << "        .    \"#:.  \"####\"###\"####\"  .:#\"   .       ." << std::endl;
	ofs << "     .     .  \"#######\"\"##\"##\"\"#######\"                  ." << std::endl;
	ofs << "                .\"##\"#####\"#####\"##\"           .      ." << std::endl;
	ofs << "    .   \"#:. ...  .:##\"###\"###\"##:.  ... .:#\"     ." << std::endl;
	ofs << "      .     \"#######\"##\"#####\"##\"#######\"      .     ." << std::endl;
	ofs << "    .    .     \"#####\"\"#######\"\"#####\"    .      ." << std::endl;
	ofs << "            .     \"      000      \"    .     ." << std::endl;
	ofs << "       .         .   .   000     .        .       ." << std::endl;
	ofs << ".. .. ..................O000O........................ ...... ..." << std::endl;

	ofs.close();
}
