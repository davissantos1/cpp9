/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <dasimoes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 13:32:33 by dasimoes          #+#    #+#             */
/*   Updated: 2026/05/05 12:39:12 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# define PATH_DB "data.csv"

# include <iostream>
# include <fstream>
# include <sstream>
# include <algorithm>
# include <map>

class	BitcoinExchange
{
	private:
		std::map<std::string, float> _db;
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange( std::string input );
		BitcoinExchange( const BitcoinExchange& other );
		BitcoinExchange&	operator=( const BitcoinExchange& other );
		void	showRates(std::string file);
		class	InvalidFileException: public std::exception
		{
			virtual const char*	what() const throw();
		};
		class	NoDatabaseException: public std::exception
		{
			virtual const char*	what() const throw();
		};
};

#endif
