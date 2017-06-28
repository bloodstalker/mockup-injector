#!/bin/bash

"make" clean
"make" all
"./syscallinjecter" > strace-log
"strace" ./syscallinjecter 2>> strace-log
