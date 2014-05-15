WEBFILES = pendulum_cv.c pendulum_cv.h pendulum_cvdemo.c Makefile-pendulum_cvdemo \
           pend.dat pendplot.png

VFGEN_OUTPUT = Makefile-pendulum_cvdemo pendulum_cv.c pendulum_cv.h pendulum_cvdemo.c
ALL = pendplot.png pend.dat $(VFGEN_OUTPUT)

all: $(ALL)

pendplot.png: pendulum_plot.py pend.dat
	python pendulum_plot.py

pend.dat: pendulum_cvdemo
	./pendulum_cvdemo v=0.0 theta=3.14 b=0.5 stoptime=10 > pend.dat

pendulum_cvdemo: $(VFGEN_OUTPUT)
	make -f Makefile-pendulum_cvdemo

$(VFGEN_OUTPUT): ../example_vf/pendulum.vf
	vfgen cvode:func=yes,demo=yes ../example_vf/pendulum.vf

clean:
	rm -f *.o pendulum_cvdemo

purge:
	rm -f $(ALL) *.o pendulum_cvdemo
