WEBFILES = pendulum.py pendulum_demo.py pend.dat pendplot.png

VFGEN_OUTPUT = pendulum.py pendulum_demo.py
ALL = pend.dat pendplot.png $(VFGEN_OUTPUT)

all: $(ALL)

pendplot.png: pend.dat pendulum_plot.py
	python pendulum_plot.py

pend.dat: $(VFGEN_OUTPUT)
	python pendulum_demo.py b=0.5 abserr=1e-10 relerr=1e-8 > pend.dat

$(VFGEN_OUTPUT): ../example_vf/pendulum.vf
	vfgen pygsl:func=yes,demo=yes ../example_vf/pendulum.vf

clean:
	rm -f *.pyc

purge:
	rm -f $(ALL) *.pyc