/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykamboua <ykamboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 23:59:26 by ykamboua          #+#    #+#             */
/*   Updated: 2025/11/29 22:53:34 by ykamboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScalarConverter.hpp"

int	main(int ac, char **av)
{
	if(ac != 2)
	{
		std::cout << "enter shi argument !" << std::endl;
		return(1);
	}
	const std::string lol = "0";
	ScalarConverter::convert(av[1]);
}
