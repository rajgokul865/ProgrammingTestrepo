#include<iostream>
#include <vector>
using namespace std;
class SomeVectors
{
public:
    std::vector<int> integers;
    std::vector<char> characters;   
};

int main()
{
    SomeVectors myVectors;

    myVectors.integers.push_back(10);
    myVectors.characters.push_back('a');

    cout<<myVectors.integers[0]; 

    return 0;
}