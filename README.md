# Simple socket chat app
As of now you are able to get the server running on one machine (say your PC) and the client on another machine (say your laptop). Only drawbacks are they both have to be running Windows and have to be connected to the same network. 

It uses WinSock2 for sockets and I'm writing it in C++14.

Currently, the received messages are coloured aqua and received ones are coloured red.

You can only send one message at a time, i.e. client sends a message. Then the app waits for response from server and vice-versa. And so on, and so forth.
