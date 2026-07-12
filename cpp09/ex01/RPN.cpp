#include "RPN.hpp"
#include <sstream>
#include <cstdlib>
#include <stdexcept>
#include <cctype>

RPN::RPN() {}

RPN::RPN(const RPN& other) : _stack(other._stack) {}

RPN& RPN::operator=(const RPN& other)
{
	if (this != &other)
		_stack = other._stack;
	return *this;
}

RPN::~RPN() {}

bool RPN::isOperator(const std::string& token) const
{
	return (token == "+" || token == "-" || token == "*" || token == "/");
}

long RPN::popOperand()
{
	if (_stack.empty())
		throw std::runtime_error("Error");
	long value = _stack.back();
	_stack.pop_back();
	return value;
}

void RPN::applyOperator(const std::string& op)
{
	long rhs = popOperand();
	long lhs = popOperand();
	long result = 0;

	if (op == "+")
		result = lhs + rhs;
	else if (op == "-")
		result = lhs - rhs;
	else if (op == "*")
		result = lhs * rhs;
	else if (op == "/")
	{
		if (rhs == 0)
			throw std::runtime_error("Error");
		result = lhs / rhs;
	}
	_stack.push_back(result);
}

void RPN::processToken(const std::string& token)
{
	if (isOperator(token))
	{
		applyOperator(token);
		return;
	}

	if (token.size() != 1 || !std::isdigit(static_cast<unsigned char>(token[0])))
		throw std::runtime_error("Error");

	long value = std::atol(token.c_str());
	_stack.push_back(value);
}

long RPN::evaluate(const std::string& expression)
{
	_stack.clear();

	std::istringstream iss(expression);
	std::string token;

	while (iss >> token)
		processToken(token);

	if (_stack.size() != 1)
		throw std::runtime_error("Error");

	return _stack.back();
}
