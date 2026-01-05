#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
public:
    MutantStack();
    MutantStack(const MutantStack &other);
    MutantStack &operator=(const MutantStack &other);
    virtual ~MutantStack();

    typedef typename Container::iterator iterator;
    iterator begin();
    iterator end();
    typedef typename Container::const_iterator const_iterator;
    const_iterator cbegin() const;
    const_iterator cend() const;
};

#include "MutantStack.tpp"

#endif