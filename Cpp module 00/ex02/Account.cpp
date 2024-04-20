/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:21:59 by tmoutinh          #+#    #+#             */
/*   Updated: 2024/04/20 11:22:00 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account()
{
    this->_amount = 0;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    return ;
}

Account::~Account()
{
    Account::_displayTimestamp();
    std::cout << "Index:" << this->_accountIndex;
    std::cout << ";amount:" << this->_amount;
    std::cout << ";Closed" << std::endl;
    return ;
}

Account::Account(int initial_deposit)
{
    Account::_displayTimestamp();
    this->_nbAccounts += 1;
    this->_amount = initial_deposit;
    this->_totalAmount += initial_deposit;
    this->_accountIndex = this->_nbAccounts;
    std::cout << "Index:" << this->_accountIndex;
    std::cout << ";amount:" << this->_amount;
    std::cout << ";Created" << std::endl;
    return ;
}

void    Account::makeDeposit(int deposit)
{
    Account::_displayTimestamp();
    std::cout << "Index:" << this->_accountIndex;
    std::cout << ";p_amount:" << this->_amount;
    this->_nbDeposits += 1;
    this->_amount += deposit;
    this->_totalNbDeposits += 1;
    this->_totalAmount += deposit;
    std::cout << ";deposit:" << deposit;
    std::cout << ";amount:" << this->_amount;
    std::cout << ";deposits:" << this->_nbDeposits << std::endl;
}

int Account::checkAmount() const
{    
    return (this->_amount);
}

bool    Account::makeWithdrawal(int withdrawal)
{
    Account::_displayTimestamp();
    std::cout << "Index:" << this->_accountIndex;
    std::cout << ";p_amount:" << this->_amount;
    std::cout << ";withdrawal:";
    if (Account::checkAmount() < withdrawal)
    {
        std::cout << "Refused" << std::endl;
        return (false);
    }
    this->_nbWithdrawals += 1;
    this->_totalNbWithdrawals += 1;
    this->_amount -= withdrawal;
    this->_totalAmount -= withdrawal;
    std::cout << withdrawal;
    std::cout << ";amount:" << this->_amount;
    std::cout << ";withdrawls:" << this->_nbDeposits << std::endl;
    return (true);
}

void    Account::displayAccountsInfos()
{
    Account::_displayTimestamp();
    std::cout << "Accounts:" << Account::getNbAccounts();
    std::cout << ";total:" << Account::getTotalAmount();
    std::cout << ";Deposits:" << Account::getNbDeposits();
    std::cout << ";Withdraws:" << Account::getNbWithdrawals() << std::endl;
}

void  Account::displayStatus() const
{
    Account::_displayTimestamp();
    std::cout << "Index:" << this->_accountIndex;
    std::cout << ";amount:" << this->_amount;
    std::cout << ";deposits:" << this->_nbDeposits;
    std::cout << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

int Account::getNbAccounts()
{
    return(_nbAccounts);
}

int Account::getTotalAmount()
{
    return(_totalAmount);
}

int Account::getNbDeposits()
{
    return(_totalNbDeposits);
}

int Account::getNbWithdrawals()
{
    return(_totalNbWithdrawals);
}

/*Not sure if i can use*/
void    Account::_displayTimestamp()
{
    std::time_t currentTime;
    char timestamp[100];

    currentTime = std::time(0);
    std::strftime(timestamp, sizeof(timestamp), "%Y%m%d_%H%M%S", std::gmtime(&currentTime));
    std::cout << "[" << timestamp << "]";
}
