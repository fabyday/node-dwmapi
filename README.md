nodejs DWM(Desktop Window Manager) wrapper
=========================================



nodejs DWM wrapper library.



# Install 

```
>>> npm install node-dwmapi

```





# Implemented features


#### DWMAPI
DwmSetWindowAttribute(
    HWND hwnd,
    DWORD dwAttribute,
    _In_reads_bytes_(cbAttribute) LPCVOID pvAttribute,
    DWORD cbAttribute
    );

# Wrapper Usages
### [Wrapper](./wrapper_md.md)



simple test
```js
const {dwmapi} = require("node-dwmapi")

console.log(dwmapi.dwAttribute)
console.log(dwmapi.DwmSetWindowAttribute(10, dwmapi.dwAttribute.DWMWA_EXCLUDED_FROM_PEEK ,true))


// result
>> 
{
  DWMWA_NCRENDERING_ENABLED: 1,
  DWMWA_NCRENDERING_POLICY: 2,
  DWMWA_TRANSITIONS_FORCEDISABLED: 3,
  DWMWA_ALLOW_NCPAINT: 4,
  DWMWA_CAPTION_BUTTON_BOUNDS: 5,
  DWMWA_NONCLIENT_RTL_LAYOUT: 6,
  DWMWA_FORCE_ICONIC_REPRESENTATION: 7,
  DWMWA_FLIP3D_POLICY: 8,
  DWMWA_EXTENDED_FRAME_BOUNDS: 9,
  DWMWA_HAS_ICONIC_BITMAP: 10,
  DWMWA_DISALLOW_PEEK: 11,
  DWMWA_EXCLUDED_FROM_PEEK: 12,
  DWMWA_CLOAK: 13,
  DWMWA_CLOAKED: 14,
  DWMWA_FREEZE_REPRESENTATION: 15,
  DWMWA_PASSIVE_UPDATE_MODE: 16,
  DWMWA_USE_HOSTBACKDROPBRUSH: 17,
  DWMWA_USE_IMMERSIVE_DARK_MODE: 20,
  DWMWA_WINDOW_CORNER_PREFERENCE: 33,
  DWMWA_BORDER_COLOR: 34,
  DWMWA_CAPTION_COLOR: 35,
  DWMWA_TEXT_COLOR: 36,
  DWMWA_VISIBLE_FRAME_BORDER_THICKNESS: 37,
  DWMWA_SYSTEMBACKDROP_TYPE: 38,
  DWMWA_LAST: 40
}
true
```
