WEBFILES = pendulum_gvf.c pendulum_gvf.h pendulum_solve.c Makefile-pendulum \
           pendulum.dat pendulum_plot.png

VFGEN_OUTPUT = Makefile-pendulum pendulum_gvf.c pendulum_gvf.h pendulum_solve.c
ALL = pendulum_plot.png pendulum.dat $(VFGEN_OUTPUT)

all: $(ALL)

pendulum_plot.png: pendulum_plot.py pendulum.dat
	python pendulum_plot.py

pendulum.dat: pendulum_solve
	./pendulum_solve v=0.0 theta=3.14 b=0.2 abserr=1e-9 stoptime=10 > pendulum.dat 

pendulum_solve: $(VFGEN_OUTPUT)
	make -f Makefile-pendulum

$(VFGEN_OUTPUT): ../example_vf/pendulum.vf
	vfgen gsl:func=yes,demo=yes ../example_vf/pendulum.vf

clean:
	rm -f *.o pendulum_solve

purge:
	rm -f $(ALL) *.o pendulum_solve
