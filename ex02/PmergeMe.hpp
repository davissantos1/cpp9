/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <dasimoes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 19:34:06 by dasimoes          #+#    #+#             */
/*   Updated: 2026/05/13 15:14:01 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME
# define PMERGE_ME

# include <iostream>
# include <algorithm>
# include <string>
# include <vector>
# include <deque>
# include <sys/time.h>

class PmergeMe
{
	private:
		std::vector<int>	v;
		std::deque<int>		d;
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe( char** av );
		PmergeMe( const PmergeMe& other );
		PmergeMe&	operator=( const PmergeMe& other );
		void	printVector();
		void	printDeque();
		void	sort();
		class	DuplicateElementException: public std::exception
		{
			const char*	what() const throw();
		};
		class	NegativeElementException: public std::exception
		{
			const char*	what() const throw();
		};
};

#endif
