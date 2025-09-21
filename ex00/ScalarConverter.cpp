/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykamboua <ykamboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 18:56:32 by ykamboua          #+#    #+#             */
/*   Updated: 2025/09/20 22:28:15 by ykamboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScalarConverter.hpp"
#include <limits>
#include<cctype>
#include <iomanip>
// #include<string.h>
// #define CHAR 0;
// #define INT 1;
// #define FLOAT 2;
// #define DOUBLE 3;
// #define PSEUDO 4;


ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(ScalarConverter& other)
{}

ScalarConverter& ScalarConverter::operator=(ScalarConverter& other)
{
	return(*this);
}

ScalarConverter::~ScalarConverter()
{}

int input_parser(const std::string& str)
{
    std::string input = str;

    if (input.empty())
        return (1);
    // if (input == "nan" || input == "nanf" || input == "+inf" || input == "-inf" ||
    //     input == "+inff" || input == "-inff")
    //     return (0);
    if (input.length() == 1 && !std::isdigit(input[0]))
        return (0);
    if (input[0] == '+' || input[0] == '-')
        input = input.substr(1);
    if (input.find_first_not_of("0123456789.f") != std::string::npos)
        return (1);
    if (std::count(input.begin(), input.end(), '.') > 1)
        return (1);
    if (std::count(input.begin(), input.end(), 'f') > 1)
        return (1);
    if (input.find('f') != std::string::npos && input.back() != 'f')
        return (1);
    return (0);
}

LiteralTypes detect_type(const std::string& input)
{
	if (input == "+inf" || input == "-inf" || input == "+inff" || input == "-inff" || input == "nan" || input == "nanf")
        return (PSEUDO);
	if(input_parser(input) == 1)
		return (NONE);
	if(input.length() == 1 && !std::isdigit(input[0]))
		return (CHAR);
	if(input.find('.') != std::string::npos)
	{
		if(input.back() == 'f')
			return (FLOAT);
		else
			return (DOUBLE);
	}
	return (INT);
}

void ScalarConverter::convert(const std::string& input)
{
	LiteralTypes type = detect_type(input);

	switch(type)
	{
		case NONE:
		{
			std::cout << "none type detected here " << std::endl;
			break;
		}
		case CHAR:
		{
			std::cout << std::fixed << std::setprecision(1);
			char c = input[0];
			std::cout << "char : " << c << std::endl;
			std::cout << "int : " << static_cast<int>(c) << std::endl;
			std::cout << "float : " << static_cast<float>(c) << std::endl;
			std::cout << "double : " << static_cast<double>(c) << std::endl;
			break;
		}
		case INT:
		{
			try
			{
				std::cout << std::fixed << std::setprecision(1);
				int n = std::stoi(input);
				if(n >= 32 && n <= 126)
					std::cout << "char : " << static_cast<char>(n) << std::endl;
				else
                    std::cout << "char: not displayable" << std::endl;
				std::cout << "int : " << n << std::endl;
				std::cout << "float : " << static_cast<float>(n) << std::endl;
				std::cout << "double: " <<  static_cast<double>(n) << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cout << "char: impossible\n int: impossible\n float: impossible\n double: impossible\n";
			}
			break;
		}
		case FLOAT:
		{
			try
			{
				std::cout << std::fixed << std::setprecision(1);
				float f = std::stof(input);
				if(f >= 32 && f <= 126)
					std::cout << "char : " << static_cast<char>(f) << std::endl;
				else
                    std::cout << "char: not displayable" << std::endl;
				std::cout << "int : " << static_cast<int>(f) << std::endl;
				std::cout << "float: " << f << std::endl;
				std::cout << "double: " << static_cast<double>(f) << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cout << "char: impossible\n int: impossible\n float: impossible\n double: impossible\n";
			}
			break;
		}
		case DOUBLE:
		{
			try
			{
				std::cout << std::fixed << std::setprecision(1);
				double d = std::stod(input);
				if(d >= 32 && d <= 126)
					std::cout << "char : " << static_cast<char>(d) << std::endl;
				else
                    std::cout << "char: not displayable" << std::endl;
				std::cout << "int: " << static_cast<int>(d) << std::endl;
				std::cout << "float: " << static_cast<float>(d)<< std::endl;
				std::cout << "double: " << (d) << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cout << "char: impossible\n int: impossible\n float: impossible\n double: impossible\n";
			}
			break;
		}
		case PSEUDO:
		{
			std::string pseudo = input;
				if(pseudo.back() != 'f')
					pseudo+= "f";
				std::cout << "char : impossible" << std::endl;
				std::cout << "int : impossible" << std::endl;
				std::cout << "float : " << pseudo << std::endl;
				std::cout << "double : " << input << std::endl;
			break;
		}
	}
}


