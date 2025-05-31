DSDL_GENERATED_DIR = dsdl_generated

all:
	python dronecan_dsdlc/dronecan_dsdlc.py -O $(DSDL_GENERATED_DIR) local DSDL/uavcan

clean:
	rm -rf $(DSDL_GENERATED_DIR)

.PHONY: all clean
