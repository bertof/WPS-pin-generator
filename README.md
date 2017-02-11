WPS Pin Generator
========
## What is this?
It is a Wireless Protected Setup (WPS) pin generator, which uses a an algorithm commonly found on commercial routers to generate their default pin.
The pin found can be used with programs like <a href="https://github.com/t6x/reaver-wps-fork-t6x">Reaver</a> to attack vulnerable WiFi routers.

## Why?
Since i moved from Ubuntu to ArchLinux the old good WPSPIN.sh from <a href="https://github.com/linkp2p/WPS-PIN">linkp2p's WPS-PIN</a> no longer works (it cannot find the network interfaces), so I'm creating this simple program in C++ to generate the same results but in a less integrated and more platform independent way.

## Legal
This program is shared as it is and in an open license so everyone can use it. 

I am not the original creator of the algorithm. 
The original discoverer of the algorithm is zhaochunsheng, who has written a C implementation in his script <a href="https://foro.elhacker.net/wireless_en_windows/computepinc83a35-t358629.0.html">computepinC83A35</a>.
All names and history of that file can be found in <a href="https://github.com/linkp2p/WPS-PIN">linkp2p's repository</a>. 

The use of this program is intended to be in a authorized environment. Don't use it against networks you do not own or you do not have legal permission to attack.
Every illicit use of this program has nothing to do with the author.