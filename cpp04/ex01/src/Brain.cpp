/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherlaud <aherlaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 14:12:01 by aherlaud          #+#    #+#             */
/*   Updated: 2025/09/05 14:12:10 by aherlaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Brain.hpp"

std::string *Brain::get_ideas()
{
    return (ideas);
}
void Brain::set_idea(int idea_num, std::string idea)
{
    if (idea_num >= 0 && idea_num < 100)
        ideas[idea_num] = idea;
}
