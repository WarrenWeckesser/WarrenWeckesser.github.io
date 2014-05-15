WEBFILES = pendulum.py pendulum_demo.py pendulum_plot.png

VFGEN_OUTPUT = pendulum.py pendulum_demo.py
ALL = pend.dat pendulum_plot.png $(VFGEN_OUTPUT)

all: $(ALL)

pendulum_plot.png: pend.dat pendulum_plot.py
	python pendulum_plot.py

pend.dat: pendulum_demo.py pendulum.py
	python pendulum_demo.py theta=3.1 b=0.5 stoptime=10 > pend.dat

$(VFGEN_OUTPUT): ../example_vf/pendulum.vf
	vfgen scipy:func=yes,demo=yes ../example_vf/pendulum.vf

clean:
	rm -f *.pyc pend.dat

purge:
	rm -f $(ALL) *.pyc
