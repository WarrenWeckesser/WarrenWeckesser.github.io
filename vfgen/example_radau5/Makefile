WEBFILES = vanderpol_rhs.f vanderpol_dr5.f

VFGEN_OUTPUT = vanderpol_rhs.f vanderpol_dr5.f
OBJS = vanderpol_dr5.o vanderpol_rhs.o radau5.o dc_lapack.o
ALL = $(VFGEN_OUTPUT) vanderpol_plot.png vdp.dat vanderpol_dr5

all: $(ALL)

vanderpol_plot.png: vanderpol_plot.py vdp.dat
	python vanderpol_plot.py

vdp.dat: vanderpol_dr5
	./vanderpol_dr5 > vdp.dat

vanderpol_dr5:	$(OBJS)
	gfortran $(OBJS) -llapack -o vanderpol_dr5

%.o: %.f
	gfortran -c $<

$(VFGEN_OUTPUT): ../example_vf/vanderpol.vf
	vfgen radau5:demo=yes ../example_vf/vanderpol.vf


clean:
	rm -f *.o vdp.dat vanderpol_dr5

purge:
	rm -f $(ALL) *.o
