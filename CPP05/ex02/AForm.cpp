/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 16:31:24 by malaamir          #+#    #+#             */
/*   Updated: 2025/11/23 17:41:09 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name("Default"), isSigned(false), signGrade(42), executeGrade(42) {}

AForm::AForm(const std::string &name, int signGrade, int executeGrade)
	: name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade)
{
	if (signGrade < 1 || executeGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || executeGrade > 150)
		throw GradeTooLowException();
}
AForm::AForm(const AForm &other)
	: name(other.name), isSigned(other.isSigned), signGrade(other.signGrade), executeGrade(other.executeGrade) {}

AForm::~AForm() {}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
		this->isSigned = other.isSigned;
	return *this;
}

const std::string &AForm::getName() const { return name; }

bool AForm::getIsSigned() const { return isSigned; }

int AForm::getSignGrade() const { return signGrade; }

int AForm::getExecuteGrade() const { return executeGrade; }


const char *AForm::GradeTooHighException::what() const throw()
{
	return "Form grade is too high!";
}
const char *AForm::GradeTooLowException::what() const throw()
{
	return "Form grade is too low!";
}
const char *AForm::FormNotSignedException::what() const throw()
{
	return "Form is not signed!";
}
void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > signGrade)
		throw GradeTooLowException();
	isSigned = true;
}

void AForm::execute(const Bureaucrat &executor) const
{
	if (!isSigned)
		throw FormNotSignedException();
	if (executor.getGrade() > executeGrade)
		throw GradeTooLowException();
	executeAction(executor);
}

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
    os << "AForm: " << form.getName() << " | Signed: ";

    if (form.getIsSigned())
    {
        os << "Yes";
    }
    else
    {
        os << "No";
    }

    os << " | Sign Grade: " << form.getSignGrade()
       << " | Execute Grade: " << form.getExecuteGrade();

    return os;
}