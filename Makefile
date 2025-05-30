all:
	python dronecan_dsdlc/dronecan_dsdlc.py -O dsdl_gen local DSDL/uavcan

clean:
	rm -rf dsdl_gen

.PHONY: all clean
