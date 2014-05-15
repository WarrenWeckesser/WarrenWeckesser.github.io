# Files generated for the web page:
WEBFILES = pendulum_adolc.cpp pendulum_adolc.h pend7.png

ADOLC_BASE = $(HOME)/adolc_base

ALL = $(WEBFILES) pend7.dat

all: $(ALL)

pend7.png: pend7plot.py pend7.dat
	python pend7plot.py

pend7.dat: pend_solver
	./pend_solver > pend7.dat

pend_solver: Makefile-pend_solver pendulum_adolc.cpp pendulum_adolc.h
	make CPPFLAGS=-I$(ADOLC_BASE)/include LDFLAGS=-L$(ADOLC_BASE)/lib64 -f Makefile-pend_solver

pendulum_adolc.cpp pendulum_adolc.h: ../example_vf/pendulum.vf
	vfgen adolc ../example_vf/pendulum.vf

clean:
	rm -f pend7.dat *.tap *.o pend_solver

purge: clean
	rm -f $(WEBFILES)
