/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 15:30:40 by malaamir          #+#    #+#             */
/*   Updated: 2026/02/02 11:19:13 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    // The subject requires the program to take the input file as an argument.
    if (argc != 2)
    {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    try
    {
        BitcoinExchange btc;

        // 1. Load the database (data.csv)
        // We assume "data.csv" is in the current directory, as per standard project layout.
        btc.loaddatabase("data.csv");

        // 2. Process the input file provided as an argument (input.txt)
        btc.processinputfile(argv[1]);
    }
    catch (const std::exception &e)
    {
        // Catch critical errors (like missing data.csv) and exit gracefully
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}