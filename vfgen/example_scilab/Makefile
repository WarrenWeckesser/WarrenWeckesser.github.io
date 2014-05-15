WEBFILES = pendulum.sci pendulum_demo.sce

VFGEN_OUTPUT = pendulum.sci pendulum_demo.sce
ALL = $(VFGEN_OUTPUT)


all: $(ALL)

$(VFGEN_OUTPUT): ../example_vf/pendulum.vf
	vfgen scilab:func=yes,demo=yes ../example_vf/pendulum.vf

clean:

purge:
	rm -f $(ALL)
