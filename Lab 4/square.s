start:
	BRA main

	# this will sit at address 1
INPUT:
	2

main:
	# load n from mem[1]
	LDI X0, 1
	ADD X3, X0
	LD X3, [X3]

	# counter = n
	ADD X1, X3

loop:
	BZ X1, end

	ADD X2, X3

	LDI X0, 255
	ADD X1, X0

	BRA loop

end:
	LDI X0, 2
	ST X2, [X0]

	HLT