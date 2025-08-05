// ************************************************************************** //
//                                                                            //
//                Account.cpp for GlobalBanksters United                      //
//                Created on  : Thu Nov 20 19:43:15 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : David Derny <gd@gbu.com>                          //
//                                                                            //
// ************************************************************************** //

#include "Account.hpp"
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp() {
	std::cout << "[19920104_091532] ";
}

int	Account::getNbAccounts() {
	return (_nbAccounts);
}

int	Account::getTotalAmount() {
	return (_totalAmount);
}

int	Account::getNbDeposits() {
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals() {
	return (_totalNbWithdrawals);
}

void Account::displayAccountsInfos() {
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";"
		<< "total:" << _totalAmount << ";"
		<< "deposits:" << _totalNbDeposits << ";"
		<< "withdrawals:" << _totalNbWithdrawals << std::endl;
}

Account::Account( int initial_deposit ) {
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;

	_nbAccounts++;
	_totalAmount += _amount;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
		<< "amount:" << _amount << ";"
		<< "created" << std::endl;
}

Account::~Account() {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
		<< "amount:" << _amount << ";"
		<< "closed" << std::endl;
}

void Account::makeDeposit( int deposit ) {
	const int old_amount = _amount;
	
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
		<< "p_amount:" << old_amount << ";"
		<< "deposit:" << deposit << ";"
		<< "amount:" << _amount << ";"
		<< "nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal( int withdrawal ) {
	_displayTimestamp();
	if (_amount < withdrawal) {
		std::cout << "index:" << _accountIndex << ";"
		<< "p_amount:" << _amount << ";"
		<< "withdrawal:refused" << std::endl;

		return (false);
	}

	const int old_amount = _amount;

	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	
	std::cout << "index:" << _accountIndex << ";"
		<< "p_amount:" << old_amount << ";"
		<< "withdrawal:" << withdrawal << ";"
		<< "amount:" << _amount << ";"
		<< "nb_withdrawals:" << _nbWithdrawals << std::endl;
	return (true);
}

int Account::checkAmount() const {
	return (_amount);
}

void Account::displayStatus() const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
		<< "amount:" << _amount << ";"
		<< "deposits:" << _nbDeposits << ";"
		<< "withdrawals:" << _nbWithdrawals << std::endl;
}



// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //