# PCB

## Design

The PCB has been designed with KiCad 8.0.7. All components are in the KiCad component libraries or in the libraries in [`lib/`](lib).

## Ordering the PCB

You can print the PCB by yourself or you can order it from a fab house.
For the best results, I recommend:

* choosing a ENIG surface finish to have golden garlands and star
* if applicable, hide the order number. If not hidden, this order number will be most probably be written on the front of the PCB, as the surface is mostly empty.

## Soldering

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