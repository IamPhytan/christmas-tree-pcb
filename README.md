# Christmas Tree PCB

## Christmas Tree Shape

The Christmas Tree shape has been drawn on the Edge Cuts layer.
 of the christmas tree

All informations about the design of the Christmas Tree Shape, including the Solder Mask are given [here](mcad).

## PCB

All informations about the PCB are given in the [`pcb`](pcb) directory.

## Flashing the ATTiny MCU

I used [`pymcuprog`](https://github.com/microchip-pic-avr-tools/pymcuprog) to program the ATTINY202-SSFR. You can install `pymcuprog` using pip:

```sh
pip install pymcuprog
```

:construction: Documentation in progress :construction:
TODO: Add circ

<!-- Circuit -->
<!-- https://github.com/microchip-pic-avr-tools/pymcuprog?tab=readme-ov-file#serial-port-updi-pyupdi -->

VDD = 3.3V logic level

I used a [FT232RL USB to TTL](https://www.amazon.ca/dp/B01JG8H5U4) Serial Adapter Module to connect my circuit to a USB port. One can also use an adapter like [this breakout](https://www.sparkfun.com/products/9873) from Sparkfun or [this console cable](https://www.adafruit.com/product/954) from Adafruit


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

To test that your ATTiny will be flashed correctly with `pymcuprog`, you can ping it with:

```console
pymcuprog ping -d attiny202 -t uart -u /dev/<device-port>
```

You can also read some bytes from the flash memory space with this command, where we read `64` bytes from a offset `0x100`

```console
pymcuprog read -m flash -o 0x0100 -b 64 -d attiny202 -t uart -u /dev/<device-port>
```


## Some references

* [JTAG2UPDI and SerialUPDI](https://teddywarner.org/Projects/SerialUPDI)

