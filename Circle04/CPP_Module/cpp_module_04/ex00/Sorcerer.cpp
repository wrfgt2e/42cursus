/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 08:15:55 by gipark            #+#    #+#             */
/*   Updated: 2021/05/16 22:51:05 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"

Sorcerer::Sorcerer(std::string const &name, std::string const &title):
    name(name), title(title)
{
    std::cout << this->name << ", " << this->title << ", is born!" << std::endl;
}

Sorcerer::Sorcerer(Sorcerer const &other):
    name(other.name), title(other.title)
{
    std::cout << this->name << ", " << this->title << ", is born!" << std::endl;
}

Sorcerer::~Sorcerer()
{
    std::cout << this->name << ", " << this->title
            << ", is dead. Consequences will never be the same!" << std::endl;
}

Sorcerer &Sorcerer::operator=(Sorcerer const &other)
{
    this->name = other.name;
    this->title = other.title;
    return (*this);
}

std::string const &Sorcerer::getName(void) const
{
    return (this->name);
}

std::string const &Sorcerer::getTitle(void) const
{
    return (this->title);
}

void Sorcerer::polymorph(Victim const &victim) const
{
    victim.getPolymorphed();
}

std::ostream &operator<<(std::ostream &out, Sorcerer const &sorcerer)
{
    out << "I am " << sorcerer.getName() << ", "
        << sorcerer.getTitle() << ", and I like ponies!" << std::endl;
    return (out);
}
