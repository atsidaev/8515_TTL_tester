# http://mil.ufl.edu/3701/pinouts/74150.html
import re
import sys

with open(sys.argv[1]) as f:
    content = f.readlines()

state = 0
signals = []
name = ""
desc = ""

for line in content:
	
	if state == 2:
		m = re.search("^([^\|]*)\|[^\|]+\|( ([^ \|\r\n$]*)[ \|\r\n$])?", line)
		if m:
			left = m.group(1).strip()
			right = m.group(3)
			if right is None:
				right = ""
			right = right.strip()
			
			hl = int(len(signals) / 2)
			sss = [ left, right ]
			if hl == 0:
				signals = sss
			else:
				l1 = signals[:hl]
				l2 = signals[hl:]
				signals = l1 + sss + l2

	if state == 1:
		desc = line.strip()
		state = 2
		
	if state == 0 and re.search("<h2>", line):
		name = line.replace("<h2>", "").replace("</h2>", "").replace("</p>", "").strip()
		state = 1

	if line.startswith("</pre>"):
		print(name + " " + desc + " " + "/* " + " ".join(signals) + " */")
		state = 0
		signals = []

