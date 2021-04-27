# FakeFeed

FakeFeed is a Kirigami based application that replaces the original camera feed with a virtual video devices. Normal (v4l2) applications will read these devices as if they were ordinary video devices, but the video will not be read from e.g. a capture card but instead it is generated by this application.


# Requirements

- kirigami2 
- kde-sdk-meta 
- gettext
- FFmpeg
- [v4l2loopback-dkms](https://github.com/umlaeute/v4l2loopback/archive/refs/tags/v0.12.5.tar.gz)

This list might become incomplete in future due to development. Therefore kindly look at CMakeLists.txt files and build logs for in-situ detail. 

# Build

- `$ git clone https://github.com/deprov447/fakefeed.git`
- `$ mkdir build && cd build`
- `$ cmake ..`
- `$ make -j$(nproc)`
- `$ sudo bin/FakeFeed`

This assumes all dependencies are installed. Kindly build the dependencies yourself if your distribution does not provide them/have outdated versions.

# Project structure
```bash
├── CMakeLists.txt
├── README.md
└── src
    ├── libFakeFeed
    │   ├── CMakeLists.txt
    │   ├── ffpmeg.cpp
    │   ├── ffpmeg.h
    │   ├── test.cpp
    │   ├── test.h
    │   ├── module.cpp
    │   ├── module.h
    │   ├── globalStorage.cpp
    │   ├── globalStorage.h
    │   └── main.cpp
    │
    ├── fakeFeed
    │   ├── ChoicePage.qml
    │   ├── Drawer.qml
    │   ├── VDeviceSettingSheet.qml
    │   └── main.qml
    │
    ├── resources.qrc
    └── CMakeLists.txt

```
