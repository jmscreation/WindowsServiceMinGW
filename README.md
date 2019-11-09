# Create A Windows Service Using MinGW


This project demonstrates compiling a windows service using MinGW with the CodeBlocks IDE.

This uses MinGW 7.3.0, with the -m64 compile flag.
I personally prefer to compile 64bit applications as this is what all future operating systems will eventually be required to run; however, this project should (this has not yet been tested) still compile for 32bit operating systems.

Setup:

To get you up and running, you need to have CodeBlocks IDE installed.
You also need to setup CodeBlocks with the right compiler: MinGW 7.3.0
Also note: Your antivirus will flag your binary as dangerous. The reason for this is due to the unsigned executable that straight installs a windows service. Under normal circumstances, this is very dangerous if you don't know the code or you don't know what you are doing. Because this is for educational purposes, this is safe to do so.

[Download MinGW 7.3.0 64bit posix](https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win64/Personal%20Builds/mingw-builds/7.3.0/threads-posix/seh/x86_64-7.3.0-release-posix-seh-rt_v5-rev0.7z/)
 From SourceForge
 
 OR
 
 [Download MinGW 7.3.0 32bit + 64bit](https://drive.google.com/file/d/1eP2pXOpo5BoWE7jLX24OWZvxNyXDGaJx/view)
 From Google Drive

You may also use the compiler below as I've confirmed that this compiler works. However, my main compiler for most C++ programming is done using MinGW 7.3.0 x86_64 threads-posix-seh

[Download MinGW 7.3.0 64bit threads-win32-sjlj](https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win64/Personal%20Builds/mingw-builds/7.3.0/threads-win32/sjlj/x86_64-7.3.0-release-win32-sjlj-rt_v5-rev0.7z)

#After Compiling

Once you get the binary compiled, you can simply run the Service.exe from the command line as follows:

```Service.exe /install```  Install the service and start it
```Service.exe /remove```  Stop and uninstall the service
```Service.exe /start```  Start the service if it's not running

These are currently the only command lines available.
