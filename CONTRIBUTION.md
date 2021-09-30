# How to contribute?

> This application only works on linux based systems. In you are on windows/mac, consider using this application inside a virtual machine
> If on virtualbox, enable webcam inside the vm: https://scribles.net/using-webcam-in-virtualbox-guest-os-on-windows-host/

## Steps to start the application
- Open a command prompt (ctrl+alt+t)
- Clone this repo `git clone https://github.com/deprov447/FakeFeed.git`
- cd into your local copy of the repo `cd FakeFeed`
- Checkout to a new branch `git checkout -b <name-of-new-branch>`
- Install dependencies
    - Ubuntu/Debian based: `sudo apt install build-essential extra-cmake-modules cmake kirigami2-dev gettext ffmpeg v4l2loopback-dkms qtquickcontrols2-5-dev`
    - Arch Linux based: `sudo pacman -Syu base-devel extra-cmake-modules cmake kirigami2 kde-sdk-meta gettext ffmpeg v4l2loopback-dkms`
- Make a build folder and move inside `mkdir build && cd build`
- `cmake ..`
- `make -j$(nproc)`
- `sudo bin/FakeFeed`

## Start contributing
If you are able to start the application, now is the time to start making some contributions. Please look into the [issues](https://github.com/deprov447/FakeFeed/issues) tab to resolve some issues or contribute a feature :)

Feel free to contact me in case of any queries.