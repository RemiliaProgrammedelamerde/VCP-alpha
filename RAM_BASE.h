#ifndef RAM_H
#define RAM_H

#include <iostream>

typedef unsigned char uint8;
typedef unsigned short int uint16;
typedef unsigned long int uint32;
typedef unsigned long long int uint64;
typedef unsigned char offset[5];

enum ramFormat
{
    _8bitAddr = static_cast<uint8>(8),
    _16bitAddr = static_cast<uint8>(16),
};

class RAM_BASE
{
    public:
        RAM_BASE(const ramFormat a_typeAddr);
        ~RAM_BASE();

        virtual uint8 accesAt(const offset &a_offset) = 0;
        virtual void setAt(const offset &a_offset , const uint8 a_data) = 0;
        virtual void corrupt(const offset &a_begin, const offset &a_end, const int seed = 0) = 0;

    protected:

        ramFormat m_format;
};

#endif // RAM_H
