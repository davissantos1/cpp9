/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <dasimoes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 19:21:09 by dasimoes          #+#    #+#             */
/*   Updated: 2026/05/05 17:39:45 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int ac, char **av)
{
	if (ac > 2)
	{
		std::cout	<< "Too many arguments, input a single argument!\n"
					<< "type in ./RPN \"<expression>\""
					<< std::endl;
		return (1);
	}
	else if (ac == 1)
		return (2);
	try
	{
		RPN rpn;
		rpn.calculate(av[1]);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (3);
	}
	return (0);
}
