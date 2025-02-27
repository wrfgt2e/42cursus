/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 23:49:14 by gipark            #+#    #+#             */
/*   Updated: 2021/05/16 23:55:50 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWEAPON_HPP
# define AWEAPON_HPP

# include <iostream>
# include <string>

class AWeapon
{
protected:
    AWeapon();

    std::string name;
    int apCost;
    int damage;

public:
    AWeapon(std::string const &name, int apCost, int damgage);
    AWeapon(AWeapon const &other);
    virtual ~AWeapon();

    AWeapon &operator=(AWeapon const &other);

    std::string const &getName(void) const;
    int getAPCost(void) const;
    int getDamage(void) const;

    virtual void attack() const = 0;
};

#endif
