WEBFILES = vanderpol.py vanderpol_dst.py vanderpol_plot.png \
           MorrisLecar.py MorrisLecar_cont.png

VFGEN_EXAMPLE1 = vanderpol.py vanderpol_dst.py
VFGEN_EXAMPLE2 = MorrisLecar.py

all: example1 example2


example1: vanderpol_plot.png $(VFGEN_EXAMPLE1)

vanderpol_plot.png: $(VFGEN_EXAMPLE1)
	python vanderpol_dst.py vanderpol_plot.png

$(VFGEN_EXAMPLE1):
	vfgen pydstool:demo=yes ../example_vf/vanderpol.vf


example2: MorrisLecar_cont.png $(VFGEN_EXAMPLE2)

MorrisLecar_cont.png: $(VFGEN_EXAMPLE2)
	python MorrisLecar_cont.py

$(VFGEN_EXAMPLE2): ../example_vf/MorrisLecar.vf
	vfgen pydstool ../example_vf/MorrisLecar.vf


clean:
	rm -f *.pyc

purge:
	rm -f *.pyc
	rm -f vanderpol_plot.png $(VFGEN_EXAMPLE1)
	rm -f MorrisLecar_cont.png $(VFGEN_EXAMPLE2)
