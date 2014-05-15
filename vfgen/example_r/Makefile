# The R commands are not run, so this Makefile does not
# regenerate the PNG files.

WEBFILES = pendulumv.R pendulumv_demo.R MackeyGlass.R MackeyGlass_demo.R

VFGEN_EXAMPLE1_OUTPUT = pendulumv.R pendulumv_demo.R
VFGEN_EXAMPLE2_OUTPUT = MackeyGlass.R MackeyGlass_demo.R


all: example1 example2


example1: $(VFGEN_EXAMPLE1_OUTPUT)

$(VFGEN_EXAMPLE1_OUTPUT): ../example_vf/pendulumv.vf
	vfgen r:func=yes,demo=yes ../example_vf/pendulumv.vf


example2: $(VFGEN_EXAMPLE2_OUTPUT) MackeyGlass_demo_edit.R

MackeyGlass_demo_edit.R: MackeyGlass_demo.R
	sed 's/times = seq(0, 10, by = 0.02)/times = seq(0, 500, by = 0.25)/' \
        MackeyGlass_demo.R > MackeyGlass_demo_edit.R

$(VFGEN_EXAMPLE2_OUTPUT): ../example_vf/MackeyGlass.vf
	vfgen r:demo=yes ../example_vf/MackeyGlass.vf


clean:
	rm -f MackeyGlass_demo_edit.R

purge:
	rm -f $(VFGEN_EXAMPLE1_OUTPUT) $(VFGEN_EXAMPLE2_OUTPUT) MackeyGlass_demo_edit.R