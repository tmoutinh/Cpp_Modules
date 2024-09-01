#include "Serializer.hpp"

int main (int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cout << "Use :: ./Serializer <Name> <date>" << std::endl;
        return (-1);
    }
    uintptr_t   serialize;
    Data        *deserialize;
    Data        example = {argv[0], argv[1]};
    std::cout << "Before Serialize : " << &example << std::endl;
    serialize = Serializer::serialize(&example);
    deserialize = Serializer::deserialize(serialize);
    std::cout << "After Serialize : " << serialize << std::endl;
    std::cout << "After Deserialize : " << deserialize << std::endl;
    return (0);
}
