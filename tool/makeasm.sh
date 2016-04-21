for i in *.c
do
	echo '#include "mock/mock.h"' > temp.c
	cat $i >> temp.c
	gcc -S temp.c
	mv temp.S $i.S
	rm temp.c
done
