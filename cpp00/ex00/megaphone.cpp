#include <iostream>

using std::cout;
using std::endl;

int main(int ac,char** av)
{
    int i;
    int j;

    i = -1;
   
    if (ac > 1)
    {
        while (av[++i] != NULL)
        {
            j = -1;
            while (av[i][++j])
                av[i][j] = (char )toupper(av[i][j]);
            cout << av[i];
            if (av[i] != NULL)
				std::cout << " ";
        }
        cout << endl;

    }
    else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (0);
}