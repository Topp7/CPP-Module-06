/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:30:21 by stopp             #+#    #+#             */
/*   Updated: 2025/01/13 18:25:25 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../inc/Serializer.hpp"

int	main(void)
{
	Data data = {42, "dataString"};

	uintptr_t uintptr = Serializer::serialize(&data);
	Data* dataptr = Serializer::deserialize(uintptr);

	std::cout << "Data : " << &data << std::endl;
	std::cout << "uintptr : " << &uintptr << std::endl;
	std::cout << "Data_ptr : " << dataptr << std::endl;
}
