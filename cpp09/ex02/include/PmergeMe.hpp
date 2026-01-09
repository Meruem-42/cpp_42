#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>
#include <sstream>

class PmergeMe
{
private:
    std::vector<int> vect_;
    std::deque<int>  deq_;

    void sortVector();
    void sortDeque();

public:
    PmergeMe(char **av);
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();

    class ErrorPmergeMe : public std::exception
    {
    public :
        const char *what() const throw();
    };

    void sort();
};



#endif