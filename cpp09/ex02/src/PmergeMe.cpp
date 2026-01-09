#include "../include/PmergeMe.hpp"

PmergeMe::PmergeMe(char **av)
{
    int i = 1;
    while(av[i] != NULL)
    {
        std::string input = av[i];
        std::stringstream ss(input);
        std::string line = "";
        std::getline(ss, line);
        // std::cout << line[0] << std::endl;
        if (isdigit(line[0]))
        {
            vect_.push_back(atoi(line.c_str()));
            deq_.push_back(atoi(line.c_str()));
        }
        else
            throw ErrorPmergeMe();
        ++i;
    }
    std::cout << *vect_.begin() << std::endl;
    std::cout << *deq_.begin() << std::endl;
    std::cout << *(--vect_.end()) << std::endl;
    std::cout << *(--deq_.end()) << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &other)
    : vect_(other.vect_), deq_(other.deq_) 
{
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    vect_ = other.vect_;
    deq_ = other.deq_;
    return (*this);
}

PmergeMe::~PmergeMe()
{
}

const char *PmergeMe::ErrorPmergeMe::what() const throw()
{
    return ("Error");
}


