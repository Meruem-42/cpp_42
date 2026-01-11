#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cmath>

class PmergeMe
{
private:
    std::vector<int> vect_;
    std::deque<int>  deq_;


    void sortVector(std::vector<int> &winners);
    void sortDeque();

public:
    PmergeMe();
    // PmergeMe(char **av);
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();

    class ErrorPmergeMe : public std::exception
    {
    public :
        const char *what() const throw();
    };
    void print_containers_class();
    void binary_search(std::vector<std::pair<int, int> > labels);
    void sort(char **av);
};

void print_containers(std::vector<int> &vect, std::deque<int> &deq);

template <typename C>
void print_container(const C& container)
{
    std::cout << "container values :" << std::endl;
    for (typename C::const_iterator it = container.begin(); it != container.end(); ++it)
    {
        std::cout << "\t" << *it << std::endl;
    }
}

#endif