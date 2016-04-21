# renaming PIN_x0..7 to real signal name
# you need the "/* SIG1 SIG2 SIG3 ... */" comment be the first line of your .c file
# pins should be enumerated in pin number order (so the right chip side should be enumerated from bottom to top)

import re
import sys

with open(sys.argv[1]) as f:
	content = f.readlines()

defines = []

if content[0].startswith("/*"):
	pins = content[0].replace("/*", "").replace("*/", "").strip().split(" ")
	if len(pins) != 14 and len(pins) != 16:
		raise Exception("Invalid description for chip pins")
	
	# rename ambigous pins
	nc = 1
	for i in range(0, len(pins)):
		if pins[i] == "NC":
			pins[i] = "NC" + str(nc)
			nc += 1
	
	pins_on_side = int(len(pins) / 2)
	
	for i in range(0, pins_on_side):
		defines.append(("BIT_L" + str(i), "P_" + pins[i]))

	for i in range(0, pins_on_side):
		defines.append(("BIT_H" + str(pins_on_side - i - 1), "P_" + pins[pins_on_side + i]))

	for d in defines:
		print("#define " + d[1] + " " + d[0])
	print()
	print()

for l in content:
	for d in defines:
		l = l.replace(d[0], d[1])
	sys.stdout.write(l)

if len(defines) > 0:
	print()
	print()
	for d in defines:
		print("#undef " + d[1])
