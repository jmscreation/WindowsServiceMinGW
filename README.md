# Create A Windows Service Using MinGW


This project demonstrates compiling a windows service using MinGW with the CodeBlocks IDE.

This uses MinGW 7.3.0, with the -m64 compile flag.
I personally prefer to compile 64bit applications as this is what all future operating systems will eventually be required to run; however, this project should (this has not yet been tested) still compile for 32bit operating systems.

## Setup

To get you up and running, you need to have CodeBlocks IDE installed.
You also need to setup CodeBlocks with the right compiler

### MinGW 7.3.0 Downloads

[Download MinGW 7.3.0 64bit posix](https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win64/Personal%20Builds/mingw-builds/7.3.0/threads-posix/seh/x86_64-7.3.0-release-posix-seh-rt_v5-rev0.7z/)
 From SourceForge
 
 OR
 
 [Download MinGW 7.3.0 32bit + 64bit](https://drive.google.com/file/d/1eP2pXOpo5BoWE7jLX24OWZvxNyXDGaJx/view)
 From Google Drive

You may also use the compiler below as I've confirmed that this compiler works. However, my main compiler for most C++ programming is done using MinGW 7.3.0 x86_64 threads-posix-seh

[Download MinGW 7.3.0 64bit threads-win32-sjlj](https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win64/Personal%20Builds/mingw-builds/7.3.0/threads-win32/sjlj/x86_64-7.3.0-release-win32-sjlj-rt_v5-rev0.7z)

### Windows Service Definitions
There are a ton of settings you can change for your windows service in the [defines.h](https://github.com/jmscreation/WindowsServiceMinGW/blob/master/defines.h) header file.
This allows you to configure some basic and advanced settings quickly and efficiently. If you are able to compile without any issues, you may now go ahead and make any changes here.

### Event Logs
If you have [SERVICE_LOG](https://github.com/jmscreation/WindowsServiceMinGW/blob/f26316532bd0c07df6a6ab5b6db8289eaf011936/defines.h#L36) set to TRUE, you will start getting event logs for your service.
To check your event logs, simply open up the Windows event viewer, and open up *Windows Logs -> Application*
Your service's logged events will have your [SERVICE_NAME](https://github.com/jmscreation/WindowsServiceMinGW/blob/f26316532bd0c07df6a6ab5b6db8289eaf011936/defines.h#L6) in the log.

### Creating Your Service
Once you are comfortable with the program compiling and configuring your service settings, you will want to create your service application.
You will be able to write your own service code [in the SampleService.cpp file](https://github.com/jmscreation/WindowsServiceMinGW/blob/dad6d5a984c38d14d9a606014d63a0f135d2a7ef/library/SampleService.cpp#L97).
This is where your code may go. It is not required to have your code here. It may help to instead instantiate an object of your own service application class, and execute an update within the while loop.

### Please Note
Your antivirus will flag your binary as dangerous. The reason for this is due to the unsigned executable that straight installs a windows service. Under normal circumstances, this is very dangerous if you don't know the code or you don't know what you are doing. Because this is for educational purposes, this is safe to do so.

## After Compiling

Once you get the binary compiled, you can simply run the Service.exe from the command line as follows:

`Service.exe /install` *Install the service and start it*

`Service.exe /remove` *Stop and uninstall the service*

`Service.exe /start`  *Start the service if it's not running*

These are currently the only command lines available.
