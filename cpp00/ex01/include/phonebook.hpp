#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "main.hpp"

class Phonebook
{
private:
    Contact repertory[8];
    int number_of_contact;

public:
    Phonebook()
    {
        number_of_contact = 0;
    }
    void push_all();
    void find_and_display();
    void add_contact();
    void display_phonebook();
};

#endif