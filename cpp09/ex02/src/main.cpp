#include "../include/PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac < 2 || ac > 5000)
    {
        std::cout << "Error" << std::endl;
        return (1);
    }
    PmergeMe test;
    try
    {
        test.sort(av);
    }
    catch(PmergeMe::SortingError& e)
    {
        std::cerr << e.what() << '\n';
    }
}