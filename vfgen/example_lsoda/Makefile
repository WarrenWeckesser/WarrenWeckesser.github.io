WEBFILES = vanderpol_rhs.f vanderpol_demo.f vdp.dat vanderpol_plot.png \
           rossler_rhs.f rp_plot.png

VFGEN_EXAMPLE1_OUTPUT = vanderpol_rhs.f vanderpol_demo.f
VFGEN_EXAMPLE2_OUTPUT = rossler_rhs.f
ALL = $(VFGEN_EXAMPLE1_OUTPUT) $(VFGEN_EXAMPLE2_OUTPUT) vdp.dat vanderpol_plot.png rp.dat rp_plot.png

LSODA_OBJS = opkdmain.o opkda1.o opkda2.o 
EXAMPLE1_OBJS = vanderpol_rhs.o vanderpol_demo.o
EXAMPLE2_OBJS = rossler_pmap.o rossler_rhs.o 

all: $(ALL)

vanderpol_plot.png: ../example_radau5/vanderpol_plot.py vdp.dat
	python ../example_radau5/vanderpol_plot.py

vdp.dat: vanderpol_demo
	./vanderpol_demo > vdp.dat

vanderpol_demo:	$(EXAMPLE1_OBJS) $(LSODA_OBJS)
	gfortran $(EXAMPLE1_OBJS) $(LSODA_OBJS) -o vanderpol_demo

rossler_pmap: $(EXAMPLE2_OBJS) $(LSODA_OBJS)
	gfortran $(EXAMPLE2_OBJS) $(LSODA_OBJS) -o rossler_pmap

rp_plot.png: rp_plot.py rp.dat
	python rp_plot.py

rp.dat: rossler_pmap
	./rossler_pmap > rp.dat

%.o: %.f
	gfortran -c $<

$(VFGEN_EXAMPLE1_OUTPUT): ../example_vf/vanderpol.vf
	vfgen lsoda:demo=yes ../example_vf/vanderpol.vf

$(VFGEN_EXAMPLE2_OUTPUT): ../example_vf/rossler.vf
	vfgen lsoda:func=yes ../example_vf/rossler.vf

clean:
	rm -f *.o rossler_pmap vanderpol_demo rp.dat

purge:
	rm -f $(ALL) *.o rossler_pmap vanderpol_demo
