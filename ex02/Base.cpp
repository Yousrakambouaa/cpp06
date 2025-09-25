/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykamboua <ykamboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 15:40:53 by ykamboua          #+#    #+#             */
/*   Updated: 2025/09/25 02:45:05 by ykamboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


Base::~Base()
{
	
}

Base* generate()
{
	int n;
	n = rand();

	if(n % 3 == 0)
		return (new (A));
	if(n % 3 == 1)
		return (new B);
	if(n % 3 == 2)
		return (new C);
	std::cout << n << std::endl;

	return(nullptr);
	
}

void identify(Base* p)
{
	if(dynamic_cast<A*>(p))
		std::cout << "Base A" << std::endl;
	else if(dynamic_cast<B*>(p))
		std::cout << "Base B" << std::endl;
	else if(dynamic_cast<C*>(p))
		std::cout << "Base C" << std::endl;
	
}

void identify(Base& p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		std::cout << "Base A" << std::endl;
		return;
	}
	catch (const std::bad_cast&)
	{}
	try
	{
		B& b = dynamic_cast<B&>(p);
		std::cout << "Base B" << std::endl;
		return;
	}
	catch(const std::bad_cast&)
	{
	}
	try
	{
		C& c = dynamic_cast<C&>(p);
		std::cout << "Base C" << std::endl;
		return;
	}
	catch(const std::bad_cast&)
	{
	}
}
