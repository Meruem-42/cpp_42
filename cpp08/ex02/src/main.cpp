#include "../include/MutantStack.hpp"
#include <vector>
#include <list>

int main()
{
    // TEST WITH MUTANTSTACK AND DEQUEU(per default) AS CONTAINER
    std::cout << "TEST WITH MUTANTSTACK AND DEQUEU(per default) AS CONTAINER\n";

    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "the top element of the MutantStack with dequeu is : " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "the size of the MutantStack with dequeu is : " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);

    // TEST WITH MUTANTSTACK AND VECTOR AS CONTAINER
    std::cout << "\nTEST WITH MUTANTSTACK AND VECTOR AS CONTAINER\n";

    MutantStack<int, std::vector<int> > mstack2;
    mstack2.push(5);
    mstack2.push(17);
    std::cout << "the top element of the MutantStack with vector is : " << mstack2.top() << std::endl;
    mstack2.pop();
    std::cout << "the size of the MutantStack with vector is : " << mstack2.size() << std::endl;
    mstack2.push(3);
    mstack2.push(5);
    mstack2.push(737);
    mstack2.push(0);
    MutantStack<int, std::vector<int> >::iterator it2 = mstack2.begin();
    MutantStack<int, std::vector<int> >::iterator ite2 = mstack2.end();
    ++it2;
    --it2;
    while (it2 != ite2)
    {
        std::cout << *it2 << std::endl;
        ++it2;
    }
    std::stack<int, std::vector<int> > s2(mstack2);

    // TEST WITH WITH LIST CONTAINER AND CONST_ITERATOR
    std::cout << "\nTEST WITH WITH LIST CONTAINER AND CONST_ITERATOR\n";

    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);
    std::cout << "the top element of the list is : " << lst.back() << std::endl;
    lst.pop_back();
    std::cout << "the size of the list is : " << lst.size() << std::endl;
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);
    std::list<int>::const_iterator it3 = lst.cbegin();
    std::list<int>::const_iterator ite3 = lst.cend();
    ++it3;
    --it3;
    while (it3 != ite3)
    {
        std::cout << *it3 << std::endl;
        ++it3;
    }
    std::list<int> s3(lst);

    std::cout << "\nTEST COPY CONSTRUCTOR\n";
    MutantStack<int, std::vector<int> > mstacktest1(mstack2);
    MutantStack<int, std::vector<int> >::iterator it4 = mstacktest1.begin();
    MutantStack<int, std::vector<int> >::iterator ite4 = mstacktest1.end();
    while (it4 != ite4)
    {
        std::cout << *it4 << std::endl;
        ++it4;
    }
    std::cout << "\nTEST OPERATOR=\n";
    MutantStack<int, std::vector<int> > mstacktest2 = mstack2;
    MutantStack<int, std::vector<int> >::iterator it5 = mstacktest2.begin();
    MutantStack<int, std::vector<int> >::iterator ite5 = mstacktest2.end();
    while (it5 != ite5)
    {
        std::cout << *it5 << std::endl;
        ++it5;
    }


    return 0;
}