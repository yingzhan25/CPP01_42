/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yingzhan <yingzhan@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 10:08:06 by yingzhan          #+#    #+#             */
/*   Updated: 2025/11/09 21:09:36 by yingzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <iterator>

static bool	inputValidate(int ac, char *av[])
{
	if (ac != 4)
	{
		std::cout << "Error: number of arguments" << std::endl;
		return (false);
	}
	std::ifstream	infile(av[1]);
	if (!infile.is_open())
	{
		std::cout << "Error: failed to open file" << std::endl;
		return (false);
	}
	if (std::string(av[2]).empty())
	{
		std::cout << "Error: input string cannot be empty" << std::endl;
		return (false);
	}
	return (true);
}

static std::string	replaceStr(std::string& content, char *av[])
{
	size_t	startPos = 0;
	std::string	s1 = av[2];
	std::string s2 = av[3];
	std::string	newContent;
	size_t	replacePos = content.find(s1, startPos);

	while (replacePos != std::string::npos)
	{
		newContent +=  content.substr(startPos, replacePos - startPos) + s2;
		startPos = replacePos + s1.length();
		replacePos = content.find(s1, startPos);
	}
	newContent +=  content.substr(startPos);
	return (newContent);
}

int	main(int ac, char *av[])
{
	if (inputValidate(ac, av) == false)
		return (1);
	std::ifstream	infile(av[1]);
	std::string content((std::istreambuf_iterator<char>(infile)),
						std::istreambuf_iterator<char>());
	std::string	outfileName = std::string(av[1]) + ".replace";
	std::ofstream	outfile(outfileName);
	if (!outfile.is_open())
	{
		std::cout << "Error: failed to create outfile" << std::endl;
		return (1);
	}
	outfile << replaceStr(content, av);
	if (outfile.fail())
	{
		std::cout << "Error: failed to write to outfile" << std::endl;
		return (1);
	}
	return (0);
}