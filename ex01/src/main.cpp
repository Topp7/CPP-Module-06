/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:30:21 by stopp             #+#    #+#             */
/*   Updated: 2025/01/14 17:27:30 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../inc/Serializer.hpp"

int	main(void)
{
	Data	testData;

	testData.a = 1;
	testData.test = "42";
	std::cout << "before Serialization	" << &testData << std::endl;
	std::cout << std::hex << "uintptr:		" << Serializer::serialize(&testData) << std::endl;
	std::cout << "after Serialization	" << Serializer::deserialize(Serializer::serialize(&testData)) << std::endl;
}
