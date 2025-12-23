/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherlaud <aherlaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:37:49 by aherlaud          #+#    #+#             */
/*   Updated: 2025/10/15 15:37:51 by aherlaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Data.hpp"

Data::Data()
    : data_(0)
{
}

Data::Data(int data)
    : data_(data)
{
}

Data::Data(const Data& other)
    : data_(other.data_)
{
}
Data &Data::operator=(const Data& other)
{
    data_ = other.data_;
    return (*this);
}

Data::~Data()
{
}

int Data::get_data()
{
    return (data_);
}

