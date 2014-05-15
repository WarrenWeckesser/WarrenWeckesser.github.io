WEBFILES = pendulum.tex main.pdf MackeyGlass2.tex mg2.pdf

ALL = main.pdf mg2.pdf pendulum.tex MackeyGlass2.tex

all: $(ALL)

main.pdf: main.tex pendulum.tex
	pdflatex main.tex

mg2.pdf: mg2.tex MackeyGlass2.tex
	pdflatex mg2.tex

pendulum.tex: ../example_vf/pendulum.vf
	vfgen latex ../example_vf/pendulum.vf

MackeyGlass2.tex: MackeyGlass2.vf
	vfgen latex MackeyGlass2.vf


clean:
	rm -f *.aux *.log

purge:
	rm -f $(ALL) *.aux *.log
