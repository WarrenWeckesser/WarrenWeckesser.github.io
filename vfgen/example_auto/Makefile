WEBFILES = vanderpola_avf.c vanderpola_canards.png fortran/vanderpola_avf.f \
           mg_2ode.vf mg_2ode_avf.c mg_bif.png

all: example1 example2


example1: vanderpola_canards.png fortran/vanderpola_avf.f

vanderpola_canards.png: vanderpola_plotpos.auto s.vanderpola_bif
	auto vanderpola_plotpos.auto

s.vanderpola_bif: c.vanderpola_avf vanderpola_avf.c
	auto vanderpola.auto

vanderpola_avf.c: ../example_vf/vanderpola.vf
	vfgen auto ../example_vf/vanderpola.vf

fortran/vanderpola_avf.f: ../example_vf/vanderpola.vf
	vfgen auto:lang=fortran ../example_vf/vanderpola.vf
	mv vanderpola_avf.f fortran


example2: mg_bif.png

b.mg_bif: mg.auto mg_2ode_avf.c
	auto mg.auto

mg_bif.png: mg_bif_plot.py b.mg_bif
	python mg_bif_plot.py

mg_2ode_avf.c: mg_2ode.vf
	vfgen auto mg_2ode.vf

mg_2ode.vf: mg.vf
	vfgen delay2ode:N=20,p=2 mg.vf > mg_2ode.vf

clean:
	rm -f s.vanderpola_bif b.vanderpola_bif d.vanderpola_bif
	rm -f s.mg_bif b.mg_bif d.mg_bif

purge:
	rm -f s.vanderpola_bif b.vanderpola_bif d.vanderpola_bif
	rm -f s.mg_bif b.mg_bif d.mg_bif 
	rm -f vanderpola_canards.png vanderpola_avf.c
	rm -f fortran/vanderpola_avf.f
	rm -f mg_2ode.vf mg_2ode_avf.c
	rm -f mg_bif.png