# neotrellis_monome_teensy

> **⚠️ Untested:** The latest changes (rotation support, serialosc compatibility fixes, standard vari-bright protocol) have not been tested on hardware yet. Firmware and pyserialoscd must be updated together, as the serial protocol changed.
> Last stable versions: [neotrellis_monome_teensy](https://github.com/nexxyz/neotrellis_monome_teensy/tree/898ff18d4dbc19901a527cd97102ca7632c30869) and [pyserialoscd](https://github.com/nexxyz/pyserialoscd/tree/580b5ac89caa787ccd0d50803da273f81f6907f6).

Changes compared to the original:

- Waits for every byte of a message, so messages split across USB packets (e.g. a 35 byte level map) are no longer garbled.
- Leds outside the grid are ignored instead of wrapping into the next row (e.g. negative or too large offsets).
- Vari-bright map/row/col (0x1A-0x1C) use the standard packed format (two 4-bit levels per byte), as sent by serialosc and [my pyserialoscd implementation](https://github.com/nexxyz/pyserialoscd).
- /grid/led/intensity scales the brightness of all leds (also vari-bright ones) like on a real grid, including leds that are already lit.
- If you use several grids, give each a unique `deviceID` in `neotrellis_monome_teensy.ino`.
- Debug output is disabled by default, as it shares the serial port with the monome protocol (see `debug.h`).

Rotation is handled by serialosc / pyserialoscd, not by the firmware.
