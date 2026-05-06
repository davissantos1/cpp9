/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <dasimoes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 17:03:17 by dasimoes          #+#    #+#             */
/*   Updated: 2026/05/05 18:35:39 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <algorithm>
# include <sstream>
# include <stack>

class	RPN
{
	public:
		RPN();
		~RPN();
		RPN( const RPN& other );
		RPN&	operator=( const RPN& other );
		void	calculate( std::string expression );
		class	WrongFormatException: public std::exception
		{
			const char*	what() const throw();
		};
		class	ImpossibleExpressionException: public std::exception
		{
			const char*	what() const throw();
		};
};

#endif
