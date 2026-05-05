/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <dasimoes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 19:21:09 by dasimoes          #+#    #+#             */
/*   Updated: 2026/05/04 22:03:15 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>

int	main(int ac, char **av)
{
	if (ac > 2)
	{
		std::cout	<< "Too many files, input a single valid path!\n"
					<< "type in ./btc <path-to-file>"
					<< std::endl;
		return (1);
	}
	else if (ac == 1)
	{
		std::cout	<< "Error: could not open file."
					<< std::endl;
			return (2);
	}
	try
	{
		BitcoinExchange btc;
		btc.showRates(av[1]);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (3);
	}
	return (0);
}
