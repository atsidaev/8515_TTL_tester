# refactoring the "res" variable usage

import re
import sys

with open(sys.argv[1]) as f:
	content = f.readlines()
	
for l in content:
	m = re.match("(^\s+res\s*=\s*)0\s*;\s*$", l);
	if m:
		print m.group(1) + "1;"
	else:
		# removing "else res = 0;"
		if re.match("^\s+else\s*res\s*=\s*0\s*;", l):
			print 
		else:
			# removing if (res==1) sym[0]=10; else sym[0]=11;
			if re.match("^\s+else\s*sym\[0\]\s*=\s*11\s*;", l) or re.match("^\s+if\s*\(res\s*==\s*1\s*\)\s*sym\[0\]\s*=\s*10\s*;", l):
				a = 1
			else:
				m = re.match("^(\s*)if\s*(.*)\s*res\s*=\s*1\s*;", l)
				if m:
					print m.group(1) + "res &= " + m.group(2).replace(" && (res==1)", "").strip() + ";"
				else:
					sys.stdout.write(l)
