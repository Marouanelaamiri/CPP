/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 17:49:56 by malaamir          #+#    #+#             */
/*   Updated: 2025/11/23 18:09:07 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
public:
    Intern();
    Intern(const Intern &other);
    Intern &operator=(const Intern &other);
    ~Intern();

	AForm *MakePresidentialPardon(const std::string &target);
	AForm *MakeRobotomyRequest(const std::string &target);
	AForm *MakeShrubberyCreation(const std::string &target);
    AForm *makeForm(const std::string &formName, const std::string &target);
};
#endif
