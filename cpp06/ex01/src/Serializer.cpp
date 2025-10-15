/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherlaud <aherlaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:37:52 by aherlaud          #+#    #+#             */
/*   Updated: 2025/10/15 15:37:53 by aherlaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Serializer.hpp"

Serializer::Serializer()
{
}

Serializer::Serializer(const Serializer& other)
{
    (void)other;
}

Serializer &Serializer::operator=(const Serializer& other)
{
    (void)other;
    return (*this);
}

Serializer::~Serializer()
{
}

uintptr_t Serializer::serialize(Data* ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data *>(raw));
}
