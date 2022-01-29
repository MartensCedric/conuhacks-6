# conuhacks-6


- `sudo apt install gdebi-core libsdl2-2.0 libsdl2-dev`
- download .deb package https://github.com/devkitPro/pacman/releases/tag/v1.0.2
- `sudo gdebi devkitpro-pacman.deb`
- add this to your .bashrc: 
```sh
   export DEVKITPRO=/opt/devkitpro
   export DEVKITARM=/opt/devkitpro/devkitARM
   export DEVKITPPC=/opt/devkitpro/devkitPPC
```
- `sudo dkp-pacman -S switch-dev switch-sdl2 switch-sdl2_mixer uam deko3d switch-curl switch-sdl2_image switch-sdl2_ttf switch-opusfile switch-glad switch-glm`
