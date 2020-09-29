/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ShrubberyCreationForm.cpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/29 16:03:58 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/09/29 16:17:49 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

#include <fstream>


ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
Form("ShrubberyCreationForm", 145, 137), _target(target) {

}


ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& src) :
Form(src) {

	*this = src;
}


ShrubberyCreationForm&	ShrubberyCreationForm::operator=(ShrubberyCreationForm const& rhs) {

	if (this != &rhs) {
		Form::operator=(rhs);
		this->_target = rhs._target;
	}

	return *this;
}


ShrubberyCreationForm::~ShrubberyCreationForm() {

}


std::ostream&	operator<<(std::ostream& o, ShrubberyCreationForm const& i) {

	o << "ShrubberyCreationForm targeted to " << i.getTarget() << std::endl;
	return o;
}


std::string const&	ShrubberyCreationForm::getTarget() const {

	return this->_target;
}


void				ShrubberyCreationForm::action() const {

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
