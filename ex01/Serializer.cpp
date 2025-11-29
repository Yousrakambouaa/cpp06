/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykamboua <ykamboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 23:35:47 by ykamboua          #+#    #+#             */
/*   Updated: 2025/11/20 22:19:33 by ykamboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data* ptr)
{
	uintptr_t num = reinterpret_cast<uintptr_t>(ptr);
	return(num);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	Data* d = reinterpret_cast<Data*>(raw);
	return(d);
}
