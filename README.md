![AVZones](https://github.com/AVUIs/AVZones/blob/master/AVZones.jpg "AVZones")

# AVZones
AudioVisual Zones - audiovisual sequencer for iOS built with openFrameworks + Maximilian

More info/acknowledgements:
http://www.avzones.org

By Nuno Correia:
http://www.nunocorreia.com

Part of the AVUIs project:
http://avuis.goldsmithsdigital.com

# Instructions

- Row 1: Delay (shift: menu)
- Row 2: Looper
- Row 3: Filter (shift: sequencer)
- Tap (row 2), move (rows 1,3): change x/y
- 2-finger tap: toggle on/off
- Double tap: shift (or choose menu item)

# Sound Files
You will need sound files, add them to the bin/data folder, and add their names to Playlist.cpp: https://github.com/AVUIs/AVZones/blob/master/Playlist.cpp

Files are organized in 3 folders, their names can be changed (check URL array in Playlist.cpp). The files I am currently using are from http://www.freesound.org. In Freesound, you can find the same files by searching the file name (number in the beggining of file name, or title). Thank you to the Freesound community.

# Dependencies
Built with openFrameworks: http://openframeworks.cc

Requires ofxmaxim addon for openFrameworks: https://github.com/micknoise/Maximilian
