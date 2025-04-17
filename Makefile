dsdl_generated:
	python dronecan_dsdlc/dronecan_dsdlc.py -O dsdl_generated DSDL/uavcan local/

clean:
	rm -rf dsdl_generated 

.PHONY: clean
