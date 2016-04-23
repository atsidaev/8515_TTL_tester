# removing initial res=1 and seg[0] = 13 assignments from particular tests

import re
import sys

with open(sys.argv[1]) as f:
	content = f.readlines()
	
for l in content:
	m = re.match("(^\s+res\s*=\s*)1\s*;\s*$", l);
	if not m:
		m = re.match("(^\s+sym\[0\]\s*=\s*)12\s*;\s*$", l);
		if not m:
			sys.stdout.write(l)
