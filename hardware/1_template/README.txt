
使用方法:
1.code文件夹执行make,编译得到二进制文件rk3288.bin;
2.使用rk3288_hardware_tool.sh生成rk3288_emmc.bin和rk3288_sd.bin;

- rk3288_emmc.bin用于emmc启动：
Windows下使用AndroidTool.exe,开发板进入MaskRom模式,烧入Loader位置;

- rk3288_sd.bin用于SD卡启动：
Linux下,插上SD卡,执行sudo dd if=rk3399_sd.bin of=/dev/sdb seek=$(((0x000040)))
(其中/dev/sdb为SD卡)

