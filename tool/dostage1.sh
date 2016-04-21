#!/bin/bash
for i in test_*.c
do
	python3 tool/stage1.py $i > $i.out
done
rm test_*.c
rename .c.out .c *.out
