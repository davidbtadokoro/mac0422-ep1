EXECUTAVEIS := mac422shell bla bla_lento

all	: $(EXECUTAVEIS)

mac422shell : mac422shell.c
	gcc -Wall -o $@ $<

bla	: bla.c
	gcc -Wall -o $@ $<

bla_lento	: bla_lento.c
	gcc -Wall -o $@ $<

.PHONY	: limpa
limpa		:
	rm $(EXECUTAVEIS) 2> /dev/null
