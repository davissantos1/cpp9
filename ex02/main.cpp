/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <dasimoes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 19:21:09 by dasimoes          #+#    #+#             */
/*   Updated: 2026/05/07 14:45:54 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout	<< "No arguments provided, input one or more arguments!\n"
					<< "type in ./PmergeMe <positive-int> ..."
					<< std::endl;
		return (1);
	}
	try
	{
		PmergeMe p(av + 1);
		p.sort();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (3);
	}
	return (0);
}
