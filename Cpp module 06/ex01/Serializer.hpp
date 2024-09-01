#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include "Data.hpp"


class Serializer 
{
    private:
        Serializer();
        Serializer(const Serializer& other);
        Serializer& operator=(const Serializer& other);
        ~Serializer();
    public:
        static Data*     deserialize(uintptr_t raw);
        static uintptr_t serialize(Data* ptr);
};


#endif

