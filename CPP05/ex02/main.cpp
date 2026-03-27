/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:34:03 by malaamir          #+#    #+#             */
/*   Updated: 2026/01/21 16:57:51 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

int main()
{
	Bureaucrat::GradeTooLowException highEx;
	// Seed the random number generator for Robotomy
	std::srand(std::time(0));

	std::cout << BLUE << "\n--- TEST 1: ShrubberyCreationForm (Sign: 145, Exec: 137) ---" << RESET << std::endl;
	try
	{
		// 1. Create a Bureaucrat who is weak (Grade 140).
		// He can SIGN (140 <= 145) but CANNOT EXECUTE (140 > 137).
		Bureaucrat bob("Bob", 140);
		ShrubberyCreationForm shrub("home");

		std::cout << shrub << std::endl;

		// 2. Try to Execute before Signing (Should fail)
		std::cout << "[Attempting to execute before signing...]" << std::endl;
		bob.executeForm(shrub); // Should print error: Not Signed

		// 3. Sign the form
		std::cout << "[Bob signs the form...]" << std::endl;
		bob.signForm(shrub);

		// 4. Try to Execute with weak grade (Should fail)
		std::cout << "[Bob attempts to execute...]" << std::endl;
		bob.executeForm(shrub); // Should print error: Grade too low

		// 5. Create a stronger Bureaucrat (Grade 130)
		Bureaucrat mike("Mike", 130);
		std::cout << "[Mike (Grade 130) takes over...]" << std::endl;

		// 6. Execute successfully
		mike.executeForm(shrub);
		std::cout << GREEN << "Success! Check for 'home_shrubbery' file." << RESET << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
	}

	std::cout << BLUE << "\n--- TEST 2: RobotomyRequestForm (Sign: 72, Exec: 45) ---" << RESET << std::endl;
	try
	{
		Bureaucrat roboCop("RoboCop", 40); // High rank
		RobotomyRequestForm robotomy("Bender");

		std::cout << robotomy << std::endl;

		roboCop.signForm(robotomy);

		// Run execution multiple times to test 50% randomness
		std::cout << "[Executing Robotomy 4 times to test randomness...]" << std::endl;
		for (int i = 0; i < 4; i++)
		{
			std::cout << YELLOW << "Attempt " << i + 1 << ": " << RESET;
			roboCop.executeForm(robotomy);
		}
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
	}

	std::cout << BLUE << "\n--- TEST 3: PresidentialPardonForm (Sign: 25, Exec: 5) ---" << RESET << std::endl;
	try
	{
		// Extremely high requirements
		Bureaucrat president("Zaphod", 1);
		PresidentialPardonForm pardon("Arthur Dent");

		std::cout << pardon << std::endl;

		// Direct execution check (without using Bureaucrat::executeForm wrapper)
		// This tests the AForm::execute method directly.
		pardon.beSigned(president);
		pardon.execute(president); // Should print "Zaphod Beeblebrox... etc"
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
	}

	std::cout << BLUE << "\n--- TEST 4: Polymorphism & Leaks Check ---" << RESET << std::endl;

	// Proving that AForm pointers can hold any concrete form
	AForm *form1 = new ShrubberyCreationForm("Garden");
	AForm *form2 = new RobotomyRequestForm("R2D2");
	Bureaucrat boss("Boss", 1);

	boss.signForm(*form1);
	boss.executeForm(*form1); // Creates Garden_shrubbery

	boss.signForm(*form2);
	boss.executeForm(*form2); // Drills R2D2

	// Clean up manual allocations
	delete form1;
	delete form2;

	return 0;
}