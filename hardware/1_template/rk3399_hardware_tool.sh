#!/bin/bash

set -e

CREATE_EMMC_BIN()
{
	./tools/boot_merger ./tools/rk3399_emmc_config.ini
	mv rk3399_emmc_V1.09.bin rk3399_emmc.bin
	
	echo "emmc ok!"
}

CREATE_SDCARD_IMG()
{
	./tools/boot_merger ./tools/rk3399_sd_config.ini
	./tools/boot_merger --gensdboot ./rk3399_sd_V1.10.bin
	rm rk3399_sd_V1.10.bin 	
	mv SD.bin rk3399_sd.bin
	echo "sdcard ok!"
}

CREATE_EMMC_BIN
CREATE_SDCARD_IMG





