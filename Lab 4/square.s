start:
    BRA main

main:
    LDI X3, ONE
    LD X0, [X3]
    HLT

# data:
ONE: 
    1
TWO:
    2
ZERO:
    0
NEG1:
    -1
