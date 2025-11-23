/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 17:49:32 by malaamir          #+#    #+#             */
/*   Updated: 2025/11/23 18:10:14 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}
Intern::Intern(const Intern &other)
{
	(void)other;
}
Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return *this;
}
Intern::~Intern() {}

AForm *Intern::MakePresidentialPardon(const std::string &target)
{
	return new PresidentialPardonForm(target);
}
AForm *Intern::MakeRobotomyRequest(const std::string &target)
{
	return new RobotomyRequestForm(target);
}
AForm *Intern::MakeShrubberyCreation(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
	
	AForm* (Intern::*formCreators[3])(const std::string &target) = {
		&Intern::MakePresidentialPardon,
		&Intern::MakeRobotomyRequest,
		&Intern::MakeShrubberyCreation
	};
	
	std::string formNames[3] = {
		"presidential pardon",
		"robotomy request",
		"shrubbery creation"
	};
	
	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
		{
			std::cout << "Intern creates " << formName << " form." << std::endl;
			return (this->*formCreators[i])(target);
		}
	}

	std::cerr << "Error: Unknown form name '" << formName << "'." << std::endl;
	return NULL;
}