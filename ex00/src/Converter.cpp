/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:55:06 by stopp             #+#    #+#             */
/*   Updated: 2025/01/13 16:23:03 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Converter.hpp"

Converter::Converter()
{
}

Converter::~Converter()
{
}

Converter::Converter(const Converter &copy)
{
	(void)copy;
}
Converter	&Converter::operator=(const Converter &copy)
{
	(void)copy;
	return (*this);
}

void	output(char c, int i, float f, double d)
{
	std::string char_str, int_str;

	std::cout << std::setprecision(15);
	//char
	if (i - d != 0.0 || i < 0 || i > 255)
		char_str = "Not possible";
	else
	{
		if (!std::isprint(i))
			char_str = "Not printable";
		else
			char_str = std::string(1, c);
	}
	std::cout << "Char: " << char_str << std::endl;
	//int
	if (d - i == 0.0)
	{
		std::stringstream ss;
		ss << i;
		int_str = ss.str();
	}
	else
		int_str = "Not possible";
	std::cout << "Int: " << int_str << std::endl;
	// float

	if (f - i == 0.0f)
		std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f" << std::endl;
	else
		std::cout << "Float: " << f << "f" << std::endl;
	//double
	if (d - i == 0.0)
		std::cout << std::fixed << std::setprecision(1) << "double: " << d << std::endl;
	else
		std::cout << "Double: " << d << std::endl;
}

bool	Converter::convert_int(std::string value)
{
	int	i;

	if (value.find('.') != std::string::npos)
		return (false);
	else if ((value[0] == '-' && value.length() > 11) || value.length() > 10)
		return (false);
	try
	{
		i = std::stoi(value);
	}
	catch (...)
	{
		std::cout << "Integer Overflow" << std::endl;
		return (false);
	}
	output(static_cast<char>(i), i, static_cast<float>(i), static_cast<double>(i));
	return (true);
}

bool	Converter::convert_float(std::string value)
{
	float	f;

	if (value.find('.') == std::string::npos)
		return(false);
	else if (value.find('f') == std::string::npos && value.find('F') == std::string::npos)
		return (false);
	try
	{
		f = std::stof(value);
	}
	catch (...)
	{
		std::cout << "Float Overflow" << std::endl;
		return (false);
	}
	output(static_cast<char>(f), static_cast<int>(f), f, static_cast<double>(f));
	return (true);
}

bool	Converter::convert_double(std::string value)
{
	double	d;
	if (value.find('.') == std::string::npos)
		return(false);
	else if (value.find('f') != std::string::npos || value.find('F') != std::string::npos)
		return (false);
	try
	{
		d = std::stod(value);
	}
	catch (...)
	{
		std::cout << "Integer Overflow" << std::endl;
		return (false);
	}
	output(static_cast<char>(d), static_cast<int>(d), d, static_cast<double>(d));
	return (true);
}

bool	isChar(std::string input)
{
	if (input.length() == 1 && !std::isdigit(input[0]) && !std::isprint(input[0]))
	{
		char c = input[0];
		output(c, static_cast<int>(c), static_cast<float>(c), static_cast<double>(c));
		return (true);
	}
	return (false);
}

int	validInput(std::string input)
{
	std::regex	numRegex(R"(^[-+]?\d*\.?\d+([fF])?$)");

	if (input == "nan" || input == "nanf" ||
		input == "+inf" || input == "-inf" ||
		input == "+inff" || input == "-inff")
		return (1);
	if (std::regex_match(input, numRegex))
		return (2);
	return (0);
}

void	pseudoInput(std::string input)
{
	std::string	s;
	std::cout << "Char:\tImpossible" << std::endl;
	std::cout << "Int:\tImpossible" << std::endl;
	if (input.substr(0, 3) == "nan")
	{
		std::cout << "Float:\tnanf" << std::endl;
		std::cout << "Double:\tnan" << std::endl;
	}
	else if (input.length() == 5)
	{
		s = input.substr(0, 4);
		std::cout << "Float:\t" << input << std::endl;
		std::cout << "Double:\t" << s << std::endl;
	}
	else
	{
		std::cout << "Float:\t" << input + "f" << std::endl;
		std::cout << "Double:\t" << input << std::endl;
	}
}

void	Converter::convert(std::string input)
{
	if (isChar(input))
		return ;
	int	input_chk = validInput(input);
	switch (input_chk)
	{
		case 0:
			std::cout << "Invalid Input" << std::endl;
			break;
		case 1:
			pseudoInput(input);
			break;
		case 2:
			std::cout << input << std::endl;
			if(!convert_int(input) &&
				!convert_float(input) &&
				!convert_double(input))
			{
				std::cout << "char: impossible" << std::endl
				<< "int: impossible" << std::endl
				<< "float: impossible" << std::endl
				<< "double: impossible" << std::endl;
			}
	}
}
