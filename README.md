# mockup-injector

well it's a mock-up but not much of an injector. For our purposes, consider it a simulation.<br/>
It just explains Martin's idea.<br/>
The CPP executable acts like the VM, it gives us the address and size of certain parts of its process memory(the state variables we need).<br/>
`strace` acts as our out-of-process code that takes the snapshot of the variables that we need. Once we have all the state variables, we can merklize them.<br/>

## running
just run these:

```bash

git clone https://github.com/bloodstalker/mockup-injector.git
chmod +x runme.sh
./runme.sh

```

