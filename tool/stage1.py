import re
import sys

with open(sys.argv[1]) as f:
    content = f.readlines()

for l in content:
	m = re.findall("(((Direct|Port|Pin)_([LH]) *={1,2} *)([^;)]*)([;)]))", l)
	if m:
		for i in m:
			num = int(i[4])
			if num != 0:
				mask = 1
				expr = []
				for c in range(0,8):
					if (num & mask) == mask:
						expr.append(c)
					mask *= 2
				
				if i[3] == 'H':
					expr = reversed(expr)
				items = list(map(lambda x: "BIT_" + i[3] + str(x), expr))
				
				l = l.replace(i[0], i[1] + "(" + " | ".join(items)  + ")"  + i[5])
	sys.stdout.write(l)
