#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cmath>
#include <ctime>

class PmergeMe
{
private:
    std::vector<int> vect_;
    std::deque<int>  deq_;
    std::vector<int> jacobsthal_;


    void sortVector(std::vector<int> &winners);
    void sortDeque(std::deque<int> &winners);

public:
    PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();

    class SortingError : public std::exception
    {
    public :
        const char *what() const throw();
    };
    void binary_search_vect(std::vector<std::pair<int, int> > labels);
    void binary_search_deq(std::deque<std::pair<int, int> > labels);
    void isSorted();
    void print_recap(std::vector<int> vect_input, double datamg_time_ms, double vect_time_ms, double deq_time_ms);
    void sort(char **av);
};

template <typename C>
void print_container(const C& container)
{
    std::cout << "container values :" << std::endl;
    for (typename C::const_iterator it = container.begin(); it != container.end(); ++it)
    {
        std::cout << "\t" << *it << std::endl;
    }
}

bool is_num(const std::string& str);


#endif