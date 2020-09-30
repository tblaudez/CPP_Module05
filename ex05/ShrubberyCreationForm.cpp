/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ShrubberyCreationForm.cpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/29 16:03:58 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/09/30 12:42:47 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

#include <fstream>


ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
ATargetedForm("Shrubbery Creation Form", 145, 137, target) {

}


ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& src) :
ATargetedForm(src) {

	*this = src;
}


ShrubberyCreationForm&	ShrubberyCreationForm::operator=(ShrubberyCreationForm const& rhs) {

	if (this != &rhs) {
		ATargetedForm::operator=(rhs);
	}

	return *this;
}


ShrubberyCreationForm::~ShrubberyCreationForm() {

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
