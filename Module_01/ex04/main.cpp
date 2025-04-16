#include <iostream>
#include <fstream>
#include <string>

int	main(int argc, char **argv)
{
	if (argc != 4 || !argv[2][0])
		return (1);

	unsigned long	i;
	std::string		fileContent;
	std::string		search = argv[2];
	std::string		replace = argv[3];
	std::string		newFileName = std::string(argv[1]) + ".replace";

	std::ifstream readFile(argv[1]);
	if (!readFile)
	{
		std::cerr << "Error: File couldnt be opened!" << std::endl;
		return (1);
	}
	std::ofstream newFile(newFileName.c_str());

	while (getline (readFile, fileContent))
	{
		i = fileContent.find(search);
		while (i != std::string::npos)
		{
			if (!fileContent.compare(i, search.length(), search))
			{
				fileContent.erase(i, search.length());
				fileContent.insert(i, replace);
			}
			i = fileContent.find(search);
		}
		newFile << fileContent << std::endl;
	}
	readFile.close();
	newFile.close();
	return (0);
}