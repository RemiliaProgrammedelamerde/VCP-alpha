#ifndef SRAM_H
#define SRAM_H

#include "RAM_BASE.h"


class SRAM : public RAM_BASE
{
    public:
        SRAM(const ramFormat a_format, unsigned char a_filler);
        virtual ~SRAM();

        uint8 accesAt(const offset& a_offset) override;

    protected:

    unsigned const char* m_memory;
    unsigned long m_pointer;

};

#endif // SRAM_H
