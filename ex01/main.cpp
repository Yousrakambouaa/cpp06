/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykamboua <ykamboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 00:46:43 by ykamboua          #+#    #+#             */
/*   Updated: 2025/11/20 22:25:52 by ykamboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
    Data d;
    d.name = "frtlan";
    d.level = 5.41;
	d.available = true;

    std::cout << "Original pointer: " << &d << "\n";
    uintptr_t raw = Serializer::serialize(&d);
    std::cout << "Serialized value:   " << raw << "\n";
    Data* ptr = Serializer::deserialize(raw);
    std::cout << "Deserialized pointer:   " << ptr << "\n";
	std::cout << ptr->name << std::endl;
	std::cout << ptr->level << std::endl;
	std::cout << ptr->available << std::endl;
    if (ptr == &d)
        std::cout << "SUCCESS: pointers match!\n";
    else
        std::cout << "FAIL: pointers dont match!\n";
}
