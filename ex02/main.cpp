/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykamboua <ykamboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 21:02:22 by ykamboua          #+#    #+#             */
/*   Updated: 2025/09/25 02:43:23 by ykamboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Base.hpp"
// #include "Base.cpp"
Base* generate();
void identify(Base* p);
void identify(Base& p);


int main(int ac, char **av)
{
	srand(time(0));
	Base* p = generate();
	identify(*p);
	identify(p);
}
