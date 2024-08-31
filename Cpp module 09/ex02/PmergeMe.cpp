/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:12:58 by tmoutinh          #+#    #+#             */
/*   Updated: 2024/08/29 23:29:45 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp" 

PmergeMe::PmergeMe() 
{
}

PmergeMe::PmergeMe(const PmergeMe& other) 
{
    if (this != &other) 
    {
    }
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) 
{
    if (this != &other) 
    {
    }
    return (*this);
}

PmergeMe::~PmergeMe() 
{
}

/*---------------------------------------------------------------------*/

bool     PmergeMe::parse(char *argv[], std::vector<int> &vec, std::deque<int> &deq)
{
    int                 number;
    std::string         total;
    std::stringstream   stream;
	
    total += argv[0];
	for (int i = 1; argv[i]; i++)
		total += " " + std::string(argv[i]);
    stream << total;
    while (!stream.eof())
    {
        if (!(stream >> number))
            return (false);
        if (number < 0)
            return (false);
        if (std::find(vec.begin(), vec.end(), number) != vec.end())
            return (false);
        vec.push_back(number);
        deq.push_back(number);
    }
    return (true);
}



/*----------------------------- Vec Functions ----------------------------*/

void    PmergeMe::pair_split(std::vector<int> &nums, std::vector<std::vector<int> > &pairs)
{
    size_t  numPairs = std::ceil(nums.size() / 2.0);

	pairs.resize(numPairs);
	pairs.assign(numPairs, std::vector<int>(2));
    for (size_t i = 0; i < numPairs; i++)
    {
        if ((2 * i + 1) == nums.size())
        {
            pairs[i][0] = -1;
            pairs[i][1] = nums[2 * i];
        }
        else
        {
            pairs[i][0] = MAX(nums[2 * i], nums[2 * i + 1]);
            pairs[i][1] = MIN(nums[2 * i], nums[2 * i + 1]);
        }
    }
}

void PmergeMe::generateJacobsthalSequence(std::vector<size_t> &vec, size_t size)
{   
    for (size_t i = 0; i < size + 2; i++)
		vec.push_back((pow(2, i + 2) - pow(-1, i + 2)) / 3);
}

void    PmergeMe::sorter(std::vector<std::vector<int> > &result, std::vector<std::vector<int> > left, std::vector<std::vector<int> > right)
{
    result.clear();
    while(!left.empty() && !right.empty())
    {
        if (left[0][0] < right[0][0] || right[0][0] == -1)
        {
            result.push_back(left.front());
            left.erase(left.begin());
        }
        else
        {
            result.push_back(right.front());
            right.erase(right.begin());
        }
    }
    while (!left.empty())
    {
        result.push_back(left.front());
        left.erase(left.begin());
    }
    while (!right.empty())
    {
        result.push_back(right.front());
        right.erase(right.begin());
    }
}

void PmergeMe::sorting(std::vector<std::vector<int> > &pairs)
{
    std::vector<std::vector<int> >    left(pairs.begin(), pairs.begin() + pairs.size() / 2);
    std::vector<std::vector<int> >    right(pairs.begin() + pairs.size() / 2, pairs.end());

    if (pairs.size() == 1)
        return ;
    sorting(right);
    sorting(left);
    sorter(pairs, left, right);
}

void    PmergeMe::place(std::vector<int> &result, int number)
{
    int                 place;

    if (number == -1)
        return;
    place = 0;
    while ((long unsigned int)place < result.size() 
        && result[place] < number)
        place++;
    result.insert(result.begin() + place, number);
}


void    PmergeMe::merging(std::vector<int> &result, std::vector<std::vector<int> > &pairs)
{
    std::vector<size_t> vec;
    size_t                 j;

    generateJacobsthalSequence(vec, pairs.size());
    result.insert(result.begin(), pairs[0][1]);
    pairs.erase(pairs.begin());
    int i = 0;
    while (!pairs.empty() && vec[i + 1])
    {
        j = vec[2 * i + 1] - vec[2 * i];
        while (!pairs.empty() && j > 0)
        {
            if (j - 1 < pairs.size())
            {
                place(result, pairs[j - 1][1]);
                pairs.erase(pairs.begin() + j - 1);
            }
            j--;
        }
        i++;
    }
}

