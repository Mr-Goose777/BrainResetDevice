# BrainResetDevice
For arduino nano.
- Sequential Illumination: The LEDs light up in a specific sequence, illuminating either the right visual field or the left of both eyes.
- 40 Hz or 60 Hz frequency.
- Random Flickering Mode: random flickering of all four LEDs simultaneously.

  All you need:
  - 4x white LEDs
  - 1 x Arduino nano
  - 2 piezo speakers
  - some wire
  - Power: Battery (pack) over 6V (4x AA oder AAA battery, or 9v cell, over Vin / ground)  or over USB port (USB-Charger / powerpack + USB-cable)
  - Some way to connect those together( Soldering iron or breadboard etc.).
  - A pair of cheap broken sunglasses (maybe take the glasses out)
  - Glue or tape, Preferrably of the double sided kind.

    Download: brainreset40hz60hzRandom.ino from master, compile using latest arduino IDE, upload.
    
    An step by step explaination to do the above can be found here: https://www.arduino.cc/en/Guide/ArduinoNano

    **You will need to add the elapsedMillis library by  pfeerick, you can do so in Arduino IDE by going to Tools -> Manage Linraries.**
    
The reason I built this are the following studies: 
Multi-sensory Gamma Stimulation Ameliorates Alzheimer’s-Associated Pathology and Improves Cognition   (https://doi.org/10.1016/j.cell.2019.02.014)

Non-invasive 40-Hz Light Flicker Ameliorates Alzheimer’s-Associated Rhythm Disorder via Regulating Central Circadian Clock in Mice   (https://doi.org/10.3389/fphys.2020.00294)


Ketamine and flickering light bring youthful plasticity to older brains    (Science  By Nick Lavars July 06, 2021 )

Microglia enable mature perineuronal nets disassembly upon anesthetic ketamine exposure or 60-Hz light entrainment in the healthy brain (https://doi.org/10.1016/j.celrep.2021.109313)

The random mode is just randomly there to spice things up. Make it less repetative.

Don't worry about LED resistors. They are only on for 1ms or 500 microseconds, or running at very low PWM. seriously. Say NO to OCD. It will work fine. Trust me. NO TO OCD. YAY ✌️
 
demonstration (Normal / Slowmo / just 60 Hz mode) : https://www.youtube.com/watch?v=WaUFnwsd4EI

![image](https://github.com/Mr-Goose777/BrainResetDevice/assets/141585273/26ba025b-6d47-402a-a107-e057432901e0)

