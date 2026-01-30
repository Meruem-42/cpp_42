#include "../include/PmergeMe.hpp"


PmergeMe::PmergeMe()
{
    int jb_init[] = {1,3,5,11,21,43,85,171,341,683,1365,2731};

    for (size_t i = 0; i < 12; ++i)
    {
        jacobsthal_.push_back(jb_init[i]);
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

void PmergeMe::isSorted()
{
    for(unsigned int i = 0; i < vect_.size() - 1; ++i)
    {
        if(vect_[i] > vect_[i + 1] || deq_[i] > deq_[i + 1])
            throw SortingError();
    }
}


const char *PmergeMe::SortingError::what() const throw()
{
    return ("deque or vect is badly sorted");
}

void PmergeMe::binary_search_deq(std::deque<std::pair<int, int> > labels)
{

    for (unsigned int i = 0; i < labels.size(); ++i)
    {
        int jb_index = jacobsthal_[i] - 1;
        if (jb_index >= (int)labels.size())
            break;

        std::pair<int,int> to_insert = labels[jb_index];
        int loser = to_insert.second;
        int winner = to_insert.first;

        std::deque<int>::iterator winner_it = std::lower_bound(deq_.begin(), deq_.end(), winner);

        std::deque<int>::iterator lo = deq_.begin();
        std::deque<int>::iterator hi = winner_it;

        while (lo < hi)
        {
            std::deque<int>::iterator mid = lo + (hi - lo) / 2;
            if (*mid < loser)
                lo = mid + 1;
            else
                hi = mid;
        }

        deq_.insert(lo, loser);
    }
    for (unsigned int i = 0; i < labels.size(); ++i)
    {
        if(std::find(jacobsthal_.begin(), jacobsthal_.end(), i + 1) != jacobsthal_.end())
            continue;

        std::pair<int,int> to_insert = labels[i];
        int loser = to_insert.second;
        int winner = to_insert.first;

        std::deque<int>::iterator winner_it = std::lower_bound(deq_.begin(), deq_.end(), winner);

        std::deque<int>::iterator lo = deq_.begin();
        std::deque<int>::iterator hi = winner_it;

        while (lo < hi)
        {
            std::deque<int>::iterator mid = lo + (hi - lo) / 2;
            if (*mid < loser)
                lo = mid + 1;
            else
                hi = mid;
        }
        deq_.insert(lo, loser);
    }
}

void PmergeMe::binary_search_vect(std::vector<std::pair<int, int> > labels)
{

    for (unsigned int i = 0; i < labels.size(); ++i)
    {
        int jb_index = jacobsthal_[i] - 1;
        if (jb_index >= (int)labels.size())
            break;

        std::pair<int,int> to_insert = labels[jb_index];
        int loser = to_insert.second;
        int winner = to_insert.first;

        std::vector<int>::iterator winner_it = std::lower_bound(vect_.begin(), vect_.end(), winner);

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

        vect_.insert(lo, loser);
    }
    for (unsigned int i = 0; i < labels.size(); ++i)
    {
        if(std::find(jacobsthal_.begin(), jacobsthal_.end(), i + 1) != jacobsthal_.end())
            continue;

        std::pair<int,int> to_insert = labels[i];
        int loser = to_insert.second;
        int winner = to_insert.first;

        std::vector<int>::iterator winner_it = std::lower_bound(vect_.begin(), vect_.end(), winner);

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
        vect_.insert(lo, loser);
    }
}

void PmergeMe::sortDeque(std::deque<int> &to_sort)
{
    if(to_sort.size() < 2)
    {
        deq_.push_back(to_sort[0]);
        return ;
    }
    std::deque<std::pair<int, int> > labels;
    std::deque<int> winners;

    for (std::deque<int>::iterator it = to_sort.begin(); it != to_sort.end(); )
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
    sortDeque(winners);
    binary_search_deq(labels);
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
    binary_search_vect(labels);
} 

void PmergeMe::sort(char **av)
{
    std::vector<int> vect_input;
    std::deque<int> deq_input;
    

    int i = 1;
    std::clock_t start_time_datamg = std::clock();
    while(av[i] != NULL)
    {
        std::string input = av[i];
        std::stringstream ss(input);
        std::string line = "";
        std::getline(ss, line);
        if (is_num(line))
        {
            vect_input.push_back(atoi(line.c_str()));
            deq_input.push_back(atoi(line.c_str()));
        }
        else
        {
            std::cout << "Error" << std::endl;
            return;
        }
        ++i;
    }    
    std::clock_t end_time_datamg = std::clock();
    std::clock_t start_time_vect = std::clock();
    sortVector(vect_input);
    std::clock_t end_time_vect = std::clock();
    std::clock_t start_time_deq = std::clock();
    sortDeque(deq_input);
    std::clock_t end_time_deq = std::clock();
    double datamg_time_ms = double(end_time_datamg - start_time_datamg) * 1000.0 / CLOCKS_PER_SEC;
    double vect_time_ms = double(end_time_vect - start_time_vect) * 1000.0 / CLOCKS_PER_SEC;
    double deq_time_ms = double(end_time_deq - start_time_deq) * 1000.0 / CLOCKS_PER_SEC;
    print_recap(vect_input, datamg_time_ms, vect_time_ms, deq_time_ms);
    isSorted();
}

void PmergeMe::print_recap(std::vector<int> vect_input, double datamg_time_ms, double vect_time_ms, double deq_time_ms)
{
    std::size_t show_limit = std::min(static_cast<std::size_t>(5), vect_input.size());
    std::cout << "Before : ";
    for(std::size_t i = 0; i < show_limit; ++i)
        std::cout << vect_input[i] << " ";
    if(show_limit < vect_input.size())
        std::cout << "[...]";
    std::cout << std::endl;
    std::cout << "After : ";
    for(std::size_t i = 0; i < show_limit; ++i)
        std::cout << vect_[i] << " ";
    if(show_limit < vect_input.size())
        std::cout << "[...]";
    std::cout << std::endl;
    std::cout << "Time to process a range of " << vect_.size() << " elements with std::vector : " << datamg_time_ms + vect_time_ms << " ms\n";
    std::cout << "Time to process a range of " << deq_.size() << " elements with std::deque : " << datamg_time_ms + deq_time_ms << " ms\n";
}


bool is_num(const std::string& str)
{
    for(unsigned int i = 0; i < str.size(); ++i)
    {
        if(!isdigit(str[i]))
            return false;
    }
    std::stringstream ss(str);
    int x;
    ss >> x;
    if (ss.fail() || x < 0)
        return false;
    return true;
}



