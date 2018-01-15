#include <iostream>
#include "tst_machine.h"
#include "programloader.h"
#include "instruction.h"

using namespace machine;

// This is common program start (initial value of program counter)
#define PC_INIT 0x80020000

void MachineTests::program_loader() {
    ProgramLoader pl("data");
    Memory m;
    pl.to_memory(&m);

    // 	addi $1, $0, 6
    QCOMPARE(Instruction(m.read_word(PC_INIT)), Instruction(8, 0, 1, 6));
    // j (8)0020000 (only 28 bits are used and they are logically shifted left by 2)
    QCOMPARE(Instruction(m.read_word(PC_INIT + 4)), Instruction(2, 0x20000 >> 2));
    // TODO add some more code to data and do more compares (for example more sections)
}
