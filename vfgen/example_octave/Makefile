WEBFILES = vanderpol.m vanderpol_demo.m vanderpol_plot.svg

VFGEN_OUTPUT = vanderpol.m vanderpol_demo.m

vanderpol_plot.svg: $(VFGEN_OUTPUT)
	octave -qfW vanderpol_demo.m vanderpol_plot.svg

$(VFGEN_OUTPUT): ../example_vf/vanderpol.vf
	vfgen octave:func=yes,demo=yes ../example_vf/vanderpol.vf


clean:

purge:
	rm -f $(VFGEN_OUTPUT) vanderpol_plot.svg