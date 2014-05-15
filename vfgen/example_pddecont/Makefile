# This Makefile doesn't run pdde, and it doesn't generate any of the PNG files.

WEBFILES = sys-ShayerCampbell2000.cpp sys-wn2.cpp sys-wn2-edit.cpp


all: sys-ShayerCampbell2000.cpp sys-wn2.cpp sys-wn2-edit.cpp

sys-ShayerCampbell2000.cpp: ../example_vf/ShayerCampbell2000.vf
	vfgen pddecont ../example_vf/ShayerCampbell2000.vf

sys-wn2.cpp: wn2.vf
	vfgen pddecont wn2.vf

sys-wn2-edit.cpp: sys-wn2.cpp
	sed -e '1,5s/sys-wn2.cpp/sys-wn2-edit.cpp -- Edited to add an approximate solution in sys_stsol/' \
        -e '/stsol/,/}/s/out.0. = .*;/out(0) = 1.85*cos(t-0.34);/' \
        -e '/stsol/,/}/s/out.1. = .*;/out(1) = 1.79*cos(t+1.2);/' \
        sys-wn2.cpp > sys-wn2-edit.cpp

clean:

purge:
	rm -f sys-ShayerCampbell2000.cpp sys-wn2.cpp sys-wn2-edit.cpp
