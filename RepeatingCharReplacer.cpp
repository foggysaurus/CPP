#include <iostream>
#include <string>
#include <vector>

std::string changer(std::string& source)
{
    constexpr int kAscciCount = 256;
    std::string result;
    result.reserve(source.size());
    std::vector<int> helper(kAscciCount, -1);
    for (size_t i = 0; i < source.size(); i++)
    {
        source[i] = tolower(source[i]);
        if (helper[source[i]] != -1)
        {
            result.push_back(')');
                result[helper[source[i]]] = ')';
        }
        else
        {
            helper[source[i]] = i;
            result.push_back('(');
        }
    }
    return result;
}

int main()
{
    std::string source = "   1231$%^ ^ ^456789((";
    std::cout << changer(source);
}