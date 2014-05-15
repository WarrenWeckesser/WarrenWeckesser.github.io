WEBFILES = lorenz.js lorenz_solverdemo.js lorenz.html


VFGEN_OUTPUT = lorenz.js lorenz_solverdemo.js lorenz.html

ALL = $(VFGEN_OUTPUT)

all: $(ALL)

$(VFGEN_OUTPUT): ../example_vf/lorenz.vf
	vfgen javascript:order=7,demo=yes ../example_vf/lorenz.vf


clean:

purge:
	rm -rf $(ALL)
