CC=g++
file=a.cpp
out=q
run:
	$(CC) $(file) -o $(out)
e:
	vim $(file)
rm:
	rm .$(file).swo
	rm .$(file).swp
clean:
	rm $(out)
m:
	vim makefile
