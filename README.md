This is an Arduino sketch file, meant to be built and loaded from the Arduino IDE.

As of writing, the 2percentmilk board uses a 5V 16MHz pro micro clone with a bootloader preinstalled.

To get the Arduino IDE set up to load this sketch to the pro micro:

- go to `Tools > Manage Libraries...` and make sure the `Adafruit_Neopixel` and `Keyboard` libraries are installed.
- go to `Tools > Board` and select `Arudino Leonardo` (this board has the same bootloader and microcontroller)
- go to `Tools > Port` and make sure the port is correctly set (should say the board name)
- open the sketch from the repository and build and load the sketch

Notes / shortcomings:

- This was a quick build, so there are things that are likely not done the best way.
- One of those things is that I used `delay()` when I should have used a debounce library like `FTDebouncer`
- I could have also precompiled and uploaded a test `.hex` file, so that the only install dependency would be `avrdude` instead of the Arduino IDE, but the Arduino IDE would still be required to change the included phrases.
- Because RAM is so limited on these chips, the phrases are stored in the program memory as an array of `const char` arrays
- This could probably also be done in QMK, but I wasn't sure how much room I would have to add the phrases to program memory with the QMK libraries, so I didn't try
- If anyone wants to contribute, please do!

