/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <dasimoes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 19:33:52 by dasimoes          #+#    #+#             */
/*   Updated: 2026/05/13 15:16:33 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

static bool	isInvalid(int i)
{
	if (i < 0)
		return (true);
	return (false);
}

static long long getTimeInMicroseconds()
{
	struct timeval time;

	gettimeofday(&time, NULL);
	return ((long long)time.tv_sec * 1000000 + time.tv_usec);
} 

static std::vector<size_t> generate_jacobsthal(size_t n)
{
	std::vector<size_t> j;

	if (n == 0)
		return (j);
	j.push_back(1);
	if (n == 1)
		return (j);
	j.push_back(3);
	while (j.back() < n)
	{
		size_t next = j[j.size() - 1] + 2 * j[j.size() - 2];
		j.push_back(next);
		if (next > n)
			break ;
	}
	return (j);
}

template <typename T>
static	void mergeInsert(T&	target)
{
	if (target.size() <= 1)
		return ;

	bool has_stray = (target.size() % 2 != 0);

	int stray = 0;
	if (has_stray)
	{
		stray = target.back();
		target.pop_back();
	}

	T winners;
	T losers;

	for (size_t i = 0; i < target.size(); i += 2)
	{
		if (target[i] < target[i + 1])
		{
			losers.push_back(target[i]);
			winners.push_back(target[i + 1]);
		}
		else
		{
			losers.push_back(target[i + 1]);
			winners.push_back(target[i]);
		}
	}

	mergeInsert(winners);

	T main_chain = winners;
	main_chain.insert(main_chain.begin(), losers[0]);

	std::vector<size_t> jacob = generate_jacobsthal(losers.size());
	size_t last_inserted_idx = 1;

	for (size_t i = 1; i < jacob.size(); i++)
	{
		size_t current_jacob_idx = jacob[i];
		
		if (current_jacob_idx >= losers.size())
			current_jacob_idx = losers.size();

		for (size_t j = current_jacob_idx - 1; j >= last_inserted_idx; j--)
		{
			typename T::iterator it_jacob = std::lower_bound(main_chain.begin(), main_chain.end(), losers[j]);
			main_chain.insert(it_jacob, losers[j]);
			if (j == 0)
				break ;
		}
		last_inserted_idx = current_jacob_idx;
		if (last_inserted_idx >= losers.size())
			break ;
	}

	if (has_stray)
	{
		typename T::iterator it = std::lower_bound(main_chain.begin(), main_chain.end(), stray);
		main_chain.insert(it, stray);
	}

	target = main_chain;
}

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe( char** av )
{
	for (int i = 0; av[i]; i++)
	{
		int val = std::atoi(av[i]);
		if (isInvalid(val))
			throw (NegativeElementException());
			
		for (size_t j = 0; j < this->v.size(); j++)
		{
			if (val == this->v[j])
				throw (DuplicateElementException());
		}

		this->v.push_back(std::atoi(av[i]));
		this->d.push_back(std::atoi(av[i]));
	}
}

PmergeMe::PmergeMe( const PmergeMe& other )
{
	if (this != &other)
		*this = other;
}

PmergeMe&		PmergeMe::operator=( const PmergeMe& other )
{
	if (this != &other)
	{
		this->v = other.v;
		this->d = other.d;
	}
	return (*this);
}

void		PmergeMe::printVector()
{
	for (size_t i = 0; i < this->v.size(); i++)
		std::cout << this->v[i] << ' ';
	std::cout << std::endl;
}

void		PmergeMe::printDeque()
{
	for (size_t i = 0; i < this->d.size(); i++)
		std::cout << this->d[i] << ' ';
	std::cout << std::endl;
}

void		PmergeMe::sort()
{
	std::cout << "Before:  ";
	this->printVector();

	long long startVector = getTimeInMicroseconds();
	mergeInsert(this->v);
	long long endVector = getTimeInMicroseconds();

	long long startDeque = getTimeInMicroseconds();
	mergeInsert(this->d);
	long long endDeque = getTimeInMicroseconds();

	std::cout << "After:   ";
	this->printVector();

	std::cout	<< "Time to process a range of " 
				<< this->v.size()
				<< " elements with std::vector :  "
				<< (endVector - startVector)
				<< "us "
				<< std::endl;

	std::cout	<< "Time to process a range of " 
				<< this->d.size()
				<< " elements with std::deque :  "
				<< (endDeque- startDeque)
				<< "us "
				<< std::endl;
}

const char*	PmergeMe::NegativeElementException::what() const throw()
{
	return ("Error");
}

const char*	PmergeMe::DuplicateElementException::what() const throw()
{
	return ("Error");
}
