# removing initial res=1 and seg[0] = 13 assignments from particular tests

import re
import sys

with open(sys.argv[1]) as f:
	content = f.readlines()
	
for l in content:
	m = re.match("(^\s+sym\[[1-3]\]\s*=\s*)[0-9]+\s*;\s*$", l);
	if not m:
		sys.stdout.write(l)
