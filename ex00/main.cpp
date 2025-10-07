/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykamboua <ykamboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 23:59:26 by ykamboua          #+#    #+#             */
/*   Updated: 2025/10/05 23:17:35 by ykamboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScalarConverter.hpp"

int	main(int ac, char **av)
{
	(void)ac;
	const std::string lol = "0";
	ScalarConverter::convert(av[1]);
	// input_parser(&lol);
}
