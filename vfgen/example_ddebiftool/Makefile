WEBFILES = sys_init.m sys_rhs.m sys_deri.m sys_tau.m

VFGEN_OUTPUT = sys_init.m sys_rhs.m sys_deri.m sys_tau.m

ALL = $(VFGEN_OUTPUT)

all: $(ALL)

$(VFGEN_OUTPUT): ../example_auto/mg.vf
	vfgen ddebiftool:path=/home/wweckesser/ddebiftool ../example_auto/mg.vf

clean:

purge:
	rm -rf $(ALL)
