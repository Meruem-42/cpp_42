#include "../include/MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack()
    : std::stack<T>()
{
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& other)
    : std::stack<T>(other)
{

}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack& other)
{
    std::stack<T>::operator=(other);
    return (*this);
}

template <typename T>
MutantStack<T>::~MutantStack()
{
}




template<typename T>
MutantStack<T>::iterator::iterator()
    : ptr_(NULL)
{
}

template<typename T>
MutantStack<T>::iterator &MutantStack<T>::iterator::operator=(const MutantStack<T>::iterator& other)
{
    
}

template<typename T>
T* MutantStack<T>::iterator::operator++()
{
}

template<typename T>
T* MutantStack<T>::iterator::operator--()
{

}

template<typename T>
bool MutantStack<T>::iterator::operator==(const MutantStack<T>::iterator& other) const
{

}
template<typename T>
bool MutantStack<T>::iterator::operator!=(const MutantStack<T>::iterator& other) const
{

}


