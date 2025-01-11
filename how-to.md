# Christmas Tree PCB How To

Here are the instructions on how to make your own Christmas Tree PCB, divided in three sections:

- [Microcontroller Programming](#microcontroller-programming)
- [PCB Shape and Art](#pcb-shape-and-art)
- [PCB Design and Assembly](#pcb-design-and-assembly)

## Microcontroller Programming

The PCB was not designed with reprogrammability in mind.
Hence, the ATtiny microcontrollers must be programed before assembly.

### Circuit to flash the ATTiny MCU

The ATtiny202-SS microcontroller is programmed using the UPDI interface.
You can use a Serial UPDI Programmer like [this one](https://github.com/wagiminator/AVR-Programmer/tree/master/SerialUPDI_Programmer) from @wagiminator.
Otherwise, you can also build the following circuit on a breadboard ([Source](https://github.com/microchip-pic-avr-tools/pymcuprog?tab=readme-ov-file#serial-port-updi-pyupdi)):

```
                        Vcc                     Vcc
                        +-+                     +-+
                         |                       |
 +---------------------+ |                       | +--------------------+
 | Serial port         +-+                       +-+  AVR device        |
 |                     |      +----------+         |                    |
 |                  TX +------+   1k     +---------+ UPDI               |
 |                     |      +----------+    |    |                    |
 |                     |                      |    |                    |
 |                  RX +----------------------+    |                    |
 |                     |                           |                    |
 |                     +--+                     +--+                    |
 +---------------------+  |                     |  +--------------------+
                         +-+                   +-+
                         GND                   GND
```

To connect my circuit to a USB port, I used a [FT232RL USB to TTL](https://www.amazon.ca/dp/B01JG8H5U4) Serial Adapter Module set with a logic level voltage of 3.3 V.
One can also use an adapter like [this breakout](https://www.sparkfun.com/products/9873) from Sparkfun or [this console cable](https://www.adafruit.com/product/954) from Adafruit, as long as the logic level of the Serial port is at 3.3V.

### Software tools to flash the MCU

The PlatformIO project in [`firmware`](firmware) uses [`pymcuprog`](https://github.com/microchip-pic-avr-tools/pymcuprog) to program the ATTINY202-SSFR, as shown in the [`platformio.ini`](firmware/platformio.ini#L28) file.
You can install `pymcuprog` using pip:

```sh
pip install pymcuprog
```

To test that your ATTiny will be flashed correctly with `pymcuprog`, you can ping it with:

```console
pymcuprog ping -d attiny202 -t uart -u /dev/<device-port>
```

You can also read some bytes from the flash memory space with this command, where we read `64` bytes from a offset `0x100`

```console
pymcuprog read -m flash -o 0x0100 -b 64 -d attiny202 -t uart -u /dev/<device-port>
```

### Programming verification

You can verify that the MCU is properly programmed by adding the LED circuit of [the schematic](pcb/output/schematics.pdf) to your programming breadboard.

## PCB Shape and Art

The shape of the PCB was

This section gives all informations about the design of the Christmas Tree Shape, from the the Solder Mask are given [here](mcad).

### PCB Edge Cut

In the original version of the project, the edge cut of the PCB was originally designed in 2023 with RealThunder's [FreeCAD Link Branch](https://github.com/realthunder/FreeCAD), using the [KicadStepUp Workbench](https://wiki.freecad.org/KicadStepUp_Workbench).
The file [`christmas-tree-pcb.FCStd`](mcad/christmas-tree-pcb.FCStd) of this repo, contains a copy of the PCB sketch, made with [FreeCAD 1.0](https://wiki.freecad.org/Release_notes_1.0).

![Christmas Tree Sketch](mcad/sketch.png)

### Solder Mask

The golden star and garlands are drawn using the front copper layer and a solder mask. While the outline of the garlands was [drawn on the front solder mask](mcad/front-mask.svg) with KiCad, they were [filled](mcad/garlands.svg) using Inkscape.

| Front Mask                   | Garlands                      |
| ---------------------------- | ----------------------------- |
| ![Mask](mcad/front-mask.svg) | ![Garland](mcad/garlands.svg) |


## PCB Design and Assembly

The PCB has been designed with KiCad 8.0.7. All components files are available in the KiCad component libraries or in the project libraries in [`pcb/lib/`](pcb/lib).

### Printing or ordering the PCB

You can print the PCB by yourself or you can order it from a fab house.
For the best results when ordering, I recommend:

* choosing a ENIG surface finish to have golden garlands and star
* if applicable, hide the order number. If not hidden, this order number will be most probably be written on the front of the PCB, as the surface is mostly empty.

### Assembly

The PCB was designed to be easily soldered by hand, as I used this project as an opportunity how to solder SMD components by hand.
Hence why all resistors and LEDs are 1206.

If you never soldered SMDs before, a good practice is to start with small components.
Hence, for this PCB, I would recommend soldering the components in the following order:

* Start with either the LEDs or the resistors
* Continue with the resistors or the LEDs on the other side.
* Solder the ATtiny.
  * This component turned out to be the hardest to solder. Luckily there are plenty of tutorials on YouTube on how to solder SOIC components.
  * Once soldered, I tested the continuity to ensure that each lead is properly soldered to his corresponding pad. You can use the PCB schematic and layout files to determine where to probe for continuity.
* Solder the coin cell battery retainer.
  * Put a blob of solder on each small side pad.
  * Then, for each pad, insert a flap of the retainer while keeping the iron on the blob.
  * You can then adjust the position of the retainer by iteratively moving it while melting the solder on a pad. Once the retainer is well placed, add more solder above each flap so that you're sure that it won't easily break out.
* Finally, solder the through-hole switch. Once soldered, I recommend using a wire cutter to cut the tips of the leads.


## Sources

* Programming with UPDI:
  * [JTAG2UPDI and SerialUPDI](https://teddywarner.org/Projects/SerialUPDI)
  * [SerialUPDI Programmer](https://github.com/wagiminator/AVR-Programmer/tree/master/SerialUPDI_Programmer)

