#include "fileContent.hpp"
#include <iostream>
#include <fstream>

void	fileContent::ft_replace( std::string search, std::string replace )
{
	size_t	i;
	i = str.find(search);
	while (i != std::string::npos)
	{
		if (!str.compare(i, search.length(), search))
		{
			str.erase(i, search.length());
			str.insert(i, replace);
		}
		i = str.find(search);
	}
}