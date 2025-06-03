DSDL_GENERATED_DIR = dsdl_generated
INSTALL_DIR = ~/uavcan_vendor_specific_types

all:
	python dronecan_dsdlc/dronecan_dsdlc.py -O $(DSDL_GENERATED_DIR) local DSDL/uavcan

install:
	mkdir -p $(INSTALL_DIR)
	ln -sf $(CURDIR)/local $(INSTALL_DIR)/local

clean:
	rm -rf $(DSDL_GENERATED_DIR)

.PHONY: all clean
