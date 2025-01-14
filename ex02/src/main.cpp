/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:37:45 by stopp             #+#    #+#             */
/*   Updated: 2025/01/14 16:58:56 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"


Base	*generate()
{
	srand(time(NULL));
	int rndm = std::rand() % 3;
	switch (rndm)
	{
		case 0:
			return (new A());
		case 1:
			return (new B());
		case 2:
			return (new C());
	}
	return (NULL);
}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "A : Identified by pointer!" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "B : Identified by pointer!" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "C : Identified by pointer!" << std::endl;
	else
		std::cout << "Error : Not one of them" << std::endl;
}

void	identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A : Identified by reference!" << std::endl;
	}
	catch(const std::exception& e)
	{
		try
		{
			(void)dynamic_cast<B&>(p);
			std::cout << "B : Identified by reference!" << std::endl;
		}
		catch(const std::exception& e)
		{
			try
			{
				(void)dynamic_cast<C&>(p);
				std::cout << "C : Identified by reference!" << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
		}
	}
}

int	main(void)
{
	Base	*base = generate();
	std::cout << "------ Test 1 ------" << std::endl;
	identify(base);
	identify(*base);
	delete base;
	std::cout << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(1));
	base = generate();
	std::cout << "------ Test 2 ------" << std::endl;
	identify(base);
	identify(*base);
	delete base;
}
