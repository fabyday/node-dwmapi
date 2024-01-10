// test = require("./build/Release/dwmapi")
const dwmapi = require("./build/Release/dwmapi")

const dwAttribute = {
    DWMWA_NCRENDERING_ENABLED : 1,              // [get] Is non-client rendering enabled/disabled
    DWMWA_NCRENDERING_POLICY : 2,                   // [set] DWMNCRENDERINGPOLICY - Non-client rendering policy
    DWMWA_TRANSITIONS_FORCEDISABLED : 3,            // [set] Potentially enable/forcibly disable transitions
    DWMWA_ALLOW_NCPAINT : 4,                        // [set] Allow contents rendered in the non-client area to be visible on the DWM-drawn frame.
    DWMWA_CAPTION_BUTTON_BOUNDS : 5,                // [get] Bounds of the caption button area in window-relative space.
    DWMWA_NONCLIENT_RTL_LAYOUT : 6,                 // [set] Is non-client content RTL mirrored
    DWMWA_FORCE_ICONIC_REPRESENTATION : 7,          // [set] Force this window to display iconic thumbnails.
    DWMWA_FLIP3D_POLICY : 8,                        // [set] Designates how Flip3D will treat the window.
    DWMWA_EXTENDED_FRAME_BOUNDS : 9,                // [get] Gets the extended frame bounds rectangle in screen space
    DWMWA_HAS_ICONIC_BITMAP : 10,                    // [set] Indicates an available bitmap when there is no better thumbnail representation.
    DWMWA_DISALLOW_PEEK : 11,                        // [set] Don't invoke Peek on the window.
    DWMWA_EXCLUDED_FROM_PEEK : 12,                   // [set] LivePreview exclusion information
    DWMWA_CLOAK : 13,                                // [set] Cloak or uncloak the window
    DWMWA_CLOAKED : 14,                              // [get] Gets the cloaked state of the window
    DWMWA_FREEZE_REPRESENTATION : 15,                // [set] BOOL, Force this window to freeze the thumbnail without live update
    DWMWA_PASSIVE_UPDATE_MODE : 16,                  // [set] BOOL, Updates the window only when desktop composition runs for other reasons
    DWMWA_USE_HOSTBACKDROPBRUSH : 17,                // [set] BOOL, Allows the use of host backdrop brushes for the window.
    DWMWA_USE_IMMERSIVE_DARK_MODE : 20,         // [set] BOOL, Allows a window to either use the accent color, or dark, according to the user Color Mode preferences.
    DWMWA_WINDOW_CORNER_PREFERENCE : 33,        // [set] WINDOW_CORNER_PREFERENCE, Controls the policy that rounds top-level window corners
    DWMWA_BORDER_COLOR : 34,                         // [set] COLORREF, The color of the thin border around a top-level window
    DWMWA_CAPTION_COLOR : 35,                        // [set] COLORREF, The color of the caption
    DWMWA_TEXT_COLOR : 36,                           // [set] COLORREF, The color of the caption text
    DWMWA_VISIBLE_FRAME_BORDER_THICKNESS : 37,       // [get] UINT, width of the visible border around a thick frame window
    DWMWA_SYSTEMBACKDROP_TYPE : 38,                  // [get, set] SYSTEMBACKDROP_TYPE, Controls the system-drawn backdrop material of a window, including behind the non-client area.
    DWMWA_LAST : 40
}
module.exports.dwmapi = {
    "DwmSetWindowAttribute": dwmapi.DwmSetWindowAttribute,
    "dwAttribute" : dwAttribute
}