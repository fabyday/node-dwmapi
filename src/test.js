const  {dwmapi} = require("./index")


console.log(dwmapi.dwAttribute)
console.log(dwmapi.DwmSetWindowAttribute(10, dwmapi.dwAttribute.DWMWA_EXCLUDED_FROM_PEEK ,true))