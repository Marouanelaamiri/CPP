/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 18:10:31 by malaamir          #+#    #+#             */
/*   Updated: 2025/11/23 18:10:40 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

int main()
{
    std::cout << BLUE << "--- SETUP ---" << RESET << std::endl;
    
    // 1. We need a Boss to sign/execute the forms the Intern creates.
    Bureaucrat boss("The Boss", 1);
    
    // 2. We need the Intern (The Factory).
    Intern someRandomIntern;

    std::cout << GREEN << "Intern and Boss created." << RESET << std::endl;

    // --- TEST LIST ---
    // We will loop through 4 names: 3 valid, 1 invalid.
    const char* formNames[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon",
        "tax evasion form" // This one doesn't exist
    };
    
    const char* targets[] = {
        "Garden",
        "Bender",
        "Arthur Dent",
        "IRS"
    };

    std::cout << BLUE << "\n--- TESTING INTERN FACTORY ---" << RESET << std::endl;

    for (int i = 0; i < 4; i++)
    {
        std::cout << "\n[Requesting Form: " << YELLOW << formNames[i] << RESET << "]" << std::endl;

        // 3. Ask Intern to create the form
        AForm* form = someRandomIntern.makeForm(formNames[i], targets[i]);

        // 4. Check if form was created successfully
        if (form)
        {
            std::cout << GREEN << " -> Success! Form created: " << *form << RESET << std::endl;

            // 5. Prove it works (Sign and Execute)
            // This proves the Intern created the CORRECT specific class.
            try
            {
                boss.signForm(*form);
                boss.executeForm(*form);
            }
            catch(const std::exception& e)
            {
                std::cerr << RED << e.what() << RESET << std::endl;
            }

            // 6. IMPORTANT: The Intern allocated memory with 'new'.
            // The User (main) is responsible for deleting it.
            delete form;
        }
        else
        {
            // 7. Handle failure (Unknown form)
            std::cout << RED << " -> Failed! Intern returned NULL." << RESET << std::endl;
        }
    }

    std::cout << BLUE << "\n--- END OF TESTS ---" << RESET << std::endl;
    return 0;
}