#include "arm/arm.h"
#include "arm/arm_instruction.h"

void redasm_entry()
{
    InitializeARM();

    RD_PLUGIN_CREATE(RDAssemblerPlugin, armle, "ARM Assembler (Little Endian)");
    armle.bits = 32;
    armle.regname = &ARMDecoder::regname;
    armle.decode = &ARMDecoder::decode<RD_FromLittleEndian32>;
    armle.emulate = &ARMDecoder::emulate;
    armle.render = &ARMDecoder::render;
    RDAssembler_Register(&armle);

    RD_PLUGIN_CREATE(RDAssemblerPlugin, armbe, "ARM Assembler (Big Endian)");
    armbe.bits = 32;
    armbe.regname = &ARMDecoder::regname;
    armbe.decode = &ARMDecoder::decode<RD_FromBigEndian32>;
    armbe.emulate = &ARMDecoder::emulate;
    armbe.render = &ARMDecoder::render;
    RDAssembler_Register(&armbe);
}
