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
![Layer-0](/docs/images/case-v2.jpg)

# by Werner

Originally the KLOR Konrad (shoutout @GEIGEIGEIST); KLORista is a 38(+2)-key, column-staggered split-keyboard. 

Features encoders, OLED displays, and haptic feedback.

Software and case deviations from the original design are made in this repo.

## Multi Layer Keymap

QWERTY base with navigation-, number-, and symbol layers.\
ft. League of Legends layer (*left-only).

![Layer-0](/docs/images/layout.png)

## RP2040 Sea-Picro with QMK 

Place in the keyboards folder of your qmk installation.

`cp -r klorista ~/qmk_firmware/keyboards`

and run

`qmk compile -kb klorista -km optimal`

![Layer-0](/docs/images/case_back.jpg)

## TODO

- [x] refactor case desgin
- [x] program base(Mac/Win), navigation(l/r), symbols, number, LOL- layers
	- [ ] swaphands toggle
	- [ ] macros..?
- [x] haptics
- [x] NUM + backspace
- [x] NAVR + esc = del
- [x] encoder layers
- [x] OLED keyboard state
- [x] WPM Bongo cat OLED animation
  - [x] Deprecate animations (+performance)
