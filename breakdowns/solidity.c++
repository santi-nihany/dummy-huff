
//free memory pointer
PUSH1 0x80
PUSH1 0x40
MSTORE

// read msg.value and revert if msg.value != 0
CALLVALUE       // stack = [msg.value]
DUP1            // stack = [msg.value, msg.value]
ISZERO          // stack = [msg.value == 0 ? 1 : 0, msg.value]
PUSH1 0xE       // stack = [0xE,msg.value == 0 ? 1 : 0, msg.value]
JUMPI           // jumps if msg.value == 0, stack = [msg.value]
PUSH0           // stack = [0, msg.value]
DUP1            // stack = [0,0, msg.value]
REVERT          // reverts if msg.value != 0

// if msg.value == 0, continue
JUMPDEST        
POP             // stack = []
PUSH1 0xA5      // stack = [0xA5]
DUP1            // stack = [0xA5, 0xA5]
PUSH2 0x1B      // stack = [0x1B, 0xA5, 0xA5]
PUSH0           // stack = [0, 0x1B, 0xA5, 0xA5]
CODECOPY        // destOffset; offset; size;
PUSH0           // stack = [0, 0xA5]
RETURN          
INVALID


PUSH1 0x80
PUSH1 0x40
MSTORE
CALLVALUE
DUP1
ISZERO
PUSH1 0xE
JUMPI
PUSH0
DUP1
REVERT
JUMPDEST
POP
PUSH1 0x4
CALLDATASIZE
LT
PUSH1 0x30
JUMPI
PUSH0
CALLDATALOAD
PUSH1 0xE0
SHR
DUP1
PUSH4 0xCDFEAD2E
EQ
PUSH1 0x34
JUMPI
DUP1
PUSH4 0xE026C017
EQ
PUSH1 0x45
JUMPI
JUMPDEST
PUSH0
DUP1
REVERT
JUMPDEST
PUSH1 0x43
PUSH1 0x3F
CALLDATASIZE
PUSH1 0x4
PUSH1 0x59
JUMP
JUMPDEST
PUSH0
SSTORE
JUMP
JUMPDEST
STOP
JUMPDEST
PUSH0
SLOAD
PUSH1 0x40
MLOAD
SWAP1
DUP2
MSTORE
PUSH1 0x20
ADD
PUSH1 0x40
MLOAD
DUP1
SWAP2
SUB
SWAP1
RETURN
JUMPDEST
PUSH0
PUSH1 0x20
DUP3
DUP5
SUB
SLT
ISZERO
PUSH1 0x68
JUMPI
PUSH0
DUP1
REVERT
JUMPDEST
POP
CALLDATALOAD
SWAP2
SWAP1
POP
JUMP 