void    PmergeMe::print(std::vector<int> &result, std::string type)
{
        std::cout << type << " ";
    for (std::vector<int>::iterator it = result.begin(); it != result.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

double PmergeMe::mergeInsertSort(std::vector<int> &nums)
{
    double                        start, end;
    double                        interval;
    std::vector<std::vector<int> >   pairs;
    std::vector<int>                result;
    
    print(nums, "Before :");
    start = clock();
    pair_split(nums, pairs);
    sorting(pairs);
    for (size_t i = 0; i < pairs.size(); i++)
    {
        if (pairs[i][0] != -1)
            result.push_back(pairs[i][0]);
    }
    merging(result, pairs);
    end = clock();
    print(result, "After :");
    interval = (end - start) / CLOCKS_PER_SEC ;
    return (interval);
}

/*----------------------------- Dec Functions ----------------------------*/
void    PmergeMe::pair_split(std::deque<int> &nums, std::deque<std::deque<int> > &pairs)
{
    size_t  numPairs = std::ceil(nums.size() / 2.0);

	pairs.resize(numPairs);
	pairs.assign(numPairs, std::deque<int>(2));
    for (size_t i = 0; i < numPairs; i++)
    {
        if ((2 * i + 1) == nums.size())
        {
            pairs[i][0] = -1;
            pairs[i][1] = nums[2 * i];
        }
        else
        {
            pairs[i][0] = MAX(nums[2 * i], nums[2 * i + 1]);
            pairs[i][1] = MIN(nums[2 * i], nums[2 * i + 1]);
        }
    }
}


void PmergeMe::generateJacobsthalSequence(std::deque<size_t> &vec, size_t size)
{   
    for (size_t i = 0; i < size + 2; i++)
		vec.push_back((pow(2, i + 2) - pow(-1, i + 2)) / 3);
}

void    PmergeMe::sorter(std::deque<std::deque<int> > &result, std::deque<std::deque<int> > left, std::deque<std::deque<int> > right)
{
    result.clear();
    while(!left.empty() && !right.empty())
    {
        if (left[0][0] < right[0][0] || right[0][0] == -1)
        {
            result.push_back(left.front());
            left.erase(left.begin());
        }
        else
        {
            result.push_back(right.front());
            right.erase(right.begin());
        }
    }
    while (!left.empty())
    {
        result.push_back(left.front());
        left.erase(left.begin());
    }
    while (!right.empty())
    {
        result.push_back(right.front());
        right.erase(right.begin());
    }
}

void PmergeMe::sorting(std::deque<std::deque<int> > &pairs)
{
    std::deque<std::deque<int> >    left(pairs.begin(), pairs.begin() + pairs.size() / 2);
    std::deque<std::deque<int> >    right(pairs.begin() + pairs.size() / 2, pairs.end());

    if (pairs.size() == 1)
        return ;
    sorting(right);
    sorting(left);
    sorter(pairs, left, right);
}

void    PmergeMe::place(std::deque<int> &result, int number)
{
    int                 place;

    if (number == -1)
        return;
    place = 0;
    while ((long unsigned int)place < result.size() 
        && result[place] < number)
        place++;
    result.insert(result.begin() + place, number);
}


void    PmergeMe::merging(std::deque<int> &result, std::deque<std::deque<int> > &pairs)
{
    std::deque<size_t> vec;
    size_t                 j;

    generateJacobsthalSequence(vec, pairs.size());
    result.insert(result.begin(), pairs[0][1]);
    pairs.erase(pairs.begin());
    int i = 0;
    while (!pairs.empty() && vec[i + 1])
    {
        j = vec[2 * i + 1] - vec[2 * i];
        while (!pairs.empty() && j > 0)
        {
            if (j - 1 < pairs.size())
            {
                place(result, pairs[j - 1][1]);
                pairs.erase(pairs.begin() + j - 1);
            }
            j--;
        }
        i++;
    }
}

void    PmergeMe::print(std::deque<int> &result, std::string type)
{
        std::cout << type << " ";
    for (std::deque<int>::iterator it = result.begin(); it != result.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

double PmergeMe::mergeInsertSort(std::deque<int> &nums)
{
    double                        start, end;
    double                        interval;
    std::deque<std::deque<int> >   pairs;
    std::deque<int>                result;
    
    start = clock();
    pair_split(nums, pairs);
    sorting(pairs);
    for (size_t i = 0; i < pairs.size(); i++)
    {
        if (pairs[i][0] != -1)
            result.push_back(pairs[i][0]);
    }
    merging(result, pairs);
    end = clock();
    interval = (end - start) / CLOCKS_PER_SEC ;
    return (interval);
}