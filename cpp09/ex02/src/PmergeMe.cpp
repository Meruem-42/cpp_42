#include "../include/PmergeMe.hpp"


// PmergeMe::PmergeMe(char **av)
// {
//     int i = 1;
//     while(av[i] != NULL)
//     {
//         std::string input = av[i];
//         std::stringstream ss(input);
//         std::string line = "";
//         std::getline(ss, line);
//         if (isdigit(line[0]))
//         {
//             vect_.push_back(atoi(line.c_str()));
//             deq_.push_back(atoi(line.c_str()));
//         }
//         else
//             throw ErrorPmergeMe();
//         ++i;
//     }
// }


PmergeMe::PmergeMe()
{

}


void PmergeMe::print_containers_class()
{
    std::cout << "vector container :" << std::endl;
    for (std::vector<int>::iterator it = vect_.begin(); it != vect_.end(); ++it)
    {
        std::cout << "\t" << *it << std::endl;
    }
    std::cout << "dequeu container :" << std::endl;
    for (std::deque<int>::iterator it = deq_.begin(); it != deq_.end(); ++it)
    {
        std::cout << "\t" << *it << std::endl;
    }
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

void PmergeMe::binary_search(std::vector<std::pair<int, int> > labels)
{
    std::vector<int> jacobsthal;
    int jb_init[] = {1,3,5,11,21,43,85,171,341,683,1365,2731};

    for (size_t i = 0; i < sizeof(jb_init)/sizeof(jb_init[0]); ++i)
    {
        jacobsthal.push_back(jb_init[i]);
    }


    for (unsigned int i = 0; i < labels.size(); ++i)
    {
        int jb_index = jacobsthal[i] - 1;   // 0-based
        if (jb_index >= (int)labels.size())
            break;

        std::pair<int,int> to_insert = labels[jb_index];
        int loser = to_insert.second;
        int winner = to_insert.first;

        // find winner position in vect_
        std::vector<int>::iterator winner_it = std::find(vect_.begin(), vect_.end(), winner);

        // binary search only in [begin, winner_it)
        std::vector<int>::iterator lo = vect_.begin();
        std::vector<int>::iterator hi = winner_it;

        while (lo < hi)
        {
            std::vector<int>::iterator mid = lo + (hi - lo) / 2;
            if (*mid < loser)
                lo = mid + 1;
            else
                hi = mid;
        }

        // insert loser at position lo
        vect_.insert(lo, loser);
    }

    for (unsigned int i = 0; i < labels.size(); ++i)
    {
        if(std::find(jacobsthal.begin(), jacobsthal.end(), i + 1) != jacobsthal.end())
            continue;

        std::pair<int,int> to_insert = labels[i];
        int loser = to_insert.second;
        int winner = to_insert.first;

        // find winner position in vect_
        std::vector<int>::iterator winner_it = std::find(vect_.begin(), vect_.end(), winner);

        // binary search only in [begin, winner_it)
        std::vector<int>::iterator lo = vect_.begin();
        std::vector<int>::iterator hi = winner_it;

        while (lo < hi)
        {
            std::vector<int>::iterator mid = lo + (hi - lo) / 2;
            if (*mid < loser)
                lo = mid + 1;
            else
                hi = mid;
        }

        // insert loser at position lo
        vect_.insert(lo, loser);
    }
}

void PmergeMe::sortVector(std::vector<int> &to_sort)
{
    if(to_sort.size() < 2)
    {
        vect_.push_back(to_sort[0]);
        return ;
    }
    std::vector<std::pair<int, int> > labels;
    std::vector<int> winners;

    for (std::vector<int>::iterator it = to_sort.begin(); it != to_sort.end(); )
    {
        if (it + 1 != to_sort.end())
        {
            int a = *it;
            int b = *(it + 1);
            if (a < b)
            {
                labels.push_back(std::make_pair(b, a));
                winners.push_back(b);
            }
            else
            {
                labels.push_back(std::make_pair(a, b));
                winners.push_back(a);
            }
            it += 2;
        }
        else
        {
            winners.push_back(*it);
            ++it;
        }
    }
    sortVector(winners);
    binary_search(labels);
    print_containers_class();
} 

void PmergeMe::sort(char **av)
{
    std::vector<int> vect_input;

    int i = 1;
    while(av[i] != NULL)
    {
        std::string input = av[i];
        std::stringstream ss(input);
        std::string line = "";
        std::getline(ss, line);
        if (isdigit(line[0]))
        {
            vect_input.push_back(atoi(line.c_str()));
        }
        // else
        //     return (NULL);
        ++i;
    }    
    sortVector(vect_input);
}



