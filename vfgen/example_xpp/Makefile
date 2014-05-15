WEBFILES = pendulum.ode MackeyGlass.ode

ALL = $(WEBFILES)

all: $(ALL)

pendulum.ode: ../example_vf/pendulum.vf
	vfgen xpp ../example_vf/pendulum.vf

MackeyGlass.ode: ../example_vf/MackeyGlass.vf
	vfgen xpp:extra="@ total=500;@ delay=20;@ maxstor=15000;@ xlo=0;@ xhi=500;@ ylo=0;@ yhi=1.5;" ../example_vf/MackeyGlass.vf

clean:

purge:
	rm -f $(ALL)