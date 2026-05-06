/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <dasimoes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 17:03:03 by dasimoes          #+#    #+#             */
/*   Updated: 2026/05/06 19:01:09 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

static bool isOnlyWhiteSpace( std::string s )
{
	bool	test = false;

	if (s.find_first_not_of(" \n\t\r\v") == std::string::npos)
		test = true;
	return (test);
}

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN( const RPN& other ) { (void) other; }

RPN&	RPN::operator=( const RPN& other ) 
{ 
	(void) other; 
	return (*this);
}

void	RPN::calculate( std::string expression )
{
	std::stringstream	ss(expression);
	std::stack<int>	expr;
	
	for (std::string tmp; std::getline(ss, tmp, ' ');)
	{
		if (tmp.length() == 1 && std::isdigit(tmp[0]))
			expr.push(std::atoi(tmp.c_str()));
		else if ((tmp == "+" || tmp == "-" || tmp == "*" || tmp == "/") && expr.size() >= 2)
		{
			int result;
			int firstValue = expr.top();	
			expr.pop();
			int secondValue = expr.top();	
			expr.pop();

			if (tmp == "+")
				result = secondValue + firstValue;
			if (tmp == "-")
				result = secondValue - firstValue;
			if (tmp == "*")
				result = secondValue * firstValue;
			if (tmp == "/")
			{
				if (firstValue == 0)
					throw (ImpossibleExpressionException());
				result = secondValue / firstValue;
			}
			expr.push(result);
		}
		else if (isOnlyWhiteSpace(tmp))
			continue;
		else
			throw (WrongFormatException());
	}
	if (expr.size() != 1)
		throw (WrongFormatException());
	std::cout << expr.top() << std::endl;
}

const char*	RPN::WrongFormatException::what() const throw()
{
	return ("Error");
}

const char*	RPN::ImpossibleExpressionException::what() const throw()
{
	return ("Error");
}
