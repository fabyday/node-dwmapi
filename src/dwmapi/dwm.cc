// hello.cc
#include <dwmapi.h>
#include <node.h>

namespace dwmapi {
using v8::Boolean;
using v8::Exception;
using v8::FunctionCallbackInfo;
using v8::Int32;
using v8::Isolate;
using v8::Local;
using v8::Number;
using v8::Object;
using v8::String;
using v8::Uint32;
using v8::Value;

enum obj_type {
  bool_type,
  rect_type,
  rendering_policy_type,
  flip_3d_window_policy_type,
  cloaked_type,
  deprecated_type,
  window_corner_preference_type,
  color_ref_type,
  uint_type,
  system_backdrop_type,
  window_attribute_type,
  error_type
};

typedef struct type_object {
  enum obj_type type;
} tobject;

#define OBJECT_CHECKER(isolate, args, err_msg)                                 \
  if (!((args)[2]->IsObject())) {                                              \
    isolate->ThrowException(Exception::TypeError(                              \
        String::NewFromUtf8(isolate, (err_msg)).ToLocalChecked()));            \
    args.GetReturnValue().Set(false);                                          \
    return;                                                                    \
  }

#define BOOL_TYPE_OBJECT                                                       \
  { bool_type }
#define RECT_TYPE_OBJECT                                                       \
  { rect_type }
#define RENDERINGPOLICY_TYPE_OBJECT                                            \
  { rendering_policy_type }
#define FLIP3DWINDOWPOLICY_TYPE_OBJECT                                         \
  { flip_3d_window_policy_type }
#define CLOAKED_TYPE_OBJECT                                                    \
  { cloaked_type }
#define DEPRECATED_TYPE_OBJECT                                                 \
  { deprecated_type }
#define WINDOW_CORNER_PREFERENCE_TYPE_OBJECT                                   \
  { window_corner_preference_type }
#define COLORREF_TYPE_OBJECT                                                   \
  { color_ref_type }
#define UINT_TYPE_OBJECT                                                       \
  { uint_type }
#define DWM_SYSTEMBACKDROP_TYPE_TYPE_OBJECT                                    \
  { system_backdrop_type }
#define DWMWINDOWATTRIBUTE_TYPE_OBJECT                                         \
  { window_attribute_type }
#define ERROR_TYPE                                                             \
  { error_type }

tobject check_param_type(unsigned int type) {
  switch (type) {
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

  if (args.Length() != 3) {
    isolate->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate, "Wrong number of arguments")
            .ToLocalChecked()));
    return;
  }
  HWND hwnd = reinterpret_cast<HWND>(args[0].As<Int32>()->Value());
  if (!args[0]->IsNumber()) {  // hwnd
    isolate->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate, "first argument must be the number.")
            .ToLocalChecked()));
    return;
  }

  if (!args[1]->IsUint32()) {  // DWORD
    isolate->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate, "second args must Unsinged int ")
            .ToLocalChecked()));
    return;
  }

  tobject type = check_param_type(args[1].As<Uint32>()->Value());

  // bool or params
  switch (type.type) {
    case bool_type: {
      auto t = args[2]->IsBoolean();
      if (!args[2]->IsBoolean()) {
        isolate->ThrowException(Exception::TypeError(
            String::NewFromUtf8(isolate,
                                "Wrong arguments. 3rd arg must be bool type ")
                .ToLocalChecked()));
        args.GetReturnValue().Set(false);
        return;
      }
      BOOL val = args[2].As<Boolean>()->Value();
      DwmSetWindowAttribute(hwnd, type.type, &val, sizeof(BOOL));
      break;
    }
    case rect_type: {
      if (!args[2]->IsObject()) {
        isolate->ThrowException(Exception::TypeError(
            String::NewFromUtf8(isolate, "rect_type : Wrong arguments")
                .ToLocalChecked()));
      } else {
        RECT val;
        DwmSetWindowAttribute(hwnd, type.type, &val, sizeof(RECT));
      }
      break;
    }
    case rendering_policy_type: {
      OBJECT_CHECKER(isolate, args, "rendering_policy_type : Wrong argument");
      int val;
      DwmSetWindowAttribute(hwnd, type.type, &val, sizeof(RECT));
      break;
    }
    case flip_3d_window_policy_type: {
      OBJECT_CHECKER(
          isolate, args, "flip_3d_window_policy_type :Wrong argument");
      int val;
      DwmSetWindowAttribute(hwnd, type.type, &val, sizeof(RECT));
      break;
    }
    case cloaked_type: {
      OBJECT_CHECKER(isolate, args, "cloaked_type : Wrong argument");
      int val;
      DwmSetWindowAttribute(hwnd, type.type, &val, sizeof(10));
      break;
    }
    case window_corner_preference_type: {
      OBJECT_CHECKER(
          isolate, args, "window_corner_preference_type : Wrong argument");
      int val;
      DwmSetWindowAttribute(hwnd, type.type, &val, sizeof(10));
      break;
    }
    case color_ref_type: {
      OBJECT_CHECKER(isolate, args, ":color_ref_type Wrong argument");
      int val;
      DwmSetWindowAttribute(hwnd, type.type, &val, sizeof(10));
      break;
    }
    case uint_type: {
      OBJECT_CHECKER(isolate, args, "uint_type : Wrong argument");
      int val;
      DwmSetWindowAttribute(hwnd, type.type, &val, sizeof(10));
      break;
    }
    case system_backdrop_type: {
      OBJECT_CHECKER(isolate, args, "system_backdrop_type : Wrong argument");
      int val;
      DwmSetWindowAttribute(hwnd, type.type, &val, sizeof(10));
      break;
    }
    case window_attribute_type: {
      OBJECT_CHECKER(isolate, args, "window_attribute_type : Wrong argument");
      int val;
      DwmSetWindowAttribute(hwnd, type.type, &val, sizeof(10));
      break;
    }
    case deprecated_type:
    case error_type:
    default: {
      isolate->ThrowException(Exception::TypeError(
          String::NewFromUtf8(isolate, "Error : not supported args")
              .ToLocalChecked()));
      args.GetReturnValue().Set(false);
      return;
    }
  }

  args.GetReturnValue().Set(true);
  return;
}

void Initialize(Local<Object> exports) {
  NODE_SET_METHOD(exports, "DwmSetWindowAttribute", dwm_set_window_attribute);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize)

}  // namespace dwmapi