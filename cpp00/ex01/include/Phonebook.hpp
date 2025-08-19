#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

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
    Contact *get_repertory();
    int get_nbcontact();
};

void display_phonebook(Phonebook p);
void find_and_display(Phonebook p);

#endif