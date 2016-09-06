#ifndef SRAM_H
#define SRAM_H

#include "RAM_BASE.h"


class SRAM : public RAM_BASE
{
    public:
        SRAM(const ramFormat a_format);
        virtual ~SRAM();

    protected:

    unsigned const char* m_memory;

};

#endif // SRAM_H
