```
█         █    █            ▄▄▄▀▀▀▀▀▀▄▄▄        █▀▀▀▀▀▀▀▀▀▀█ 
█        █     █          ▄▀            ▀▄      █          █ 
█       █      █        ▄▀                ▀▄    █          █ 
█      █       █        █                  █    █          █  █ 
█     █        █       █                    █   █          █      ████   ██████████   █████   
█    █         █       █                    █   █▄▄▄▄▄▄▄▄▄▄█  █  █    █      █             █  
█   █ █        █       █                    █   █      █      █  █           █             █  
█  █   █       █        █                  █    █       █     █    ███       █         █████  
█ █     █      █        ▀▄                ▄▀    █        █    █       █      █       █     █  
██       █     █          ▀▄            ▄▀      █         █   █  █     █     █       █     █  
█         █    █▄▄▄▄▄▄▄▄    ▀▀▀▄▄▄▄▄▄▀▀▀        █          █  █   █████      █        ███████ 
```
![](/docs/images/photo.jpg)

# by Werner

Originally the KLOR Konrad (shoutout @GEIGEIGEIST); KLORista is a 40(+2)-key, column-staggered split-keyboard. 

Featuring encoders, OLED displays. Optionally, haptic feedback and sound.

Deviations from the original design (including an improved key switchplate) is included in this repo.

## Multi Layer Keymap

QWERTY base with navigation-, number-, math-, and symbol layers.\
ft. League of Legends layer (*left-only).

![Layer-0](/docs/images/layout.png)

## RP2040 Sea-Picro with QMK 

Place in the keyboards folder of your qmk installation.

`cp -r klorista ~/qmk_firmware/keyboards`

and run

`qmk compile -kb klorista -km default`

## TODO

- [x] solder & assemble
- [x] program base(Mac/Win), Navigation(l/r), Symbols (l/r), number, LOL- layers
- [x] encoder layers
- [x] OLED keyboard state
- [x] WPM Bongo cat OLED animation
- [ ] Function layer
