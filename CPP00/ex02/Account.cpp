/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 18:16:39 by malaamir          #+#    #+#             */
/*   Updated: 2025/10/28 20:34:05 by malaamir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit )
{
	_accountIndex =  _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	
	_nbAccounts++;
	_totalAmount += initial_deposit;

	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount
			  << ";created" << std::endl;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << " index:" <<_accountIndex << ";amount:" << _amount 
			  << ";closed" << std::endl;
}

void Account::_displayTimestamp()
{
	std::time_t curr_time = time(NULL);
	std::tm* timeinfo =std::localtime(&curr_time);
	char buffer[20];
	std::strftime(buffer, 20, "[%Y%m%d_%H%M%S]", timeinfo);
	std::cout << buffer;
}

void Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << " accounts:" << _nbAccounts
			  << ";total:" << _totalAmount
			  << ";deposits:" << _totalNbDeposits
			  << ";withdrawals:" << _totalNbWithdrawals
			  << std::endl;
}

void Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";deposits:" << _nbDeposits
			  << ";withdrawals:" << _nbWithdrawals
			  << std::endl;
}
void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";p_amount:"
			  << _amount << ";deposit:" << deposit;
	_amount += deposit;
	_nbDeposits++;
	
	_totalAmount += deposit;
	_totalNbDeposits++;
	
	std::cout << ";amount:" << _amount << ";nb_deposits:"
			  << _nbDeposits << std::endl;
}

bool  Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	
	std::cout << " index:" << _accountIndex << ";p_amount:"
			  << _amount << ";withdrawal:";
	if(_amount < withdrawal)
	{
		std::cout << "refused" << std::endl;
		return false;
	}
	std::cout << withdrawal;
	
	_amount -= withdrawal;
	_nbWithdrawals++;
	
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;

	std::cout << ";amount:" << _amount
			  << ";nb_withdrawals:"
			  << _nbWithdrawals << std::endl;
	
	return true;
}
