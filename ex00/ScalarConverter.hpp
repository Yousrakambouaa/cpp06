/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykamboua <ykamboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 18:56:24 by ykamboua          #+#    #+#             */
/*   Updated: 2025/09/20 00:23:03 by ykamboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
enum LiteralTypes
{
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    PSEUDO,
};

class	ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter& other);
		ScalarConverter& operator=(ScalarConverter& other);
		~ScalarConverter();
	public:
		static	void convert(const std::string& input);
};

#endif