#include "sram.h"

SRAM::SRAM(const ramFormat a_format, unsigned char a_filler) : RAM_BASE::RAM_BASE(a_format)
{
    m_memory = nullptr;

    switch(m_format)
    {
        case _8bitAddr :
            m_memory = new unsigned char[0xFF] { a_filler };
        break;
        case _16bitAddr :
            m_memory = new unsigned char[0x10000] { a_filler };
        break;

        /*
         NE PAS OUBLIER DE COMPLETER UNE FOIS D'AUTRE FORMATS IMPLEMENTES !!!
        */
    }

}

SRAM::~SRAM()
{
    //dtor
}

uint8 SRAM::accesAt(const offset& a_offset)
{
    unsigned long convert;
    if(m_format == _16bitAddr){convert = a_offset[0]*10000 + a_offset[1]*1000 + a_offset[2]*100 + a_offset[3]*10 + a_offset[4];}
    else{convert  = a_offset[0]*1000 + a_offset[1]*100 + a_offset[2]*10 + a_offset[3]*1;}

    return m_memory[convert];
}
