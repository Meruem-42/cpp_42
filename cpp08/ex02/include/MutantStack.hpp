#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
    MutantStack();
    MutantStack(const MutantStack& other);
    MutantStack &operator=(const MutantStack& other);
    virtual ~MutantStack();

    class iterator
    {
    private :
        T* ptr_;
    public :
        iterator();
        MutantStack<T>::iterator &operator=(const MutantStack<T>::iterator& other);

        T* operator++();
        T* operator--();

        bool operator==(const MutantStack<T>::iterator& other) const;
        bool operator!=(const MutantStack<T>::iterator& other) const;
    }
};


#endif