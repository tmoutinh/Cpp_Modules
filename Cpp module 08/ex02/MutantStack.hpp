/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 20:13:57 by tmoutinh          #+#    #+#             */
/*   Updated: 2024/06/21 09:30:04 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#   include <iostream>
#   include <stack>
#   include <list>

template <typename T>
class MutantStack: public std::stack<T>
{
    private:
        std::stack<T> _stack;
    public:
        MutantStack() {};
        MutantStack(const MutantStack& other) { *this = other; };
        MutantStack& operator=(const MutantStack& other)
        {
            if (this != &other)
                this->_stack = other._stack;
            return *this;
        
        };
        ~MutantStack() {};

        //Iterator features
        typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;

        iterator begin() { return this->c.begin(); }
        iterator end() { return this->c.end(); }
        const_iterator begin() const { return this->c.begin(); }
        const_iterator end() const { return this->c.end(); }
        
};

#endif