/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:32:22 by stopp             #+#    #+#             */
/*   Updated: 2025/01/13 12:12:14 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstring>
#include <limits>
#include <iomanip>
#include <sstream>
#include <cctype>
#include <regex>

class	Converter
{
	private:
		Converter();
		Converter(const Converter &copy);
		~Converter();
		Converter	&operator=(const Converter &copy);
		static bool	convert_int(std::string value);
		static bool	convert_float(std::string value);
		static bool	convert_double(std::string value);

	public:
		static void		convert(std::string input);
};
