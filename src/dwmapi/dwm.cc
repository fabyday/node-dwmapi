// hello.cc
#include <node.h>
#include <dwmapi.h>
namespace dwmapi {

using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::String;
using v8::Value;
// DwmSetWindowAttribute(
//     HWND hwnd,
//     DWORD dwAttribute,
//     _In_reads_bytes_(cbAttribute) LPCVOID pvAttribute,
//     DWORD cbAttribute
//     );

enum obj_type{
    bool_type,
    rect_type,
    rendering_policy_type,
    flip_3d_window_policy_type,
    cloaked_type,
    deprecated_type,
    window_corner_preference_type,
    color_ref_type,
    uint_typem,
    system_backdrop_type,
    window_attribute_type,
    error_type
}


typedef struct type_object{
    const char* type;
}tobject;




#define BOOL_TYPE_OBJECT type_object(bool_type)
#define RECT_TYPE_OBJECT type_object(rect_type)
#define RENDERINGPOLICY_TYPE_OBJECT type_object(rendering_policy_type)
#define  FLIP3DWINDOWPOLICY_TYPE_OBJECT type_object(flip_3d_window_policy_type)
#define  CLOAKED_TYPE_OBJECT type_object(cloaked_type)
#define  DEPRECATED_TYPE_OBJECT type_object(deprecated_type)
#define WINDOW_CORNER_PREFERENCE_TYPE_OBJECT type_object(window_corner_preference_type)
#define COLORREF_TYPE_OBJECT type_object(color_ref_type)
#define UINT_TYPE_OBJECT type_object(uint_type)
#define DWM_SYSTEMBACKDROP_TYPE_TYPE_OBJECT type_object(system_backdrop_type)
#define DWMWINDOWATTRIBUTE_TYPE_OBJECT type_object(window_attribute_type)
#define ERROR_TYPE type_object(error_type);

tobject check_param_type(unsigned long type){
switch(type)        {
  case DWMWA_NCRENDERING_POLICY:
    return BOOL_TYPE_OBJECT;
  case DWMWA_TRANSITIONS_FORCEDISABLED:
    return RENDERINGPOLICY_TYPE_OBJECT;
  case DWMWA_NCRENDERING_ENABLED:
    return BOOL_TYPE_OBJECT;
  case DWMWA_ALLOW_NCPAINT:
    return BOOL_TYPE_OBJECT;
  case DWMWA_CAPTION_BUTTON_BOUNDS:
    return RECT_TYPE_OBJECT;
  case DWMWA_NONCLIENT_RTL_LAYOUT:
    return BOOL_TYPE_OBJECT;
  case DWMWA_FORCE_ICONIC_REPRESENTATION:
    return BOOL_TYPE_OBJECT;
  case DWMWA_FLIP3D_POLICY:
    return FLIP3DWINDOWPOLICY_TYPE_OBJECT;
  case DWMWA_EXTENDED_FRAME_BOUNDS:
  return RECT_TYPE_OBJECT;
  case DWMWA_HAS_ICONIC_BITMAP:
  return BOOL_TYPE_OBJECT;
  case DWMWA_DISALLOW_PEEK:
    return BOOL_TYPE_OBJECT;

  case DWMWA_EXCLUDED_FROM_PEEK:
    return BOOL_TYPE_OBJECT;

  case DWMWA_CLOAK:
  return CLOAKED_TYPE_OBJECT;
  case DWMWA_CLOAKED:
  return CLOAKED_TYPE_OBJECT;
  case DWMWA_FREEZE_REPRESENTATION:
  return DEPRECATED_TYPE_OBJECT;
  case DWMWA_PASSIVE_UPDATE_MODE:
      return BOOL_TYPE_OBJECT;

  case DWMWA_USE_HOSTBACKDROPBRUSH:
        return BOOL_TYPE_OBJECT;

  case DWMWA_USE_IMMERSIVE_DARK_MODE:
        return BOOL_TYPE_OBJECT;

  case DWMWA_WINDOW_CORNER_PREFERENCE:
  return WINDOW_CORNER_PREFERENCE_TYPE_OBJECT;
  case DWMWA_BORDER_COLOR:
  return COLORREF_TYPE_OBJECT;
  case DWMWA_CAPTION_COLOR:
  return COLORREF_TYPE_OBJECT;
  case DWMWA_TEXT_COLOR:
  return COLORREF_TYPE_OBJECT;
  case DWMWA_VISIBLE_FRAME_BORDER_THICKNESS:
  return UINT_TYPE_OBJECT;
  case DWMWA_SYSTEMBACKDROP_TYPE:
  return DWM_SYSTEMBACKDROP_TYPE_TYPE_OBJECT;
  case DWMWA_LAST:  
  return DWMWINDOWATTRIBUTE_TYPE_OBJECT;
}
return ERROR_TYPE;
}


void dwm_set_window_attribute(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  
  args.GetReturnValue().Set(String::NewFromUtf8(
      isolate, "world").ToLocalChecked());
}

if(args.Length() == 3){
    isolate->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate,
                            "Wrong number of arguments").ToLocalChecked()));
}

if(!args[0]->IsNumber()){ //hwnd
    isolate->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate,
                            "Wrong arguments").ToLocalChecked()));
    return;
}



if(!args[1]->IsUint32()){ // DWORD
    isolate->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate,
                            "Wrong arguments").ToLocalChecked()));
        return;
        
}
tobject type = check_param_type(args[1]->Int32Value())
{ // bool or params
switch(type.type)
case obj_type:::
if(!args[2]->IsBoolean()){
    isolate->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate,
                            "Wrong arguments").ToLocalChecked()));
}
}


void Initialize(Local<Object> exports) {
  NODE_SET_METHOD(exports, "DwmSetWindowAttribute", dwm_set_window_attribute);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize)

}  // namespace demo 