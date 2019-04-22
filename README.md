g930-battery-percentage-win
===========================

Screenshots
-----------
![screenshot](https://user-images.githubusercontent.com/5454041/56529770-98185a80-6551-11e9-9d56-4ef148663151.png)

Description
-----------
This is a [g930-battery-percentage](https://github.com/Roliga/g930-battery-percentage) Windows port achieved by using the [hidapi](https://github.com/signal11/hidapi) `hidtest` as a base. Only the main executable has been ported, this means no low battery notification or auto-checking service.

Usage
-----
Just start the `g930-battery-percentage-win.exe` exectuable, preferably from a command line window so you actually have time to read the output. That's all this does for now.

Known issues
------------
This won't work if Logitech's G930 monitoring software is running (only tested with the old one, but I assume it's the same for the LGS): this is probably because they use exclusive HID access; I doubt there's a way around this.

Compiling & testing
-------------------
This project has been compiled with Visual Studio Community 2017 and tested on Windows 7 x64.

License
-------
This software utilizes code from [g930-battery-percentage](https://github.com/Roliga/g930-battery-percentage), published under the [MIT License](https://github.com/Wyse-/g930-battery-percentage-win/blob/master/LICENSE).

This software utilizes code from [hidapi](https://github.com/signal11/hidapi), published under the [HIDAPI License](https://github.com/Wyse-/g930-battery-percentage-win/blob/master/LICENSE_hidapi.txt).

