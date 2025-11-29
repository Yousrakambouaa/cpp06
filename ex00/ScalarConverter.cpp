/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykamboua <ykamboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 18:56:32 by ykamboua          #+#    #+#             */
/*   Updated: 2025/11/29 23:17:18 by ykamboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScalarConverter.hpp"

bool input_parser(const std::string& str)
{
    if (str.empty())
        return (false);
    if (str == "nan" || str == "nanf" || str == "+inf" || str == "-inf" || str == "+inff" || str == "-inff")
        return (true);
    std::string input = str;
    int dot_count = 0;
    int f_count = 0;
    if (input.length() == 1 && !std::isdigit(input[0]))
        return (true);
    if (input[0] == '+' || input[0] == '-')
        input = input.substr(1);
    for (size_t i = 0; i < input.size(); ++i)
    {
        char c = input[i];
        if (std::isdigit(c))
            continue;
        else if (c == '.')
            dot_count++;
        else if (c == 'f')
        {
            f_count++;
            if (i != input.size() - 1)
				return (false);
        }
        else
			return (false);
    }
    if (dot_count > 1 || f_count > 1)
        return (false);
    bool has_digit = false;
    for (size_t i = 0; i < input.size(); ++i)
    {
        if (std::isdigit(static_cast<unsigned char>(input[i])))
        {
            has_digit = (true);
            break;
        }
    }
    return (has_digit);
}

LiteralTypes detect_type(const std::string& input)
{
    bool isPseudoFloat = (input == "nanf" || input == "+inff" || input == "-inff");
    bool isPseudoDouble = (input == "nan" || input == "+inf" || input == "-inf");
    if (isPseudoFloat || isPseudoDouble)
        return (PSEUDO);
    if ((input.length() == 1 && !std::isdigit(input[0])) ||
        (input.length() == 3 && input.front() == '\'' && input.back() == '\''))
        return (CHAR);
    if (!input_parser(input))
        return (NONE);
    if (input.back() == 'f')
        return (FLOAT);
    if (input.find('.') != std::string::npos)
        return (DOUBLE);
    return (INT);
}

void ScalarConverter::convert(const std::string& input)
{
    LiteralTypes type = detect_type(input);
    switch (type)
    {
        case (NONE):
            std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
            break;
        case (CHAR):
        {
			char c ;
			if(input.length() == 3)
				c = input[1];
			else
				c = input[0];
			if (c < 0 || c > 127)
				std::cout << "char: impossible\n";
			else if (isprint(static_cast<unsigned char>(c)))
				std::cout << "char: '" << c << "'\n";
			else
				std::cout << "char: Non displayable\n";
			std::cout << std::fixed << std::setprecision(1);
			std::cout << "int: " << static_cast<int>(c) << "\n";
			std::cout << "float: " << static_cast<float>(c) << "f\n";
			std::cout << "double: " << static_cast<double>(c) << "\n";
			break;
        }
        case (INT):
        {
			char* end;
			long n_long = std::strtol(input.c_str(), &end, 10);
			if (end == input.c_str() || *end != '\0' || n_long < INT_MIN || n_long > INT_MAX)
			{
				std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
				break;
			}
			int n = static_cast<int>(n_long);
			if (n < 0 || n > 127)
				std::cout << "char: impossible\n";
			else if (isprint(n))
				std::cout << "char: '" << static_cast<char>(n) << "'\n";
			else
				std::cout << "char: Non displayable\n";
				std::cout << "int: " << n << "\n";
				std::cout << std::fixed << std::setprecision(1);
				std::cout << "float: " << static_cast<float>(n) << "f\n";
				std::cout << "double: " << static_cast<double>(n) << "\n";
			break;
        }
        case (FLOAT):
        {
			std::string tmp = input;
			if (tmp.back() == 'f')
			tmp = tmp.substr(0, tmp.size() - 1);
			char* end;
			float f = std::strtof(tmp.c_str(), &end);
			if (end == tmp.c_str() || *end != '\0')
			{
				std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
				break;
			}
			if (f < 0 || f > 127 || f != static_cast<int>(f))
				std::cout << "char: impossible\n";
			else if (isprint(static_cast<int>(f)))
				std::cout << "char: '" << static_cast<char>(f) << "'\n";
			else
				std::cout << "char: Non displayable\n";
			if (f > static_cast<float>(INT_MAX) || f < static_cast<float>(INT_MIN))
				std::cout << "int: impossible\n";
			else
				std::cout << "int: " << static_cast<int>(f) << "\n";
				std::cout << std::fixed << std::setprecision(1);
				std::cout << "float: " << f << "f\n";
				std::cout << "double: " << static_cast<double>(f) << "\n";
			break;
        }
        case (DOUBLE):
        {
			char* end;
			double d = std::strtod(input.c_str(), &end);
			if (end == input.c_str() || *end != '\0')
			{
				std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
				break;
			}
			if (d < 0 || d > 127 || d != static_cast<int>(d))
				std::cout << "char: impossible\n";
			else if (isprint(static_cast<int>(d)))
				std::cout << "char: '" << static_cast<char>(d) << "'\n";
			else
				std::cout << "char: Non displayable\n";
			if (d > static_cast<double>(INT_MAX) || d < static_cast<double>(INT_MIN))
				std::cout << "int: impossible\n";
			else
				std::cout << "int: " << static_cast<int>(d) << "\n";
			std::cout << std::fixed << std::setprecision(1);
			if (d > static_cast<double>(FLT_MAX) || d < -static_cast<double>(FLT_MAX))
				std::cout << "float: impossible\n";
			else
				std::cout << "float: " << static_cast<float>(d) << "f\n";
			std::cout << "double: " << d << "\n";
			break;
        }
        case (PSEUDO):
		{
			std::cout << "char: impossible\n";
			std::cout << "int: impossible\n";
			std::cout << std::fixed << std::setprecision(1);
			if (input == "nan" || input == "nanf")
				std::cout << "float: nanf\n" << "double: nan\n";
			else if (input == "+inf" || input == "+inff")
				std::cout << "float: +inff\n" << "double: +inf\n";
			else if (input == "-inf" || input == "-inff")
				std::cout << "float: -inff\n" << "double: -inf\n";
			break;
		}
    }
}
