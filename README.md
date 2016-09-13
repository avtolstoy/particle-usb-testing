## Intro
Use `feature/usb-descriptors-dfu` (https://github.com/spark/firmware/tree/feature/usb-descriptors-dfu) branch for full feature set:
- Composite USB
- Vendor requests
- Bootloader update (descriptors, WCID support)

system-part2 currently overflows 128K on Electron. Please use gcc 5.3 and `USE_PRINTF_FLOAT=n` when building.


## Windows prerequisites:
1. Old Windows driver (https://s3.amazonaws.com/spark-website/Spark.zip) installed and verified to work correctly with <= 0.5.x devices


## Linux/OSX prerequisites:
1. Install libusb-1.0
2. Build usbtool (https://github.com/avtolstoy/usbtool)


## Linux/OSX:
Verify that each test works correctly:

1. Each serial enabled should output `"%SerialName% millis=12345"` every second
2. Each serial enabled should also echo any received characters back
3. If HID is enabled, the device should move the pointer every 5 seconds
4. Device ID should be accessible through vendor-specific requests:
  - `$ ./usbtool -b -v 0x2b04 -p 0xPID control in vendor device 0x50 0 0`


### Pids are:

- `0xc006` - Photon
- `0xc008` - P1
- `0xc00a` - Electron
- `0xd006` - Photon DFU
- `0xd008` - P1 DFU
- `0xd00a` - Electron DFU


## Windows

1. Verify that tests 001_serial, 002_pre060_serial, 003_serial_hid work correctly with Old Windows driver (see Linux/OSX section for steps)
  1. NOTE: usbtool might fail because of caching
2. Install new driver https://ci.appveyor.com/api/buildjobs/05ordriewmsx0cjh/artifacts/installer%2Fparticle_drivers_6.1.0.25.exe
3. Verify that all the tests work correctly with the same steps as in Linux/OSX section.

`usbtool.exe` can be found in `windows` directory.

## Inspecting USB descriptors

- OSX: `osx/USB Prober.app.zip`
- Windows: `windows/usbview.exe`
- Linux: `$ lsusb -v`

## Bootloader

1. With USB cache cleared, the device should automatically install WinUSB driver for DFU interface using WCID (https://github.com/pbatard/libwdi/wiki/WCID-Devices)
