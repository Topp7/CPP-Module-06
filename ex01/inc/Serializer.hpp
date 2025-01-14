/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:12:36 by stopp             #+#    #+#             */
/*   Updated: 2025/01/13 18:27:46 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

typedef struct s_data
{
	int			a;
	std::string	test;
}	Data;

class	Serializer
{
	private:
		Serializer();
		~Serializer();
		Serializer(const Serializer &copy);
		Serializer	&operator=(const Serializer &copy);

	public:
		static uintptr_t	serialize(Data *ptr);
		static Data*		deserialize(uintptr_t raw);


};
