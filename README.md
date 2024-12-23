# Christmas Tree PCB






## Flashing the ATTiny MCU

I used [`pymcuprog`](https://github.com/microchip-pic-avr-tools/pymcuprog) to program the ATTINY202-SSFR. You can install `pymcuprog` using pip:

```sh
pip install pymcuprog
```

:construction: Documentation in progress :construction:
TODO: Add circ

<!-- Circuit -->
<!-- https://github.com/microchip-pic-avr-tools/pymcuprog?tab=readme-ov-file#serial-port-updi-pyupdi -->

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

