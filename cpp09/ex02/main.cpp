#include "../include/PmergeMe1.hpp"
#include <vector>


// void GetNumberRandom(std::vector<int> &SequenceN,ssize_t N)
// {
//     srand(time(NULL));
//     for (ssize_t i = 0; i < N; i++)
//         SequenceN.push_back(rand() % 100);
// }



// void PrintVector(std::vector<int> SequenceN)
// {
//     std::vector<std::pair<int,int>> v;


// }

// int main(int ac,char** av)
// {
//     ssize_t N = 12;
//     std::vector<int> SequenceN;
    
//     GetNumberRandom(SequenceN,N);
    
//     std::vector<std::pair<int,int>> v = MakeThisPairs(SequenceN);
    
//     PrintVector(SequenceN);
    
// }


 
int main(int argc, char **argv)
{
    try 
    {
        PmergeMe pm(argc, argv);
        pm.run();
    }
    catch (const std::exception &e) 
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}