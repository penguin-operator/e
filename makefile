src = $(wildcard src/**.c)

e:
	gcc $(src) -o $@ -Iinclude -O0 -g
